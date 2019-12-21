INCLUDE:=-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12
LIBS:=-lcairo -lpng12

all: clean build

clean:
	rm -f hamilton

build:
	gcc $(INCLUDE) -o hamilton hamilton.c $(LIBS)
