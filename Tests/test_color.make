################################################################################
# Project name
# @file
# Authors:
#		-
################################################################################



# Set Varibles #################################################################

# Directory and name of the executable:
EXEC = color.out

# Main test file
MAIN = test_color.cpp

#Directory of source code:
DIR_SOURCE = ../src
SOURCE = $(wildcard $(DIR_SOURCE)/*.cpp)

# Directory of includeded headers and headers:
DIR_INCLUDE = ../inc
INCLUDE = $(wildcard $(DIR_INCLUDE)/*.hpp)

# Directory of objects and objects:
DIR_OBJ = Build
OBJS= $(addprefix $(DIR_OBJ)/,$(notdir $(SOURCE:.cpp=.o)))

# Compilator and flags:
CC = g++
LIBS  = -lm `pkg-config --cflags --libs opencv`
CFLAGS = -std=c++14 -c -Wall -W -Wextra -I $(DIR_INCLUDE)

# LCOV directory name
LCOV = lcov_html

# ################ #############################################################


# Make Commands ################################################################

all: $(EXEC)

covarage: CFLAGS += -fprofile-arcs -ftest-coverage
covarage: LIBS += -fprofile-arcs -ftest-coverage
coverage: reset $(EXEC)
	./$(EXEC)
	gcov $(DIR_OBJ)
	lcov -d . -c -o $(EXEC).info
	genhtml $(EXEC).info -o $(LCOV)

debug: CFLAGS += -ggdb
debug: reset all


.PHONY: clean reset
clean:
	rm -f $(DIR_OBJ)/*.o
	rm -f $(DIR_OBJ)/*.gcda
	rm -f $(DIR_OBJ)/.gcno
	rm -rf $(DIR_OBJ)
	rm -f $(EXEC).info
reset: clean
	rm -f $(EXEC)
	rm -f $(EXEC)
	rm -rf $(LCOV)

# ################# ############################################################


# Build ########################################################################

$(EXEC): $(OBJS) $(DIR_OBJ)/main.o
	$(CC) $^ -o $@ $(LIBS)

$(DIR_OBJ)/main.o: $(MAIN)
	@mkdir -p $(DIR_OBJ)
	$(CC) -c $< -o $@ $(CFLAGS)

$(DIR_OBJ)/%.o: $(DIR_SOURCE)/%.cpp $(DIR_INCLUDE)/%.hpp
	@mkdir -p $(DIR_OBJ)
	$(CC) -c $< -o $@ $(CFLAGS)

# ##############################################################################
