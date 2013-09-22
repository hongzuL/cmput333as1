
read: readtext_s.c
	g++ -O -Wall readtext_s.c
clean:
	rm -f *~ a.out
run:
	./a.out
