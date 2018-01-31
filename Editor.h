#ifndef EDITOR_INCLUDED
#define EDITOR_INCLUDED

#include <vector>
#include <string>

/**
 * This class will be responsible for most editing options.
 */
class Editor {
  public:
    // Default constructor
    Editor();
    // String constructor
    Editor(std::string root);

    // Music root path getter
    inline std::string getMusicRoot() { return musicRoot; }
  private:
    // The root of the user's music library
    std::string musicRoot;
};

#endif
