# Makefile

# Cross-compiler prefix
CC = i586-pc-msdosdjgpp-gcc

# Paths
INCLUDES = -I./pdcurses/include
LIBDIR   = -L./pdcurses/lib
LIBS     = -lpdcurses

# Compiler flags
CFLAGS = -Wall -O2 $(INCLUDES)
LDFLAGS = $(LIBDIR) $(LIBS)

# Output and sources
TARGET = curses.exe
SRCS = curses.c

# Build target
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET)

.PHONY: all clean

