#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int map[500][500];
int height, width;
int sum;
int subSum = 0;

int dw[4] = { -1, 1, 0, 0 };
int dh[4] = { 0, 0, -1, 1 };

bool checked[500][500] = { false, };

void ResetChecked() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			checked[i][j] = false;
		}
	}
}

void DFS(int h, int w, int tsum, int cnt) {
	if (cnt >= 4) {
		if (sum < tsum)
			sum = tsum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int newH = h + dh[i];
		int newW = w + dw[i];

		if (newH < 0 || newH >= height || newW < 0 || newW >= width)
			continue;

		if (checked[newH][newW])
			continue;

		checked[newH][newW] = true;
		DFS(newH, newW, tsum + map[newH][newW], cnt + 1);
		checked[newH][newW] = false;
	}
}

int main() {
	scanf("%d%d", &height, &width);

	sum = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			memset(checked, 0, sizeof(checked));
			checked[i][j] = true;
			DFS(i, j, map[i][j], 1);
		}
	}

	// ㅏ, ㅓ 모양 계산
	for (int i = 0; i <= height - 3; i++) {
		for (int j = 0; j <= width - 2; j++) {
			subSum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];

			if (subSum > sum)
				sum = subSum;

			subSum = map[i][j+1] + map[i + 1][j+1] + map[i + 2][j+1] + map[i+1][j];

			if (subSum > sum)
				sum = subSum;
		}
	}

	// ㅗ, ㅜ 모양 계산
	for (int i = 0; i <= height - 2; i++) {
		for (int j = 0; j <= width - 3; j++) {
			subSum = map[i+1][j] + map[i + 1][j+1] + map[i + 1][j+2] + map[i][j + 1];

			if (subSum > sum)
				sum = subSum;

			subSum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j+1];

			if (subSum > sum)
				sum = subSum;
		}
	}

	printf("%d\n", sum);

	return 0;
}
