#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	
	return b;
}

int main() {
	int N, maxVal = 0;
	int arrPrev[502] = { 0, };
	int arrCurr[502] = { 0, };
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			int temp;
			cin >> temp;
			arrCurr[j + 1] = max(arrPrev[j], arrPrev[j + 1]) + temp;
		}
		for (int j = 0; j < i; j++) {
			arrPrev[j + 1] = arrCurr[j + 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (maxVal < arrCurr[i]) {
			maxVal = arrCurr[i];
		}
	}

	cout << maxVal;

	return 0;
}
