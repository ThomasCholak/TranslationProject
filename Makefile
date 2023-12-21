C = g++
CFLAGS = -std=c++11 -Wall

TARGET = comp
SRC = P4.cpp
HEADERS = P4.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
        $(C) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
        rm -f $(TARGET)
