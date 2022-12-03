#include <iostream>
#include <stdlib.h>
#include "Library.h"
#include "Parser.h"

using namespace std;

int main(int argc, char *argv[])
{
   Library library;
   string input = "";

   while (true) {
       cout << "['add' 'remove' 'select' 'show' 'clone' 'import' 'exit']" << endl;
       //cin >> input;
       getline(cin, input);
       Parser command(input);
       if (command.getOperation() == "add") {
           if (command.getArg1() == "song") {
               if (command.getArg2() == "") {
                   library.addSong();
               }
               else {
                   library.addSongToPlaylist(command.getArg2());
               }
           }
           else if (command.getArg1() == "playlist") {
               if (command.getArg2() == "") {
                   cout << "Please specify playlist name: ";
                   string tempPlaylist = "";
                   cin >> tempPlaylist;
                   library.addPlaylist(tempPlaylist);
               }
               else {
                   library.addPlaylist(command.getArg2());
               }
           }
           else {
               cout << "error: Improper use of add. Use one of:" << endl;
               cout << "error:    add song" << endl;
               cout << "error:    add song <title>" << endl;
               cout << "error:    add playlist <playlist name>" << endl;
           }
       }
       else if (command.getOperation() == "remove") {
           if (command.getArg1() == "song") {
               if (command.getArg2() == "") {
                   cout << "error: Must specify a song title - nothing removed" << endl;
               }
               else {
                   library.removeSong(command.getArg2());
               }
           }
           else if (command.getArg1() == "playlist") {
               if (command.getArg2() == "") {
                   library.removeSelectedPlaylist();
               }
               else {
                   library.removeSpecifiedPlaylist(command.getArg2());
               }
           }
           else {
               cout << "error: Improper use of remove. Use:" << endl;
               cout << "error:    remove song <title>" << endl;
               cout << "error:    remove playlist [<playlist name>]" << endl;
           }
       }
       else if (command.getOperation() == "select") {
           if (command.getArg1() == "library") {
               if (command.getArg2() != "") {
                   cout << "Improper use of select. Use one of:" << endl;
                   cout << "error:    select library" << endl;
                   cout << "error:    select playlist <playlist name>" << endl;
               }
               else {
                   library.selectLibrary();
               }
           }
           else if (command.getArg1() == "playlist") {
               if (command.getArg2() == "") {
                   cout << "Improper use of select. Use one of:" << endl;
                   cout << "error:    select library" << endl;
                   cout << "error:    select playlist <playlist name>" << endl;
               }
               else {
                   library.selectPlaylist(command.getArg2());
               }
           }
           else {
               cout << "Improper use of select. Use one of:" << endl;
               cout << "error:    select library" << endl;
               cout << "error:    select playlist <playlist name>" << endl;
           }
       }
       else if (command.getOperation() == "show") {
           if (command.getArg1() == "playlist") {
               if (command.getArg2() == "") {
                   library.showSelectedPlaylist();
               }
               else {
                   library.showSpecifiedPlaylist(command.getArg2());
               }
           }
           else if (command.getArg1() == "playlists") {
               library.showPlaylists();
           }
           else if (command.getArg1() == "songs") {
               library.showSongs();
           }
           else if (command.getArg1() == "song") {
               if (command.getArg2() == "") {
                   cout << "error: No song title specified - nothing shown."  << endl;
               }
               else {
                   library.showSong(command.getArg2());
               }
           }
           else {
               cout << "error: Improper use of show. Use: " << endl;
               cout << "error:    show playlist [<playlist name>]" << endl;
               cout << "error:    show playlists" << endl;
               cout << "error:    show songs" << endl;
               cout << "error:    show song <song title>" << endl;
           }
       }
       else if (command.getOperation() == "clone") {
           if (command.getArg1() == "") {
               cout << "error: Improper use of clone. Must specify a new playlist name" << endl;
           }
           else {
               library.clonePlaylist(command.getArg1());
           }
       }
       else if (command.getOperation() == "import") {
           if (command.getArg1() == "") {
               cout << "error: Must specify at least one playlist to import." << endl;
           }
           else {
               library.importPlaylist(command.getArg1());
           }
       }
       else if (command.getOperation() == "exit") return 0;
       else {
           cout << "Command not recognized. Please try again." << endl;
       }

   }

}
