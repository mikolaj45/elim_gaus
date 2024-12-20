all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

test_case1: all
	bin/gauss dane/C dane/d

test_case2: all
	bin/gauss dane/E dane/f
