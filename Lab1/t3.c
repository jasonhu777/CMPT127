#include <stdio.h>
#include <math.h>

float floorf(float x);
float roundf(float x);
float ceilf(float x);


int main(void) {

	float f = 0;
	int floor = 0;
	int round = 0;
	int ceil = 0;
	
	scanf("%f", &f);

	floor = floorf(f);
	round = roundf(f);
	ceil = ceilf(f);


	printf("%d %d %d\n", floor, round, ceil);


	return 0;
}
