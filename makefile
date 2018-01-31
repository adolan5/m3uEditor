CC=g++
C_FLAGS=-Wall -Wfatal-errors -Wextra
C_SOURCES=m3uEditor.cc
EXE=m3uEditor.exe

m3uEditor.exe: m3uEditor.cc
	$(CC) $(C_FLAGS) $(C_SOURCES) -o $(EXE)

clean:
	del $(EXE)
