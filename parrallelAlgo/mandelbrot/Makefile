BIN= mandelbrot_gui mandelbrot

all:$(BIN)

mandelbrot_gui: mandelbrot_seq.c
	gcc -L/usr/X11R6/lib -DWITH_DISPLAY mandelbrot_seq.c -o mandelbrot_gui -fopenmp  -lX11

mandelbrot: mandelbrot_seq.c
	gcc mandelbrot_seq.c -o mandelbrot -fopenmp

clean:
	rm -f $(BIN)
