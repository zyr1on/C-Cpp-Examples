CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LIBS = $(shell pkg-config --cflags --libs poppler-cpp)

SRCS = src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = pdf2text

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS); $(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

%.o: %.cpp; $(CXX) $(CXXFLAGS) -c $< -o $@

clean: ; rm -f $(OBJS) $(TARGET)
