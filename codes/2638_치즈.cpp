#include <iostream>

using namespace std;

int dw[4] = {1, 0, -1, 0};
int dh[4] = {0, 1, 0, -1};

int height, width;
int map[100][100];
bool checkAirMap[100][100];

bool isCheeseLeft;

void GetMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}
}

void InitializeCheckMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			checkAirMap[i][j] = false;
		}
	}
}

void MarkOutsideAirDFS(int w, int h) {
	checkAirMap[h][w] = true;

	for (int i = 0; i < 4; i++) {
		int newH = h + dh[i];
		int newW = w + dw[i];

		if (newH < 0 || newH >= height || newW < 0 || newW >= width)
			continue;

		if (checkAirMap[newH][newW] == true || map[newH][newW] == 1)
			continue;

		MarkOutsideAirDFS(newW, newH);
	}
}

void MarkAllOutsideAir() {
	int direction = 0;
	int currW = 0, currH = 0;

	do {
		MarkOutsideAirDFS(currW, currH);

		if ((currW == width - 1 && currH == 0)
			|| (currW == width - 1 && currH == height - 1)
			|| (currW == 0 && currH == height - 1)) {
			direction += 1;
		}

		currW += dw[direction];
		currH += dh[direction];
	} while (!(currW == 0 && currH == 0));
}

void EraseCheese() {
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			int count = 0;
			if (map[i][j] == 1) {
				isCheeseLeft = true;

				for (int k = 0; k < 4; k++) {
					if (checkAirMap[i + dh[k]][j + dw[k]])
						count++;
				}

				if (count >= 2) {
					map[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	int cnt = 0;
	isCheeseLeft = true;

	cin >> height >> width;

	GetMap();

	while (isCheeseLeft) {
		isCheeseLeft = false;
		// 초기화.
		InitializeCheckMap();

		// 제거될 치즈 구분.
		MarkAllOutsideAir();
	
		// 치즈 제거
		EraseCheese();
		cnt += 1;
	}

	cout << cnt - 1;

	return 0;
}
