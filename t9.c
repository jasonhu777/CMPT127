#include <stdio.h>
#include <math.h>

	double floor(double x);
	double ceil(double x);

int main() {

	int width = 0, breadth = 0, height = 0;





	while (scanf("%d %d %d", &width, &breadth, &height) == 3 && width > 0 && breadth > 0 && width > 0) {

		for (int j = height -1; j >= 0 ; j--) {

		int left = floor(j*(width/(2.0*height)));
		int right = ceil((width-1) + -j*(width/(2.0*height)));



			for (int i = 0; i < width; i++) {



				if (i == left || i == right  || j == 0 ) {
				printf("#");
				}


				if ( j == (height-1) && (right-1) != left && i > left && i < right)
				{
				printf("#");
				}

				if (i > left && i < right && j > 0 && j != (height-1) ) 
				{
				printf(".");
				}

				if (i < left && j > 0)
				{
				printf(" ");
				}

			}	
			printf("\n");
		}



	}
	return 0;
}
