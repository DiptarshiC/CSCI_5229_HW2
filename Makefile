exe=hw2
all:$(exe)


#Ubuntu

LIBS=-lglut -lGLU -lGL
CFlags= -Wall 


#compiler rules
.c.o:
	gcc -c $(CFlags) $<

#linking
hw2:main.c
	gcc -o $@ $^  $(LIBS)

.PHONY: clean

clean:
	rm -f sort hw2
