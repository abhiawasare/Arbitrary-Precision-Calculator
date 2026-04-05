OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
Apc.exe:$(OBJ)
	gcc -o $@ $^
clean:
	rm *.o *.exe