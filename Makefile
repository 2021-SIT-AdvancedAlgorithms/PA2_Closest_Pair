all:
	gcc -o closest_pair closest_pair.c kernel.c -lm -O2

competition:
	echo '99999' | ./closest_pair n 2d