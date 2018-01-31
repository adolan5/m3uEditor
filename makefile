CC=g++
C_FLAGS=-Wall -Wfatal-errors -Wextra -std=c++11
EXE=m3uEditor.exe

m3uEditor.exe: Editor.o Main.cc
	$(CC) $(C_FLAGS) Editor.o main.cc -o $(EXE)

Editor.o: Editor.cc Editor.h
	$(CC) $(C_FLAGS) -c Editor.cc

clean:
	del $(EXE) *.o
