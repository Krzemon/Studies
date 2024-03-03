exec: binary.o cipher.o main.cpp xor.o mystring.o
	g++ -Wall mystring.o binary.o cipher.o xor.o main.cpp -o exec

mystring.o: mystring.cpp mystring.h
	g++ -Wall -c mystring.cpp

binary.o: binary.h binary.cpp mystring.cpp mystring.h
	g++ -Wall -c binary.cpp

cipher.o: cipher.cpp cipher.h binary.cpp binary.h mystring.h mystring.cpp xor.cpp xor.h
	g++ -Wall -c cipher.cpp

xor.o: xor.cpp xor.h
	g++ -Wall -c xor.cpp

.PHONY: clean
clean:
	rm -f *.o exec
