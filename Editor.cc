#include "Editor.h"
#include <iostream>
#include <string>

using namespace std;

// Default ctor does nothing
Editor::Editor():musicRoot("") { }

// String ctor initializes music root
Editor::Editor(string root):musicRoot(root) { }
