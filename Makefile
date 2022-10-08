# Set the windows path you want to move the game inorder to run it (use /mnt/ befor the path so you can access you disk)
WIN_PATH := /mnt/c/Users/panat/Desktop/

# Set the name of the output
EXEC := game

# paths
LIB := ./lib
INCLUDE := ./include
SRC := ./src
BUILD := ./build

#Program args
ARGS := 3

#Default compiler
CC = gcc
CCPP = g++

#Debug mode
DEBUG := false

#Exta object files
EXTRA := $(LIB)/libraylib.a


################################### DO NOT EDIT BELOW THIS LINE UNLESS YOU KNOW WHAT YOU ARE DOING ###################################


# Makefile options
PLATFORM = linux

#compiler options
CFLAGS = -Wall -Werror -I$(INCLUDE)
CPPFLAGS = -I$(INCLUDE)  -O3
LDFLAGS = -lm

SRCS := $(shell find $(SRC) -name '*.c')
OBJS := $(SRCS:$(SRC)/%.c=$(SRC)/%.o)
OBJPATH := $(addprefix $(BUILD)/,$(notdir $(OBJS)))

SRCS_CPP := $(shell find $(SRC) -name '*.cpp')
OBJS_CPP := $(SRCS_CPP:$(SRC)/%.cpp=$(SRC)/%.opp)
OBJPATH_CPP := $(addprefix $(BUILD)/,$(notdir $(OBJS_CPP)))

ifeq ($(DEBUG),true)
	CFLAGS += -g3 -O0
else
	CFLAGS += -O3
endif

ifeq ($(PLATFORM),win)
	LDFLAGS += -lgdi32 -lwinmm -lopengl32 -lpthread -static-libstdc++ -static-libgcc --static
	CC = x86_64-w64-mingw32-gcc
	CCPP = x86_64-w64-mingw32-g++
	EXTRA := $(LIB)/libraylib.a
	EXEC :=$(EXEC).exe
else ifeq ($(PLATFORM),linux)
	LDFLAGS += -ldl -lpthread -lGL
	EXTRA := $(LIB)/libraylib.a
	WIN_PATH = ./
else ifeq ($(PLATFORM),web)
	LDFLAGS += -lm -lGL
	
endif

$(SRC)/%.opp: $(SRC)/%.cpp
	$(CCPP) $(CPPFLAGS) -c $< -o $@
	mv $@ $(BUILD)

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ && mv $@ $(BUILD) 

# Για να φτιάξουμε τα k08.a/libraylib.a τρέχουμε το make στο lib directory.
$(LIB)/%.a:
	$(MAKE) -C $(LIB) $*.a SUFFIX=$(PLATFORM)

$(EXEC):$(OBJS) $(OBJS_CPP) $(EXTRA)
	$(CCPP) $(OBJPATH) $(OBJPATH_CPP) $(EXTRA) -o $(EXEC) $(LDFLAGS)
#Cleaning
PHONY clean:
	rm -f $(BUILD)/*.o $(BUILD)/*.opp $(EXEC) $(EXTRA) $(EXEC).exe

# valgrind: $(EXEC)
# 	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGS)

# run: $(EXEC)
# 	./$(EXEC) $(ARGS)
