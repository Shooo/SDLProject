EXE = sdlproject

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC = g++
CPPFLAGS = -Iinclude
CFLAGS = -Wall
LDFLAGS = -lSDL2 -lSDL2main -lSDL2_image

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

$(OBJ_DIR):
	mkdir -p $@
clean:
	rm -f $(EXE) $(OBJ)
