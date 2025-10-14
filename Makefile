
# main:
# # 	clang -Wall -Wextra -std=gnu2y -g -o main src/main.c src/caesar.c src/vigenere.c
# 	clang -c src/main.c src/caesar.c src/vigenere.c 
# 	clang -o main caesar.o vigenere.o main.o
#clang -Wall -Wextra -std=gnu2y -g -o main caesar.o vigenere.o main.o
	

# Clean up
# clean:
# 	rm -f main


# CC = clang
# CFLAGS = -Wall -Wextra -std=gnu2y -g
# OBJS = caesar.o vigenere.o

# all: main

# main: $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o main

# caesar.o: src/caesar.c headers/caesar.h
# 	$(CC) $(CFLAGS) -c caesar.c

# vigenere.o: src/vigenere.c headers/vigenere.h
# 	$(CC) $(CFLAGS) -c src/vigenere.c

# clean:
# 	rm -f *~ *.o sysstatd
# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=gnu2y -g -Iheaders

# Source and object files
SRC = src/main.c src/knights_tour.c
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = main

all: $(TARGET)


# Build executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	del src/knights_tour.o

