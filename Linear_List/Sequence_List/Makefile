SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))
CFLAGS=-fexec-charset=GBK

main.exe: $(OBJ)
	@gcc $(CFLAGS) $^ -o $@
	
%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

.PHONY: clean
clean: 
	@del *.o 