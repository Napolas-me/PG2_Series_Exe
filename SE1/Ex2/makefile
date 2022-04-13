LDFLAGS = -g
CFLAGS = -c -g

readFromFile: readFromFile.o stringMan.o
	gcc $(LDFLAGS)-o readFromFile readFromFile.o stringMan.o 

readFromFile.o: readFromFile.c stringMan.h
	gcc $(CFLAGS) readFromFile.c

stringExe: stringExe.o stringMan.o
	gcc $(LDFLAGS) -o stringExe stringExe.o stringMan.o

stringExe.o: stringExe.c stringMan.h
	gcc $(CFLAGS) stringExe.c

stringMan.o: stringMan.c stringMan.h
	gcc $(CFLAGS) stringMan.c

clean:
	rm -f *.o stringExe  readFromFile a.out

debug: stringExe
	insight stringExe
	