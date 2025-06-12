```makefile
CC=gcc
CFLAGS=-Wall
SRCDIR=src
TARGET=reconix

$(TARGET): $(SRCDIR)/main.c $(SRCDIR)/modules.c
 $(CC) $(CFLAGS) $(SRCDIR)/main.c $(SRCDIR)/modules.c -o $(TARGET)

clean:
 rm -f $(TARGET)
