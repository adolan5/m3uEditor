#include "Editor.h"
#include <iostream>
#include <string>
#include <dirent.h>

using namespace std;

// Default ctor does nothing
Editor::Editor():musicRoot("") { }

// String ctor initializes music root
Editor::Editor(string path):musicRoot(path) { }

// dtor closes directories if they're open
Editor::~Editor() {
  if(root != NULL) { closedir(root); }
}

// Verify that the passed directory is valid and open it
void Editor::openRoot() {
  if((root = opendir(musicRoot.c_str())) == NULL) {
    throw string(musicRoot + " is not a valid directory!");
  }
}
