#include <iostream>

using namespace std;

int map[100002][2] = {0, };
int N;

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b > c) {
			return b;
		}
		else {
			return c;
		}
	}
}

int DP() {
	int sum[100002][2] = { 0, };

	for (int i = N - 1; i >= 0; i--) {
		sum[i][0] = map[i][0] + max(sum[i+1][1], sum[i+2][0], sum[i+2][1]);
		sum[i][1] = map[i][1] + max(sum[i+1][0], sum[i+2][0], sum[i+2][1]);
	}

	if (sum[0][0] > sum[0][1])
		return sum[0][0];
	else
		return sum[0][1];
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		for (int j = 0; j < N * 2; j++) {
			cin >> map[j % N][j / N];
		}

		cout << DP() << '\n';
	}
	return 0;
}
