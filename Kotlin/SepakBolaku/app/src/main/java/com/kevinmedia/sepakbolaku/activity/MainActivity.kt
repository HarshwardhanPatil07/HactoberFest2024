package com.kevinmedia.sepakbolaku.activity

import android.content.Intent
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.kevinmedia.sepakbolaku.adapter.ListPlayerAdapter
import com.kevinmedia.sepakbolaku.data.Player
import com.kevinmedia.sepakbolaku.activity.PlayerDetail.Companion.EXTRA_PLAYER
import com.kevinmedia.sepakbolaku.R
import com.kevinmedia.sepakbolaku.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    private lateinit var listFootballPlayer: RecyclerView
    private val list = ArrayList<Player>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        listFootballPlayer = binding.footballerList
        listFootballPlayer.setHasFixedSize(true)

        list.addAll(getListPlayer())
        showRecyclerList()
    }

    // buat nampilin tombol profile
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_main, menu)
        return true
    }

    // tombol action more - buat ngarahin ke hal profile ketika tombol profile diklik
    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_more -> {
                val intent = Intent(this, Author::class.java)
                startActivity(intent)
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    // tombol buat ngarahin ke playerdetail sambil membawa data berupa array player
    private fun showSelectedHero(player: Player) {
        // Membuat objek Intent untuk membuka PlayerDetail
        val intent = Intent(this, PlayerDetail::class.java)

        // Menambahkan data Player sebagai extra pada Intent
        intent.putExtra(EXTRA_PLAYER, player)

        startActivity(intent)
    }

    // get data dari string.xml lalu memasukan data tsb ke array player
    private fun getListPlayer(): ArrayList<Player> {
        val dataName = resources.getStringArray(R.array.data_name)
        val dataDescription = resources.getStringArray(R.array.data_description)
        val dataClub = resources.getStringArray(R.array.data_club)
        val dataRate = resources.getStringArray(R.array.data_rate)
        val dataPositional = resources.getStringArray(R.array.data_position)
        val dataGoal = resources.getStringArray(R.array.allgoaluntilnow)
        val dataAssist = resources.getStringArray(R.array.allassistuntilnow)
        val dataActive = resources.getStringArray(R.array.activeplayer)

        val dataPhoto = resources.obtainTypedArray(R.array.data_photo)
        val listPlayer = ArrayList<Player>()
        // urutannya gaboleh salah, harus sesuai urutan di data class player
        for (i in dataName.indices) {
            val player = Player(dataName[i], dataDescription[i], dataPhoto.getResourceId(i, -1), dataClub[i], dataRate[i], dataPositional[i], dataActive[i], dataGoal[i], dataAssist[i])
            listPlayer.add(player)
        }
        return listPlayer
    }

    private fun showRecyclerList() {
        listFootballPlayer.layoutManager = LinearLayoutManager(this)
        val listPlayerAdapter = ListPlayerAdapter(list)
        listFootballPlayer.adapter = listPlayerAdapter

        listPlayerAdapter.setOnItemClickCallback(object : ListPlayerAdapter.OnItemClickCallback {
            override fun onItemClicked(data: Player) {
                showSelectedHero(data)
            }
        })
    }
}