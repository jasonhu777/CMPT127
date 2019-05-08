//TESTING Git

#include <stdio.h>

int main() {
	int width = 0, breadth = 0, height = 0;
    int min = 1;
    int max = 50;
	
	while (scanf("%d %d %d", &width, &breadth, &height) == 3 && width > 0 && breadth > 0 && width > 0) {

		for (int i = 0; i < breadth; i++) {

            for (int j =0; j < width; j++) {

                if (i == 0 || j == 0 || i == breadth -1  || j == width - 1) {
                    printf("#");
                } 
                else {
                    printf(".");

                }
            }
            printf("\n");

        }
	}

	return 0;
}
