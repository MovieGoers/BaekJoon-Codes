#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;

	return b;
}

int main() {
	int N;
	cin >> N;

	int houses[1001][3];
	houses[0][0] = houses[0][1] = houses[0][2] = 0;

	for (int i = 1; i <= N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		houses[i][0] = min(houses[i - 1][1], houses[i - 1][2]) + r;
		houses[i][1] = min(houses[i - 1][0], houses[i - 1][2]) + g;
		houses[i][2] = min(houses[i - 1][0], houses[i - 1][1]) + b;
	}

	if (houses[N][0] < houses[N][1]) {
		if (houses[N][0] < houses[N][2])
			cout << houses[N][0];
		else
			cout << houses[N][2];
	}
	else {
		if (houses[N][1] < houses[N][2])
			cout << houses[N][1];
		else
			cout << houses[N][2];
	}
	return 0;
}
