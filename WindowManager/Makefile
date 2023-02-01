CXXFLAGS ?= -Wall -g
CXXFLAGS += -std=c++1y
CXXFLAGS += `pkg-config --cflags x11 libglog`
LDFLAGS += `pkg-config --libs x11 libglog`
EXEC_NAME="Denizalti"

all: build

HEADERS = \
    util.hpp \
    window_manager.hpp
SOURCES = \
    util.cpp \
    window_manager.cpp \
    main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

build: $(HEADERS) $(OBJECTS)
	$(CXX) -o $(EXEC_NAME) $(OBJECTS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(EXEC_NAME) $(OBJECTS)
