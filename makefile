CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = trees_helpers.o trees.o
TARGET = trees


all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET)
