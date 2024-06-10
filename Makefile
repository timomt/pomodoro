# Makefile

CXX = g++ -g
CXXFLAGS = -Wall -Wextra -Werror -Wold-style-cast -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c++17

TARGET = pomodoro
OBJECTS = timer.o

.PHONY: all clean cppcheck

all: $(TARGET)

clean: 
	rm -f $(TARGET) main.o $(OBJECTS)

$(TARGET): main.o $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

cppcheck: main.cpp $(OBJECTS:.o=.cpp)
	$(CPPCHECK) $^

timer.o: timer.cpp timer.h
main.o: main.cpp timer.h
