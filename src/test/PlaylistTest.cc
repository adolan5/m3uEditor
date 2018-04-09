#include "Playlist.h"
#include "catch.hpp"

using namespace std;

/**
 * Test case for adding a song to a playlist.
 */
TEST_CASE("Playlist::addNewSong") {
  // Using catch, we know that this line will be called before each section
  Playlist thePlaylist;
  SECTION("A valid song file, ending in '.mp3'") {
    string validSong("Whale Watching.mp3");
    REQUIRE_NOTHROW(thePlaylist.addNewSong(validSong));
    // Verify that the song is in the playlist now
    REQUIRE(thePlaylist.contains(validSong));
  }

  SECTION("An invalid song file (not ending in '.mp3'") {
    REQUIRE_THROWS(thePlaylist.addNewSong("pants"));
    REQUIRE(thePlaylist.getNumSongs() == 0);
  }

  SECTION("An invalid song file that almost ends in '.mp3'") {
    REQUIRE_THROWS(thePlaylist.addNewSong("trousersmp3"));
    REQUIRE(thePlaylist.getNumSongs() == 0);
  }
}
