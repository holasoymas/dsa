CC = clang
CFLAGS = -Wall -Wextra -g

# List of source files (replace with your actual filenames)
SRCS = complexNum.c addComplex.c

# List of object files derived from source files
OBJS = $(SRCS:.c=.o)

# Target executable name
TARGET = complex

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)
