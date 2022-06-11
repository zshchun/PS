#include <stdio.h>
int gcd1(int a, int b) {
	return b ? gcd1(b, a%b) : a;
}
int gcd2(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(int argc, char **argv) {
	printf("1071, 1029 : %d\n", gcd1(1071, 1029));
	printf("1071, 1029 : %d\n", gcd2(1071, 1029));
	return 0;
}

