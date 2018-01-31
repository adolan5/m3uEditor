#ifndef ENTRY_INCLUDED
#define ENTRY_INCLUDED

#include <windows.h>
#include <string>

/**
 * Entry point for m3uEditor.
 */
class MainClass {
  public:
    // Default ctor grabs stdin info
    MainClass();
    //dtor cleans up (resets terminal to how it was)
    ~MainClass();

    // Getter for the csbi
    inline CONSOLE_SCREEN_BUFFER_INFO getScreenInfo() { return csbi; }
    // Getters for std in and std out
    inline HANDLE getStdIn() { return stdInHandle; }
    inline HANDLE getStdOut() { return stdOutHandle; }

    // Get the user's music path
    std::string getMusicPath();

  private:
    // Standard input device
    HANDLE stdInHandle;
    // Standard output device
    HANDLE stdOutHandle;
    // Storage for the way the terminal is at start
    CONSOLE_SCREEN_BUFFER_INFO csbi;
};

#endif
