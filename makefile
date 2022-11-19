CC := g++
CFLAGS := -std=c++17 -Wall -g -DDEBUG

LIBS :=  -DSFML_STATIC -lsfml-window-d -lsfml-system-d -lsfml-graphics-d -lopengl32  -lgdi32 -lwinmm
buildPath := build
objPath := objs
srcPath := src

# OBJ = 
# OBJ := $(addprefix $(objPath)/, $(OBJ))

vpath %.cpp $(srcPath):$(socketPath)
vpath %.h   $(srcPath):$(socketPath)


.PHONY: build rebuild run clean

$(objPath)/%.o: %.cpp %.h
	$(CC) -o $@ $< -c $(CFLAGS)

$(buildPath)/$(EXENAME).exe: $(OBJ) $(srcPath)/main.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) 
clean:
	cd $(buildPath) && DEL /F/Q/S *.* > NUL
	cd $(objPath) && DEL /F/Q/S *.* > NUL

build:
	$(MAKE) EXENAME="run" 

rebuild:
	$(MAKE) clean 
	$(MAKE) build	