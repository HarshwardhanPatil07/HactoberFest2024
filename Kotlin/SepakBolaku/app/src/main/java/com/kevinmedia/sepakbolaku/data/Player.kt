package com.kevinmedia.sepakbolaku.data

import android.os.Parcelable
import kotlinx.parcelize.Parcelize

@Parcelize
data class Player(
    val name: String,
    val description: String,
    val photo: Int,
    val club: String,
    val rate: String,
    val positionPlayer: String,
    val activePlayer: String,
    val TotalGoal: String,
    val TotalAssist: String,
): Parcelable
