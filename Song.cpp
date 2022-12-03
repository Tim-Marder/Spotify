#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Song.h"

Song::Song() {}

bool operator==(const Song & song1, const Song & song2) {
    return song1.title == song2.title;
}

ostream & operator<<(ostream & out, const Song & song) {
    out << "[" << song.timeAdded << " " << song.dateAdded << "] '" << song.title << "' by " << song.artist << " [" << song.duration /*change*/ << "] (" << song.explicity << ")" << endl;
    return out;
}

void Song::createSong() {
    cout << "song title: ";
    cin >> title;
    cout << "song artist: ";
    cin >> artist;
    cout << "Duration [MM:SS]: ";
    cin >> duration;
    bool badDuration = checkDuration(duration);
    if (badDuration) cout << "Illegal time duration value: " << duration << endl;
    cout << "explicit? (y/n): ";
    cin >> curses;
    string hours = "";
    string mins = "";
    string secs = "";

    if (tm.getHours() < 10) hours = "0" + to_string(tm.getHours());
    else hours = to_string(tm.getHours());
    if (tm.getMins() < 10) mins = "0" + to_string(tm.getMins());
    else mins = to_string(tm.getMins());
    if (tm.getSecs() < 10) secs = "0" + to_string(tm.getSecs());
    else secs = to_string(tm.getSecs());

    timeAdded = hours + ":" + mins + ":" + secs;
    dateAdded = to_string(tm.getMonth()) + "/" + to_string(tm.getDay()) + "/" + to_string(tm.getYear());

    explicity = "";
    if (curses == "y") explicity = "Explicit";
    else if (curses == "n") explicity = "Clean";
    else explicity = "unknown";

    if (badDuration) {
        newDuration = "00m 00s";
    }
    else {
        seconds = calculateSeconds(duration);
        newDuration = calculateNewDuration(seconds);
    }
}

bool Song::checkDuration(string duration) {
    bool retVal = true;
    if (duration.length() == 5) {
        if (stoi(duration.substr(0,2)) >= 0 && stoi(duration.substr(0,2)) <= 23 && stoi(duration.substr(3, 2)) >= 0 && stoi(duration.substr(3,2)) <= 59) {
            if (duration.substr(2,1) == ":") {
                retVal = false;
            }
        }
    }
    return retVal;
}

int Song::calculateSeconds(string duration) {
    return (stoi(duration.substr(0,2)) * 60) + stoi(duration.substr(3,2));
}

string Song::calculateNewDuration(int seconds) {
    int secondsLeft = seconds;
    int min = 0;
    int sec = 0;
    while (secondsLeft >= 60) {
        min++;
        secondsLeft -= 60;
    }
    sec += secondsLeft;
    return to_string(min) + "m " + to_string(sec) + "s";
}

string Song::getNewDuration() {
    return newDuration;
}

int Song::getSeconds() {
    return seconds;
}

void Song::displaySong() {
    explicity = "";
    if (curses == "y") explicity = "Explicit";
    else if (curses == "n") explicity = "Clean";
    else explicity = "unknown";
    cout << "[" << timeAdded << " " << dateAdded << "] '" << title << "' by " << artist << " [" << newDuration /*change*/ << "] (" << explicity << ")" << endl;
}

string Song::getTitle() { //debugging
    return title;
}

string Song::getArtist() {
    return artist;
}

string Song::getExplicity() {
    return explicity;
}

string Song::getTimeAdded() {
    return timeAdded;
}

string Song::getDateAdded() {
    return dateAdded;
}
