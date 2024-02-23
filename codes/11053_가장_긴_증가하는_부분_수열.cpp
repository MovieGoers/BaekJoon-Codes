#include <iostream>

using namespace std;

int main() {
	int N, arr[1001][2];
	cin >> N;

	arr[0][0] = 0;
	arr[0][1] = 0;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0];
	}


	for (int i = 1; i <= N; i++) {
		int maxVal = -1;
		for (int j = 0; j < i; j++) {
			if (arr[i][0] > arr[j][0]) {
				if (maxVal < arr[j][1]) {
					maxVal = arr[j][1];
				}
			}
		}
		arr[i][1] = maxVal + 1;
	}

	int max = -1;

	for (int i = 1; i <= N; i++) {
		if (arr[i][1] > max) {
			max = arr[i][1];
		}
	}

	cout << max;

	return 0;
}
