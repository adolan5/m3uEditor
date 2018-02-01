#ifndef ENTRY_INCLUDED
#define ENTRY_INCLUDED

#include <windows.h>
#include <string>
#include "Editor.h"

/**
 * Entry point for m3uEditor.
 */
class MainClass {
  public:
    // Default ctor sets root path to ""
    MainClass();
    // String ctor sets up music root path and stdin stuff
    MainClass(std::string path);
    //dtor cleans up (resets terminal to how it was)
    ~MainClass();

    // Getter for the csbi
    inline CONSOLE_SCREEN_BUFFER_INFO getScreenInfo() { return csbi; }
    // Getters for std in and std out
    inline HANDLE getStdIn() { return stdInHandle; }
    inline HANDLE getStdOut() { return stdOutHandle; }

    // Initialize root directory
    int initialize();

    // Display root menu
    void mainMenu();

    // Display a usage method
    static void usage();

  private:
    // An instance of a playlist editor
    Editor plEditor;
    // Standard input device
    HANDLE stdInHandle;
    // Standard output device
    HANDLE stdOutHandle;
    // Storage for the way the terminal is at start
    CONSOLE_SCREEN_BUFFER_INFO csbi;
};

#endif
