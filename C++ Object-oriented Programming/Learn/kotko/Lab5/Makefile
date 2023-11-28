SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall

exec: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean valgrind

clean:
	rm -f exec ./*.o

valgrind: exec
	valgrind --tool=memcheck ./exec

