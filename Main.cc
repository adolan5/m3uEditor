#include "Editor.h"
#include "Main.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

MainClass::MainClass() {
  stdInHandle = GetStdHandle(STD_INPUT_HANDLE);
  stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  // Remember how colors were when we started
  GetConsoleScreenBufferInfo(stdOutHandle, &csbi);
}

MainClass::~MainClass() {
  // Ditch any extra input in the buffer
  FlushConsoleInputBuffer(stdInHandle);
  // Set our colors back to normal
  SetConsoleTextAttribute(stdOutHandle, csbi.wAttributes);
}

string MainClass::getMusicPath() {
  string passedPath;
  cout << "Enter the path of your root music directory: ";
  cin >> passedPath;
  return resolvePath(passedPath);
}

string MainClass::resolvePath(string path) {
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

void MainClass::mainMenu() {
}

int main() {
  MainClass entryPoint;
  Editor myEditor(entryPoint.getMusicPath());
  try {
    myEditor.openRoot();
  } catch(string error) {
    SetConsoleTextAttribute(entryPoint.getStdOut(), 0x0C);
    cout << error + '\n';
    return EXIT_FAILURE;
  }
  system("cls");
  cout << "Music library root path: ";
  SetConsoleTextAttribute(entryPoint.getStdOut(), 0x1A);
  cout << myEditor.getMusicRoot() << '\n';
  return 0;
}
