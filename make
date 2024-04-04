CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

SOURCES = ./src/*.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJECTS) $(EXECUTABLE)