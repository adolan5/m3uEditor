CC=g++
C_FLAGS=-Wall -Wfatal-errors -Wextra -std=c++11
INCLUDE=-I include
OBJECTS=build\Editor.o build\Main.o
EXE=bin\m3uEditor.exe

# Main entry point
$(EXE): $(OBJECTS)
	$(CC) $(INCLUDE) $(C_FLAGS) build\\*.o -o $(EXE)

# Editor object
build\Editor.o: src\Editor.cc include\Editor.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

# Main object
build\Main.o: src\Main.cc include\Main.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

clean:
	del /Q $(EXE) build\*
