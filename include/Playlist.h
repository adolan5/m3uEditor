#ifndef PLAYLIST_INCLUDED
#define PLAYLIST_INCLUDED

#include <vector>
#include <string>
/**
 * A representation of playlists.
 * Currently, we are only able to add to a new playlist. There may be room to expand
 * to load up an existing m3u playlist and create a Playlist object from it.
 * We allow duplicate songs, as you should when it comes to playlists.
 */

class Playlist {
  public:
    // Default ctor
    Playlist();

    // Add a song to the playlist, by default to the end of the playlist
    void addNewSong(std::string songPath);

  private:
    // The songs that are in this playlist
    std::vector<std::string> songs;
};

#endif
