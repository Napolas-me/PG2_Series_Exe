LDFLAGS = -g
CFLAGS = -c -g
stringExe: stringExe.o stringMan.o
	gcc $(LDFLAGS) -o stringExe stringExe.o stringMan.o

stringExe.o: stringExe.c stringMan.h
	gcc $(CFLAGS) stringExe.c

stringMan.o: stringMan.c stringMan.h
	gcc $(CFLAGS) stringMan.c

clean:
	rm -f *.o stringExe

debug: stringExe
	insight stringExe
	