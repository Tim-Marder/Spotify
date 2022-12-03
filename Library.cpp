#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Library.h"

Library::Library() {
    //playlists[10];
    //Song libSongs[50];

    lastPlaylist = 0;
    playlistCapacity = 10;
    playlists = new Playlist[playlistCapacity];

    libLastSong = 0;
    libSongCapacity = 50;
    libSongs = new Song[libSongCapacity];

    selectedPlaylist = -1;
}

bool Library::isDuplicateSong(Song song) {
    for (int i = 0; i < libLastSong; i++) {
        if (libSongs[i] == song) {
            return true;
        }
    }
    return false;
}

void Library::selectPlaylist(string playlist) {
    for (int i = 0; i < lastPlaylist; i++) {
        if (playlists[i].getName() == playlist) {
            selectedPlaylist = i; // selecting the index of the playlist
            cout << "success: Selected playlist " << playlist << endl;
            return;
        }
    }
    cout << "error: Cannot find playlist " << playlist << " - not selected." << endl;
}

void Library::selectLibrary() {
    selectedPlaylist = -1;
    cout << "success: Selected library." << endl;
}

void Library::addSong() {
    if (libLastSong == libSongCapacity) {
        growSongs();
    }
    Song newSong;
    newSong.createSong();
    if (!isDuplicateSong(newSong)) {
        libSongs[libLastSong] = newSong;
        libLastSong++;
        cout << "success: Added song: [" << newSong.getTimeAdded() << " " << newSong.getDateAdded() << "] '" << newSong.getTitle() << "' by " << newSong.getArtist() << " [" << newSong.getNewDuration() /*change*/ << "] (" << newSong.getExplicity() << ")" << endl;
    }
    else {
        cout << "error: Duplicate song exists in the library" << endl;
    }
}

void Library::growSongs() {
	int new_capacity = libSongCapacity * 2;
	Song *new_songs = new Song[new_capacity];
	for (int i = 0; i < libLastSong; i++) {
		new_songs[i] = libSongs[i];
	}
	libSongCapacity = new_capacity;
	delete [] libSongs;
	libSongs = new_songs;
}

void Library::growPlaylists() {
	int new_capacity = playlistCapacity * 2;
	Playlist *new_playlists = new Playlist[new_capacity];
	for (int i = 0; i < lastPlaylist; i++) {
		new_playlists[i] = playlists[i];
	}
	playlistCapacity = new_capacity;
	delete [] playlists;
	playlists = new_playlists;
}

void Library::addSongToPlaylist(string song) {
    if (selectedPlaylist == -1) {
        cout << "error: No playlist selected." << endl;
        cout << "error: Select a playlist to add a song, by title, to the playlist" << endl;
        cout << "error: To add a song directly to the library, use 'add song'" << endl;
    }
    else {
        for (int i = 0; i < libLastSong; i++) {
            if (libSongs[i].getTitle() == song) {
                playlists[selectedPlaylist].addSongHere(libSongs[i]);
                return;
            }
        }
        cout << "Song " << song << " not found in libary" << endl;
    }
}

void Library::addPlaylist(string playlist) {
    if (lastPlaylist == playlistCapacity) {
        growPlaylists();
    }
    Playlist newPlaylist;
    newPlaylist.createPlaylist(playlist);
    for (int i = 0; i < lastPlaylist; i++) {
        if (playlists[i] == newPlaylist) {
            cout << "error: Duplicate playlist exists in the library" << endl;
            return;
        }
    }
    playlists[lastPlaylist] = newPlaylist;
    lastPlaylist++;
    selectPlaylist(playlist);
    cout << "success: A new playlist called " << playlist << " added to the library" << endl;
}

Song * Library::replaceSong(Song* songs, Song song, int index, int last) {
    Song* tempSongs = new Song[libSongCapacity];
    for (int i = 0; i < index; i++) {
        tempSongs[i] = songs[i];
    }
    for (int i = index + 1; i < last; i++) {
        tempSongs[i] = songs[i];
    }
    songs = tempSongs;
    return songs;
}

void Library::removeSong(string song) {
    if (selectedPlaylist == -1) {
        for (int i = 0; i < libLastSong; i++) {
            if (libSongs[i].getTitle() == song) {
                libSongs = replaceSong(libSongs, libSongs[i], i, libLastSong);
                libLastSong--;
                cout << "success: Song " << song << " has been removed from library" << endl;
                return;
            }
        }
        cout << "error: No song named " << song << " was found in the library" << endl;
    }
    else {
        playlists[selectedPlaylist].removeSongHere(song);
    }
}

