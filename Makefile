# Paths
RAYLIB_PATH = C:/raylib/raylib
SRC_DIR     = src
BUILD_DIR   = build
BIN         = main.exe

# Compiler and flags
CXX      = gcc
CXXFLAGS = -Wall -D_DEFAULT_SOURCE -Wno-missing-braces -g -O0
#-std=c++14
# Includes and libs
INCLUDES = -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external
LIBS     = -L$(RAYLIB_PATH)/src -lraylib -lopengl32 -lgdi32 -lwinmm

# Sources
SOURCES  = $(wildcard $(SRC_DIR)/*.c)
HEADERS  = $(wildcard $(SRC_DIR)/*.h)

# Target
$(BIN): $(SOURCES)
	$(CXX) -o $@  $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -DPLATFORM_DESKTOP
#	$(CXX) -o $@  $^ $(HEADERS) $(CXXFLAGS) $(INCLUDES) $(LIBS) -DPLATFORM_DESKTOP
#	$(CXX) -o $@  $^ $(HEADERS) $(CXXFLAGS) $(INCLUDES) $(LIBS) -DPLATFORM_DESKTOP -Wl,--subsystem,windows

# Clean rule
clean:
	del /Q $(BIN)
