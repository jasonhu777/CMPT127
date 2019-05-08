#include <stdio.h>
#include <math.h>

float floorf(float x);
float roundf(float x);
float ceilf(float x);


int main (void) {

	float f = 0;
	int floor = 0;
	int round = 0;
	int ceil = 0;

	while (scanf("%f", &f) == 1) {
		floor = floorf(f);
		round = roundf(f);
		ceil = ceilf(f);
		printf("%d %d %d\n", floor, round, ceil);
		
	}
    if (scanf("%f", &f) == EOF) {
	    printf( "Done.\n");
    }
	return 0;
}
