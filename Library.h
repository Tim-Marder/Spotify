#ifndef _LIBRARY_
#define _LIBRARY_

#include <stdlib.h>
#include <array>
using namespace std;
#include "Playlist.h"
#include "Song.h"

class Library {
   public:
       Library();
       void selectPlaylist(string playlist);
       void selectLibrary();
       void addSong();
       void addSongToPlaylist(string song);
       void addPlaylist(string playlist);
       void removeSong(string song);
       Song *replaceSong(Song* songs, Song song, int index, int last);
       void removeSelectedPlaylist();
       void removeSpecifiedPlaylist(string playlist);
       Playlist *replacePlaylist(Playlist* playlists, Playlist playlist, int index, int last);
       void showSelectedPlaylist();
       void showSpecifiedPlaylist(string playlist);
       void showPlaylists();
       void showSongs();
       void showSong(string song);
       void clonePlaylist(string newPlaylist);
       void importPlaylist(string playlist);
       void growPlaylists();
       void growSongs();
       int libCalculateTotalSeconds();
       string libCalculateNewTotalDuration(int totalSeconds);
       bool isDuplicateSong(Song song);
   private:
       Playlist *playlists; //array
       int lastPlaylist;
       int playlistCapacity;
       Song *libSongs; //array
       int libLastSong;
       int libSongCapacity;
       int selectedPlaylist;
};

#endif
