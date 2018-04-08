CC=g++
C_FLAGS=-Wall -Wfatal-errors -Wextra -std=c++11
INCLUDE=-I include
# This include is not necessary unless you are building
# to run tests. In that case, get catch.hpp and place it
# in .\catch
TEST_INCLUDE=-I catch
OBJECTS=build\Editor.o build\Main.o build\Playlist.o
TEST_OBJS=build\test\Runner.o build\test\PlaylistTest.o
EXE=bin\m3uEditor.exe
TEST_EXE=bin\testRunner.exe

# Main entry point
$(EXE): $(OBJECTS)
	$(CC) $(INCLUDE) $(C_FLAGS) $(OBJECTS) -o $(EXE)

# Editor object
build\Editor.o: src\Editor.cc include\Editor.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

# Playlist object
build\Playlist.o: src\Playlist.cc include\Playlist.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

# Main object
build\Main.o: src\Main.cc include\Main.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

clean:
	del /Q /S $(EXE) $(TEST_EXE) build\*

### Tests Section ###
# Test entry point
$(TEST_EXE) test: $(EXE) $(TEST_OBJS)
	$(CC) $(TEST_INCLUDE) $(C_FLAGS) $(TEST_OBJS) -o $(TEST_EXE)

# Test runner object
build\test\Runner.o: src\test\Runner.cc
	$(CC) $(TEST_INCLUDE) $(C_FLAGS) -c -o $@ $<

# Playlist test cases
build\test\PlaylistTest.o: src\test\PlaylistTest.cc
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(C_FLAGS) -c -o $@ $<
