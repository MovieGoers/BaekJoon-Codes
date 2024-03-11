#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {
	int bagSize, swapCnt;
	int bags[101];

	scanf("%d%d", &bagSize, &swapCnt);

	for (int i = 1; i <= bagSize; i++) {
		bags[i] = i; 
	}

	for (int i = 0; i < swapCnt; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		// a와 b 바구니 내용 swap.'
		while (a <= b) {
			int temp = bags[a];
			bags[a] = bags[b];
			bags[b] = temp;

			a++;
			b--;
		}
	}

	for (int i = 1; i <= bagSize; i++) {
		printf("%d ", bags[i]);
	}


	return 0;
}
