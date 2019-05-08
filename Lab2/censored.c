#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isAlphabet(char c);

int main(int argc, char* argv[]) {

	char word[128] = { 0 };
	int censor = 0;
	int i = 0;

/*
	printf("argv[1]: %s\n", argv[1]);
	printf("argv[2]: %s\n", argv[2]);
	printf("argc: %d\n", argc);
*/
	//printf("%d\n", len1);
	//printf("%d\n", len2);

	char c = getchar();
	while (c!= EOF) {

		if (isAlphabet(c) || c == '\'' ) {
		word[i] = c;
		//word[i];
		i++;
		}
		else {
			censor = 0;
			for (int j = 0; j < argc; j++) {
				if (strcmp(argv[j], word) == 0) {
					// 0 means equal if < 0, str1 < str2  if >0, str1 > str2
				
					censor = 1;
					printf("CENSORED");
				}
			}
			if (censor == 0) {
				printf("%s", word);
				
			}
			if (!isAlphabet(c)){
				printf("%c", c);
			}
			i = 0;
			memset(word, 0, sizeof(word));
		}	
		c = getchar();	
	}
	return 0;
}

bool isAlphabet(char c) {
	return (c >= 'a' && c <= 'z') || (c>= 'A' && c<= 'Z');
}