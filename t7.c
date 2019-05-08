#include <stdio.h>

int main() {

int d = 0;
	while (scanf("%d", &d) == 1) {
			for (int i = 0; i < d; i++) {
				printf("#");
			}
			printf("\n");
	}
	return 0;
}
