all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	bin/gauss dane/A_test1 dane/b_test1
	
	
test1: all
	bin/gauss dane/A_test1 dane/b_test1

