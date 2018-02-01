#include "Editor.h"
#include "Main.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Sets the path of the playlist editor instance and
// sets up screen info
MainClass::MainClass(string path): plEditor(path) {
  stdInHandle = GetStdHandle(STD_INPUT_HANDLE);
  stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  // Remember how colors were when we started
  GetConsoleScreenBufferInfo(stdOutHandle, &csbi);
}

// dtor cleans up and sets colors to normal
MainClass::~MainClass() {
  // Ditch any extra input in the buffer
  FlushConsoleInputBuffer(stdInHandle);
  // Set our colors back to normal
  SetConsoleTextAttribute(stdOutHandle, csbi.wAttributes);
}

// Verifies that the root music directory is valid
int MainClass::initialize() {
  try {
    plEditor.openRoot(); // Verify that the directory is valid
  } catch(string error) {
    SetConsoleTextAttribute(getStdOut(), 0x0C);
    cout << error + '\n';
    return EXIT_FAILURE;
  }
  return 0;
}

// Initial menu that is shown after root directory is validated/opened
void MainClass::mainMenu() {
  char choice;
  system("cls");
  cout << "Music library root path: ";
  SetConsoleTextAttribute(getStdOut(), 0x1A); // Print the directory in blue
  cout << plEditor.getMusicRoot() << '\n';
  SetConsoleTextAttribute(stdOutHandle, csbi.wAttributes); // Reset color
  while(1) {
    cout << "(q)uit, (n)ew: ";
    cin.get(choice);
    if(tolower(choice) == 'q') { return; }
    if(tolower(choice) == 'n') {
      cout << "Coming soon!\n";
      return;
    }
  }
}

void MainClass::usage() {
  cout << "USAGE: m3uEditor.exe Root-Music-Path\n"
    << "where Root-Music-Path is the path to the root of your music directory.\n";
}

int main(int argc, char *argv[]) {
  if(argc < 2) { // Need to pass path to root music directory
    MainClass::usage();
    return 0;
  }
  MainClass entryPoint(argv[1]); // Construct based on passed path
  // If the directory isn't valid, exit
  if(entryPoint.initialize() == EXIT_FAILURE) { return EXIT_FAILURE; }
  entryPoint.mainMenu();
  cout << "Bye!\n";
  return 0;
}
