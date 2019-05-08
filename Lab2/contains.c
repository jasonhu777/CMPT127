#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main(int argc, char* argv[]) {

/*
	//printf("%s\n", argv[0]);
	printf("argv[1]: %s\n", argv[1]);
	printf("argv[2]: %s\n", argv[2]);
	printf("argc: %d\n", argc);
*/
	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[2]);

/*
for (int i =0; i <len1; i++) {
	printf("%c\n", argv[1][i]);
}
	
	printf("%d\n", len1);
	printf("%d\n", len2);
*/
	if (argc < 3) {
		printf("false\n");
	}


	if (len2 > len1) {
		printf("false\n");
	}

	int i = 0;
	int j = 0;

	while (len1 >= len2 && j != len2 && argc >= 3 && i != len1) {
		for (i = 0, j = 0; i < len1; i++) {
			
			if (argv[1][i] == argv[2][j] && j != len2) {
				
				while (argv[1][i] == argv[2][j] && j < len2) {

					i++;
					j++;
				}
				if (j == len2) {
					printf("true\n");
					break;
				} else {
					printf("false\n");
					break;
				}
				
			}  
			
			
		}
		if (i == len1 && len1 != len2) {
				printf("false\n");
			}
	}


	return 0;
}