#include "Playlist.h"
#include <regex>
#include <algorithm>

using namespace std;

// Default ctor does nothing (yet)
Playlist::Playlist() { }


// Add a song to the playlist, by default to the end of the playlist
void Playlist::addNewSong(std::string songName) {
  // Ensure that the file ends in a ".mp3". This doesn't verify that the user is actually
  // passing an mp3 file, but it's good enough for our purposes.
  regex mp3Regex(".*[.]mp3");
  if(!regex_match(songName, mp3Regex)) {
    throw string(songName + " was not detected to be an mp3 file!");
  }

  // Add it to the list
  songs.push_back(songName);
}

// Get the number of songs in the playlist
int Playlist::getNumSongs() {
  return songs.size();
}

// Tell if a song is in the playlist
bool Playlist::contains(string songName) {
  if(find(songs.begin(), songs.end(), songName) != songs.end()) {
    return true;
  }
  return false;
}
