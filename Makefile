susan-select.out: susan-select.c
	cc -Wall susan-select.c -o susan-select.out

run: susan-select.out
	./susan-select.out
