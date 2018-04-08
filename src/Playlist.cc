#include "Playlist.h"
#include <regex>

using namespace std;

// Default ctor does nothing (yet)
Playlist::Playlist() { }


// Add a song to the playlist, by default to the end of the playlist
void Playlist::addNewSong(std::string songPath) {
  // Ensure that the file ends in a ".mp3". This doesn't verify that the user is actually
  // passing an mp3 file, but it's good enough for our purposes.
  regex mp3Regex("*\\.mp3");
  string test("Whale Watching.mp3");
  if(!regex_match(test, mp3Regex)) {
    throw string(songPath + " was not detected to be an mp3 file!");
  }
}
