#ifndef _PLAYLIST_
#define _PLAYLIST_

#include <stdlib.h>
#include <array>
using namespace std;
#include "Song.h"

class Playlist {
   public:
       Playlist();
       Playlist(const Playlist & other);
       Playlist &operator+(const Playlist &other); // or +=
       friend bool operator==(const Playlist & playlist1, const Playlist & playlist2);
       void addSongHere(Song song); //adds song to playlist
       void createPlaylist(string playlist); //gives information to playlist instance
       Song *replaceSongHere(Song* songs, Song song, int index, int last);
       void removeSongHere(string song); //removes song from playlist
       void showSongsHere(); //shows songs in playlist -> display songs in song.cpp?
       void showSongHere(string song);
       void ExpandSongCapacity();
       string getName();
       void setName(string name);
       string getTimeAdded();
       string getDateAdded();
       void grow();
       int calculateTotalSeconds();
       string calculateNewTotalDuration(int totalSeconds);
       bool isDuplicate(Song song);
   private:
       string name;
       string dateAdded; //not string; maybe not separte
       string timeAdded; //not string; maybe not separte
       int totalDuration; //not int maybe; figure out
       Song *songs;
       int lastSong;
       int songCapacity;
       Timestamp tm;
};

#endif
