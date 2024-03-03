FLAGS=-Wall

exec: main.cpp fvector.o fvectop.o fvectaux.o
	g++ ${FLAGS} -o exec main.cpp fvector.o fvectop.o fvectaux.o

fvector.o: fvector.h fvector.cpp
	g++ ${FLAGS} -c fvector.cpp

fvectop.o: fvectop.h fvectop.cpp
	g++ ${FLAGS} -c fvectop.cpp

fvectaux.o: fvectaux.h fvectaux.cpp
	g++ ${FLAGS} -c fvectaux.cpp

.PHONY: clean valgrind

clean:
	rm -f exec ./*.o

valgrind: exec
	valgrind --tool=memcheck ./exec
