#include <stdio.h>

int main(void) {
	//int times = 2;
	char c;
	unsigned char uc;
	int i;
	unsigned int ui;
	long l;
	unsigned long ul;
	float f;
	double d; 
	long double ld;	

	printf("%d %d %d %d %d %d %d %d %d\n", 
		sizeof(c)*8, sizeof(uc)*8, sizeof(i)*8, sizeof(ui)*8, sizeof(l)*8, 
		sizeof(ul)*8, sizeof(f)*8, sizeof(d)*8, sizeof(ld)*8);
}
