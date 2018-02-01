#include "Editor.h"
#include <iostream>
#include <string>
#include <dirent.h>
#include <windows.h>

using namespace std;

// Default ctor does nothing
Editor::Editor():musicRoot("") { }

// String ctor initializes music root
Editor::Editor(string path):musicRoot(resolvePath(path)) { }

// dtor closes directories if they're open
Editor::~Editor() {
  if(root != NULL) { closedir(root); }
}

string Editor::resolvePath(string path) {
  DWORD retval = 0; // Indicates success
  char buffer[260]; // 260 is stdlib.h's MAX_PATH
  retval = GetFullPathName(path.c_str(), 260, buffer, NULL);
  // On failure, return empty string
  if(retval == 0) {
    return "";
  }
  else {
    return string(buffer);
  }
}

// Verify that the passed directory is valid and open it
void Editor::openRoot() {
  if((root = opendir(musicRoot.c_str())) == NULL) {
    throw string(musicRoot + " is not a valid directory!");
  }
}
