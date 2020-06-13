SRC:= $(wildcard Tools/* .cpp) \
	  $(wildcard Main/* .cpp)

OBJECTS:= $(SRC:.cpp=.o)

exe: $(OBJECTS)
	 $(CXX) -g -o $@ $^

clean:
	rm -f $(OBJECTS) exe

