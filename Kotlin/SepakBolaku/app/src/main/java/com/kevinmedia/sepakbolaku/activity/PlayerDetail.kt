package com.kevinmedia.sepakbolaku.activity

import android.content.Intent
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.provider.MediaStore
import android.view.Menu
import android.view.MenuItem
import android.widget.ImageView
import android.widget.TextView
import com.kevinmedia.sepakbolaku.data.Player
import com.kevinmedia.sepakbolaku.R
import java.io.ByteArrayOutputStream

class PlayerDetail : AppCompatActivity() {
    private lateinit var tvPlayerName: TextView
    private lateinit var tvPlayerDescription: TextView
    private lateinit var tvPlayerClub: TextView
    private lateinit var tvPlayerRate: TextView
    private lateinit var tvPlayerPositionalPlayer: TextView
    private lateinit var tvActivePlayer: TextView
    private lateinit var tvPlayerTotalGoalandAssist: TextView
    private lateinit var dataPlayerIntent: String
    private lateinit var dataImageIntent: String

    private lateinit var ivPlayerPhoto: ImageView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_player_detail)

        // Mendapatkan data Player dari extra pada Intent
        val player = intent.getParcelableExtra<Player>(EXTRA_PLAYER)

        // mengambil id view
        tvPlayerName = findViewById(R.id.player_name_detail)
        tvPlayerClub = findViewById(R.id.player_club_detail)
        tvPlayerDescription = findViewById(R.id.player_description_detail)
        tvPlayerRate = findViewById(R.id.rating_player)
        tvPlayerPositionalPlayer = findViewById(R.id.positional_player_detail)
        tvActivePlayer = findViewById(R.id.active_player_description)
        tvPlayerTotalGoalandAssist = findViewById(R.id.player_goalandassist_description)
        ivPlayerPhoto = findViewById(R.id.player_image)

        // Menampilkan data Player di view yang sudah diambil id-nya tadi
        tvPlayerName.text = player?.name
        tvPlayerDescription.text = player?.description
        tvPlayerClub.text = player?.club
        tvPlayerRate.text = player?.rate
        tvPlayerPositionalPlayer.text = player?.positionPlayer
        tvActivePlayer.text = player?.activePlayer
        tvPlayerTotalGoalandAssist.text = player?.TotalGoal + "/" + player?.TotalAssist
        ivPlayerPhoto.setImageResource(player?.photo!!)

        dataPlayerIntent =  "Player Name : " + player?.name +
                            "\n\nPlayer Club : " + player?.club +
                            "\n\nPlayer Rate : " + player?.rate +
                            "\n\nPositional Player : " + player?.positionPlayer +
                            "\n\nActive Player : " + player?.activePlayer +
                            "\n\nTotal Goal and Assist : " + player?.TotalGoal + "/" + player?.TotalAssist +
                            "\n\nPlayer Description : " + player?.description

        dataImageIntent = player?.photo.toString()
        supportActionBar?.setDisplayHomeAsUpEnabled(true)
    }

    companion object {
        const val EXTRA_PLAYER = "extra_player"
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            android.R.id.home -> {
                finish()
                true
            }
            R.id.action_share -> {
                val image = BitmapFactory.decodeResource(resources, dataImageIntent.toInt())
                val shareIntent = Intent(Intent.ACTION_SEND)
                shareIntent.type = "image/*"
                shareIntent.putExtra(Intent.EXTRA_TEXT, dataPlayerIntent)
                shareIntent.putExtra(Intent.EXTRA_STREAM, getUriFromBitmap(image))

                startActivity(Intent.createChooser(shareIntent, "Bagikan dengan"))
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    // fungsi untuk mengembalikan URI dari bitmap
    private fun getUriFromBitmap(bitmap: Bitmap): Uri? {
        val bytes = ByteArrayOutputStream()
        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, bytes)
        val path = MediaStore.Images.Media.insertImage(contentResolver, bitmap, "Title", null)
        return Uri.parse(path)
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_playerdetail, menu)
        return true
    }

}