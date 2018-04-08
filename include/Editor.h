#ifndef EDITOR_INCLUDED
#define EDITOR_INCLUDED

#include <string>
#include <dirent.h>
#include <windows.h>

/**
 * This class will be responsible for most editing options.
 */
class Editor {
  public:
    // Default constructor
    Editor();
    // String constructor
    Editor(std::string path);
    // dtor closes directories if they're open
    ~Editor();

    // Music root path getter
    inline std::string getMusicRoot() { return musicRoot; }

    // (Try to) open up the root directory
    void openRoot();
  private:
    // The root of the user's music library
    std::string musicRoot;
    // The directory that is the root of the music dir
    DIR *root;

    // Resolves the full path of a directory or file
    std::string resolvePath(std::string path);
};

#endif
