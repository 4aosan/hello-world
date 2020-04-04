#hello world
TARGET  = hello
CC      = gcc
CFLAGS  = -g -MMD -MP
LDFLAGS = 
LIBS    = 
INCLUDE = -I ./include
SRC_DIR = ./src
OBJ_DIR = ./build
SOURCES = $(shell ls $(SRC_DIR)/*.c)
SRC     = $(SRC_DIR)/%.c
OBJS    = $(subst $(SRC_DIR),$(OBJ_DIR),$(SOURCES:.c=.o))
OBJ     = $(OBJ_DIR)/%.o
DEPENDS = $(OBJS:.o=.d)

$(warning SOURCES=$(SOURCES))
$(warning OBJS=$(OBJS))

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(TARGET)

-include $(DEPENDS)

.PHONY: all clean
