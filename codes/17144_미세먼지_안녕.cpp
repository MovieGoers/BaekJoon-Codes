#include <iostream>
#include <utility>

using namespace std;

int width, height, T;
int map[50][50];

pair<int, int> upper, lower;

int dh[4] = { 0, 0, -1, 1 };
int dw[4] = { -1, 1, 0, 0 };

pair<int, int> GetDhDw(char c) {
	pair<int, int> retVal;
	
	switch (c) {
	case 'U':
		retVal.first = -1;
		retVal.second = 0;
		break;
	case 'D':
		retVal.first = 1;
		retVal.second = 0;
		break;
	case 'L':
		retVal.first = 0;
		retVal.second = -1;
		break;
	case 'R':
		retVal.first = 0;
		retVal.second = 1;
		break;
	}

	return retVal;
}

void DiffuseDust() {
	int tempMap[50][50] = { 0, };

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			int spreadAmount = map[h][w] / 5;
			for (int i = 0; i < 4; i++) {
				int newH = h + dh[i];
				int newW = w + dw[i];

				if (newH < 0 || newH >= height || newW < 0 || newW >= width)
					continue;

				if (map[newH][newW] == -1)
					continue;

				tempMap[newH][newW] += spreadAmount;
				tempMap[h][w] -= spreadAmount;
			}
		}
	}

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			map[h][w] += tempMap[h][w];
		}
	}
};

void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ActivateAirCleaner() {
	pair<int, int> A, B;
	char direction = 'U';

	// 공기청정기 위쪽 순환
	A.first = upper.first - 1;
	A.second = upper.second;
	B.first = upper.first;
	B.second = upper.second;

	while (1) {
		Swap(&map[A.first][A.second], &map[B.first][B.second]);

		if (A.first == upper.first && A.second == upper.second)
			break;

		B.first = A.first;
		B.second = A.second;

		if (B.first == 0 && B.second == 0) {
			direction = 'R';
		}
		else if (B.first == 0 && B.second == width - 1) {
			direction = 'D';
		}
		else if (B.first == upper.first && B.second == width - 1) {
			direction = 'L';
		}

		pair<int, int> newD = GetDhDw(direction);
		A.first = B.first + newD.first;
		A.second = B.second + newD.second;
	}
	map[upper.first][upper.second + 1] = 0;

	// 공기청정기 아래쪽 순환 
	A.first = lower.first + 1;
	A.second = lower.second;
	B.first = lower.first;
	B.second = lower.second;

	direction = 'D';

	while (1) {
		Swap(&map[A.first][A.second], &map[B.first][B.second]);

		if (A.first == lower.first && A.second == lower.second)
			break;

		B.first = A.first;
		B.second = A.second;

		if (B.first == height - 1 && B.second == 0) {
			direction = 'R';
		}
		else if (B.first == height - 1 && B.second == width - 1) {
			direction = 'U';
		}
		else if (B.first == lower.first && B.second == width - 1) {
			direction = 'L';
		}

		pair<int, int> newD = GetDhDw(direction);
		A.first = B.first + newD.first;
		A.second = B.second + newD.second;
	}

	map[lower.first][lower.second + 1] = 0;
};

int main() {
	cin >> height >> width >> T;

	bool flag = false;

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			cin >> map[h][w];
			if (map[h][w] == -1) {
				if (flag == false) {
					flag = true;
					upper.first = h;
					upper.second = w;
				}
				else {
					lower.first = h;
					lower.second = w;
				}
			}
		}
	}

	for (int t = 0; t < T; t++) {
		// 1. 미세먼지 확산
		DiffuseDust();
		// 2. 공기청정기 확산
		ActivateAirCleaner();
	}

	int cnt = 0;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			if (map[h][w] != -1)
				cnt += map[h][w];
		}
	}

	cout << cnt;

	return 0;
}
