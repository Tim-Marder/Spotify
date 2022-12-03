#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Playlist.h"

Playlist::Playlist() {
    totalDuration = 0;
    lastSong = 0;
    songCapacity = 50;
    songs = new Song[songCapacity];
}

Playlist::Playlist(const Playlist & other) {
    this->totalDuration = other.totalDuration;
    this->lastSong = other.lastSong;
    this->songCapacity = other.songCapacity;
    this->songs = other.songs;
    this->timeAdded = to_string(tm.getHours()) + ":" + to_string(tm.getMins()) + ":" + to_string(tm.getSecs());
    this->dateAdded = to_string(tm.getMonth()) + "/" + to_string(tm.getDay()) + "/" + to_string(tm.getYear());
}

Playlist &Playlist::operator+(const Playlist &other) {
    for (int i = 0; i < other.lastSong; i++) {
        this->addSongHere(other.songs[i]);
    }
    return *this;
}

bool operator==(const Playlist & playlist1, const Playlist & playlist2) {
    return playlist1.name == playlist2.name;
}

void Playlist::setName(string newName) {
    name = newName;
}

void Playlist::createPlaylist(string playlist) {
    name = playlist;
    timeAdded = to_string(tm.getHours()) + ":" + to_string(tm.getMins()) + ":" + to_string(tm.getSecs());
    dateAdded = to_string(tm.getMonth()) + "/" + to_string(tm.getDay()) + "/" + to_string(tm.getYear());
    totalDuration = 0;
    lastSong = 0;
    songCapacity = 50;
    songs = new Song[songCapacity];
}

string Playlist::getName() {
    return name;
}

string Playlist::getTimeAdded() {
    return timeAdded;
}

string Playlist::getDateAdded() {
    return dateAdded;
}

bool Playlist::isDuplicate(Song song) {
    for (int i = 0; i < lastSong; i++) {
        if (songs[i] == song) {
            return true;
        }
    }
    return false;
}

void Playlist::addSongHere(Song song) {
    if (lastSong == songCapacity) {
        grow();
    }
    if (!isDuplicate(song)) {
        songs[lastSong] = song;
        lastSong++;
        cout << "success: Added song: [" << song.getTimeAdded() << " " << song.getDateAdded() << "] '" << song.getTitle() << "' by " << song.getArtist() << " [" << song.getNewDuration() /*change*/ << "] (" << song.getExplicity() << ")" << endl;
    }
    else {
        cout << "error: Duplicate song exists in playlist" << endl;
    }
}

void Playlist::grow() {
	int new_capacity = songCapacity * 2;
	Song *new_songs = new Song[new_capacity];
	for (int i = 0; i < lastSong; i++) {
		new_songs[i] = songs[i];
	}
	songCapacity = new_capacity;
	delete [] songs;
	songs = new_songs;
}

Song * Playlist::replaceSongHere(Song* songs, Song song, int index, int last) {
    Song *tempSongs = new Song[songCapacity];
    for (int i = 0; i < index; i++) {
        tempSongs[i] = songs[i];
    }
    for (int i = index + 1; i < last; i++) {
        tempSongs[i] = songs[i];
    }
    songs = tempSongs;
    return songs;
}

void Playlist::removeSongHere(string song) {
    for (int i = 0; i < lastSong; i++) {
        if (songs[i].getTitle() == song) {
            songs = replaceSongHere(songs, songs[i], i, lastSong);
            lastSong--;
            cout << "success: Song " << song << " has been removed from playlist " << this->name << endl;
            return;
        }
    }
    cout << "error: No song named " << song << " was found in playlist " << this->name << endl;
}

int Playlist::calculateTotalSeconds() {
    int totalSeconds = 0;
    for (int i = 0; i < lastSong; i++) {
        totalSeconds = totalSeconds + songs[i].getSeconds();
    }
    return totalSeconds;
}

string Playlist::calculateNewTotalDuration(int totalSeconds) {
    int secondsLeft = totalSeconds;
    int min = 0;
    int sec = 0;
    while (secondsLeft >= 60) {
        min++;
        secondsLeft -= 60;
    }
    sec += secondsLeft;
    return to_string(min) + "m " + to_string(sec) + "s";
}

void Playlist::showSongsHere() {
    cout << "Playlist: " << this->name << endl;
    cout << "Created: " << timeAdded << " " << dateAdded << endl; // TODO
    cout << "Length: " << calculateNewTotalDuration(calculateTotalSeconds()) << endl; // TODO
    cout << "Songs: " << lastSong << endl;
    for (int i = 0; i < lastSong; i++) {
        cout << songs[i];
    }
}

void Playlist::showSongHere(string song) {
    for (int i = 0; i < lastSong; i++) {
        if (songs[i].getTitle() == song) {
            cout << songs[i];
            return;
        }
    }
    cout << "error: Could not find song " << song << " in playlist " << this->name << endl;
}
