exe: struct.o user.o is_functions.o functions.o main.o save.o 
	gcc struct.o user.o is_functions.o functions.o main.o save.o -o exe

struct.o: src/struct.c src/struct.h
	gcc -c -Wall src/struct.c -o struct.o

save.o: src/save.c src/save.h src/user.h src/functions.h 
	gcc -c -Wall src/save.c -o save.o

user.o: src/user.c src/user.h src/struct.h src/functions.h src/save.h
	gcc -c -Wall src/user.c -o user.o

is_functions.o: src/is_functions.c src/is_functions.h src/struct.h src/functions.h src/user.h
	gcc -c -Wall src/is_functions.c -o is_functions.o 

functions.o: src/functions.c src/functions.h src/struct.h src/user.h
	gcc -c -Wall src/functions.c -o functions.o 

main.o: src/main.c src/user.h src/save.h
	gcc -c -Wall src/main.c -o main.o 

clean: 
	rm -f *.o 
	rm -f exe 