Playlist * Library::replacePlaylist(Playlist* playlists, Playlist playlist, int index, int last) {
    Playlist* tempPlaylists = new Playlist[playlistCapacity];
    for (int i = 0; i < index; i++) {
        tempPlaylists[i] = playlists[i];
    }
    for (int i = index + 1; i < last; i++) {
        tempPlaylists[i] = playlists[i];
    }
    playlists = tempPlaylists;
    return playlists;
}

void Library::removeSelectedPlaylist() {
    if (selectedPlaylist == -1) {
        cout << "error: No playlist specified or selected - no effect" << endl;
        return;
    }
    else {
        playlists = replacePlaylist(playlists, playlists[selectedPlaylist], selectedPlaylist, lastPlaylist);
        lastPlaylist--;
        selectedPlaylist = -1;
        cout << "success: Removed playlist from library" << endl;
        return;
    }
}

void Library::removeSpecifiedPlaylist(string playlist) {
    for (int i = 0; i < lastPlaylist; i++) {
        if (playlists[i].getName() == playlist) {
            playlists = replacePlaylist(playlists, playlists[i], i, lastPlaylist);
            lastPlaylist--;
            cout << "success: Removed playlist " << playlist << " from the library" << endl;
            return;
        }
    }
    cout << "error: No playlist named " << playlist << " was found in the library" << endl;
}

void Library::showSelectedPlaylist() {
    if (selectedPlaylist == -1) {
        cout << "error: No playlist is currently selected" << endl;
        return;
    }
    else {
        playlists[selectedPlaylist].showSongsHere();
    }
}

void Library::showSpecifiedPlaylist(string playlist) {
    for (int i = 0; i < lastPlaylist; i++) {
        if (playlists[i].getName() == playlist) {
            playlists[i].showSongsHere();
            return;
        }
    }
    cout << "error: No playlist named " << playlist << " exists in the library" << endl;
}

void Library::showPlaylists() {
    if (lastPlaylist == 0) {
        cout << "error: No playlists in the library to show" << endl;
        return;
    }
    for (int i = 0; i < lastPlaylist; i++) {
        cout << playlists[i].getName() << " (Created: " << playlists[i].getTimeAdded() << " " << playlists[i].getDateAdded() << ")" << endl;
    }
}

int Library::libCalculateTotalSeconds() {
    int totalSeconds = 0;
    for (int i = 0; i < libLastSong; i++) {
        totalSeconds = totalSeconds + libSongs[i].getSeconds();
    }
    return totalSeconds;
}

string Library::libCalculateNewTotalDuration(int totalSeconds) {
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

void Library::showSongs() {
    cout << "Songs: " << libLastSong << " (" << libCalculateNewTotalDuration(libCalculateTotalSeconds()) << ")" << endl;
    for (int i = 0; i < libLastSong; i++) {
        cout << libSongs[i];
    }
}

void Library::showSong(string song) {
    if (selectedPlaylist == -1) {
        for (int i = 0; i < libLastSong; i++) {
            if (libSongs[i].getTitle() == song) {
                cout << libSongs[i];
                return;
            }
        }
        cout << "error: Could not find song title " << song << " in library" << endl;
    }
    else {
        playlists[selectedPlaylist].showSongHere(song);
        return;
    }
}

void Library::clonePlaylist(string newPlaylist) {
    Playlist playlist2;
    if (selectedPlaylist == -1) {
        cout << "error: No playlist selected" << endl;
        return;
    }
    else {
        playlist2 = Playlist(playlists[selectedPlaylist]);
        playlist2.setName(newPlaylist);
        for (int i = 0; i < lastPlaylist; i++) {
            if (playlists[i] == playlist2) {
                cout << "error: Duplicate playlist exists in the library" << endl;
                return;
            }
        }
        playlists[lastPlaylist] = playlist2;
        lastPlaylist++;
        cout << "success: Cloned playlist " << playlists[selectedPlaylist].getName() << " into playlist " << playlist2.getName() << endl;
        return;
    }
}

void Library::importPlaylist(string playlist) {
    if (selectedPlaylist == -1) {
        cout << "error: No playlist selected." << endl;
        return;
    }
    else {
        Playlist specifiedPlaylist;
        for (int i = 0; i < lastPlaylist; i++) {
            if (playlists[i].getName() == playlist) {
                specifiedPlaylist = playlists[i];
                break;
            }
        }
        playlists[selectedPlaylist] = playlists[selectedPlaylist] + specifiedPlaylist;
        return;
    }
    cout << "error: Did not succeed in importing playlist" << endl;
}
