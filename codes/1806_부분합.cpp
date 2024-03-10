#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

using namespace std;

int arr[100001];

int min(int A, int B) {
	if (A < B)
		return A;

	return B;
}

int main() {
	int arrSize, S;
	int start = 0, end = 0;
	int checkSum = 0;
	int minLen = 999999;

	scanf("%d %d", &arrSize, &S);

	arr[0] = 0;

	for (int i = 1; i <= arrSize; i++) {
		scanf("%d", &arr[i]);
	}

	while (start <= end && end <= arrSize) {
		if (checkSum >= S) {
			minLen = min(minLen, end - start);
			start++;
			checkSum -= arr[start];
		}
		else {
			end++;
			checkSum += arr[end];
		}
	}

	if (minLen != 999999)
		printf("%d", minLen);
	else
		printf("0");

	return 0;
}
