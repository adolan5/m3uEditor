#ifndef EDITOR_INCLUDED
#define EDITOR_INCLUDED

#include <vector>
#include <string>
#include <dirent.h>

/**
 * This class will be responsible for most editing options.
 */
class Editor {
  public:
    // Default constructor
    Editor();
    // String constructor
    Editor(std::string path);

    // Music root path getter
    inline std::string getMusicRoot() { return musicRoot; }

    // (Try to) open up the root directory
    void openRoot();
  private:
    // The root of the user's music library
    std::string musicRoot;
    // The directory that is the root of the music dir
    DIR *root;
};

#endif
