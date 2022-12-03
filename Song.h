#ifndef _SONG_
#define _SONG_

#include <stdlib.h>
using namespace std;
#include "Timestamp.h"

class Song {
   public:
       Song();
       friend bool operator==(const Song & song1, const Song & song2); // friend?
       friend ostream & operator<<(ostream & out, const Song & song);
       void displaySong();
       void createSong();
       bool checkDuration(string duration);
       int calculateSeconds(string duration);
       string calculateNewDuration(int seconds);
       string getTitle();
       string getArtist();
       string getExplicity();
       string getTimeAdded();
       string getDateAdded();
       int getSeconds();
       string getNewDuration();
   private:
       string title;
       string artist;
       string duration;
       int seconds;
       string newDuration;
       string explicity;
       string curses;
       string dateAdded;
       string timeAdded;
       Timestamp tm;
};

#endif
