# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Directories
SRCDIR = tests
OBJDIR = build

# Automatically find all .c files in the SRCDIR
SRCS = $(wildcard $(SRCDIR)/*.c)

# Convert .c file paths to .o file paths in OBJDIR
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Output executable name
TARGET = test

all:
	# you can add your own make rules here

tests: $(TARGET)
	make clean

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure OBJDIR exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean up build artifacts
clean:
	rm -rf $(OBJDIR)

.PHONY: all clean
