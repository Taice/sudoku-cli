CC := clang
CFLAGS := -Wall -g

SRCFILES := $(wildcard ./*.c)
OBJFILES := $(SRCFILES:.c=.o)

LINK := -lm

OUTPUT := game

all : $(OUTPUT)

$(OUTPUT) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LINK)

%.o : %.c $.h
	$(CC) $(CFLAGS) -c $^ $(LINK)

run : 
	make
	./$(OUTPUT)

clean : 
	rm $(OBJFILES) $(OUTPUT)

debug :
	make
	gdb ./$(OUTPUT)
