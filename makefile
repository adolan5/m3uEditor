CC=g++
C_FLAGS=-Wall -Wfatal-errors -Wextra -std=c++11
INCLUDE=-I include
# This include is not necessary unless you are building
# to run tests. In that case, get catch.hpp and place it
# in .\catch
TEST_INCLUDE=-I catch
OBJECTS=build\Editor.o build\Playlist.o
TEST_OBJS=build\test\Runner.o build\test\PlaylistTest.o
MAIN_OBJECT=build\Main.o
EXE=bin\m3uEditor.exe
TEST_EXE=bin\testRunner.exe

# Run test suite
.PHONY: test
test: $(TEST_EXE)
	$(TEST_EXE)

### Main Objects/executables ###
# Main entry point, run tests by default on build
.PHONY: package
$(EXE) package: $(MAIN_OBJECT) test
	$(CC) $(INCLUDE) $(C_FLAGS) $(OBJECTS) $(MAIN_OBJECT) -o $(EXE)

# Main entry point, but skip tests
.PHONY: skip
skip: $(OBJECTS) $(MAIN_OBJECT)
	$(CC) $(INCLUDE) $(C_FLAGS) $(OBJECTS) $(MAIN_OBJECT) -o $(EXE)

# Editor object
build\Editor.o: src\Editor.cc include\Editor.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

# Playlist object
build\Playlist.o: src\Playlist.cc include\Playlist.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

# Main object
$(MAIN_OBJECT): src\Main.cc include\Main.h
	$(CC) $(INCLUDE) $(C_FLAGS) -c -o $@ $<

# Clean out executables and all objects
.PHONY: clean
clean:
	del /Q /S $(EXE) $(TEST_EXE) build\*

### Tests ###
# Create test entry point
$(TEST_EXE): $(TEST_OBJS) $(OBJECTS)
	$(CC) $(TEST_INCLUDE) $(C_FLAGS) $(OBJECTS) $(TEST_OBJS) -o $(TEST_EXE)

# Just compile, but don't output test suite
.PHONY: test-compile
test-compile: $(TEST_OBJS)

# Test runner object
build\test\Runner.o: src\test\Runner.cc
	$(CC) $(TEST_INCLUDE) $(C_FLAGS) -c -o $@ $<

# Playlist test cases
build\test\PlaylistTest.o: src\test\PlaylistTest.cc include\Playlist.h
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(C_FLAGS) -c -o $@ $<
