all:
	gcc -Wall --pedantic src/gauss.c src/mat_io.c src/main.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	bin/gauss dane/A_test1 dane/b_test1
	bin/gauss dane/C dane/d
	bin/gauss dane/E dane/f
	
	

