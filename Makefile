# 1. Detect the Operating System
ifeq ($(OS),Windows_NT)
    # Windows Settings
    EXE = .exe
    RM = del /Q
    FIX_PATH = $(subst /,\,$1)
    TARGET = gamestore$(EXE)
else
    # Mac and Linux Settings
    EXE =
    RM = rm -f
    FIX_PATH = $1
    TARGET = gamestore
endif

# 2. Compiler Settings
CC = gcc
CFLAGS = -Wall -g -I include
SRC = src/*.c

# 3. Build Rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up rule (Uses the RM variable we defined above)
clean:
	$(RM) $(TARGET)