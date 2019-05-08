#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isSpaceOrEOF(char c);
bool isAlphabet(char c);

int main() {

unsigned long int charcount = 0;
unsigned long int wordcount = 0; 
unsigned long int linecount = 0;
unsigned long int space = 0;

char last = getchar();
while(last != EOF) {
	charcount++;
	char current = getchar();
	if (!isAlphabet(last) && isAlphabet(current)) {
		wordcount++;
	}
	if ( current == '\n') {
		linecount++;
	}
	last = current;
}
printf("%lu %lu %lu\n", charcount, wordcount, linecount);
	return 0;
}
bool isAlphabet(char c) {
	return (c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z') || c == '\'' || c == EOF;
}
bool isSpaceOrEOF(char c) {
	return (isspace(c) ||c == EOF);
	// isspace(c)
}