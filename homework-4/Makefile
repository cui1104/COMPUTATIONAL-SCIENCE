#define compiler
CC = g++

# directories 
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

# *_FILES use "wildcards" to create an automatic list of all the header (.h), source (.c), and object (.o) files based on the directory.
INC_FILES := $(wildcard $(INC_DIR)/*.h)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# -I$(INC_DIR) tells the compiler to include files in ./include and use the C++11 standard.
CFLAGS = -I$(INC_DIR) --std=c++11

# this DEPS says that if the files in ./include change, things should get recompiled. 
DEPS = $(INC_FILES)

# Define target "all". Since this is the first target, it is always run.
# Add additional files to build to the right hand side of this target.
all: main 

# This builds the "main.cpp" file. Note that: 
#   @, <, ^ are "automatic variables"
#   "@" refers to the target (left hand side of the ":")
#   "^" refers to the prerequisites (right hand side of the ":")
main: main.cpp $(OBJ_FILES)
	$(CC) $^ $(CFLAGS) -o $@

# Here, we build additional .o files. THIS SHOULD NOT BE CHANGED.
# We use "<", which stands for the first prerequisite. 
# If we use "^", we build all prereqs, including $(DEPS).
# If we use "^", we don't build the $(DEPS) prereq - these are just the headers, and we include them so if they change, the makefile gets updated.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f main $(OBJ_DIR)/*.o *~ *.o 


