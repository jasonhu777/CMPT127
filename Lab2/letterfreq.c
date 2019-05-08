#include <stdio.h>
#include <stdbool.h>

bool isAlphabet(char c);

int main(int argc, char* argv[]) {

	float letters[26] = { 0 };
	int count = 0;

	char c = getchar();

	while (c!= EOF) {

		if (isAlphabet(c)) {
			count++;
			if (c >= 'A' && c <= 'Z') {
				c += 32;
			}
			c -= 'a';
			letters[c]++;
		}

		c = getchar();
	}
	//printf("count is: %d\n", 6/count);
	for (int i = 0; i < sizeof(letters)/4; i++) {
		//printf("%d ", letters[i]);
		if (letters[i] != 0) {
			printf("%c %.4f\n", 'a'+i, letters[i]/count);
		}
	}
	return 0;
}

bool isAlphabet(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}