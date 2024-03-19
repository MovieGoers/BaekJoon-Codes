#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	while (true) {
		int a;
		scanf("%d", &a);

		if (a == 0)
			break;

		if (a % N == 0) {
			printf("%d is a multiple of %d.\n", a, N);
		}
		else {
			printf("%d is NOT a multiple of %d.\n", a, N);
		}
	}
	
	return 0;
}
