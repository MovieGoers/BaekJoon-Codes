#include <stdio.h>
#include <memory.h>
#include <math.h>

using namespace std;

bool map[101][101];

int dragonSequence[1024]; // 오른쪽 0, 위 1, 왼쪽 2, 아래 3 방향. 시작하는 방향은 오른쪽으로 가는 것을 기준.

void GenerateDragonSequence(int length) {
	if (length == 1024)
		return;

	for (int i = 0; i < length; i++) {
		dragonSequence[length * 2 - i - 1] = (dragonSequence[i] + 1) % 4;
	}

	GenerateDragonSequence(length * 2);
};

void DrawDragonSequence(int x, int y, int direction, int gen) {
	int length = pow(2, gen);

	map[x][y] = true;
	int newX = x;
	int newY = y;

	for (int i = 0; i < length; i++) {
		switch ((dragonSequence[i] + direction) % 4) {
		case 0:
			// 오른쪽 방향.
			newX++;
			break;
		case 1:
			// 윗쪽 방향.
			newY--;
			break;
		case 2:
			newX--;
			break;
		case 3:
			newY++;
			break;
		}
		map[newX][newY] = true;
	}
}

void CountSquares(int *count) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				*count += 1;
		}
	}
}

int main() {
	int N;
	int count = 0;

	scanf("%d", &N);

	memset(map, false, sizeof(map));
	GenerateDragonSequence(1);

	for (int i = 0; i < N; i++) {
		int x, y, d, g;

		scanf("%d%d%d%d", &x, &y, &d, &g);
		DrawDragonSequence(x, y, d, g);
	}

	CountSquares(&count);

	printf("%d", count);
	
	return 0;
}
