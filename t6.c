#include <stdio.h>
#include <math.h>

float roundf(float x);

int main() {
	float f;
	float smallest;
	float largest;
	float total;
	int numInputs = 1;

	if (scanf("%f", &f) == 1) {
		smallest = largest = total = f;
	}

//smallest = largest = total = f;
	while (scanf("%f", &f) == 1) {

		if (f >= -100000 && f <= 100000) {
			if (smallest > f) {
				smallest = f;
			}
			if (largest < f) {
				largest = f;
			}
		
			total += f;
			numInputs++;	
		}
		

	}
	printf("%.2f %.2f %.2f\n", smallest, largest, total/numInputs);

	return 0;
}
