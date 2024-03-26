#include <stdio.h>
#include <memory.h>

using namespace std;

int mapSize, runwaySize;
int map[100][100];
int runwayCnt;

int main() {
	runwayCnt = 0;

	scanf("%d%d", &mapSize, &runwaySize);

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int row = 0; row < mapSize; row++) {
		bool isAbleToCross = true;
		bool runway[100];
		memset(runway, false, sizeof(runway));

		for (int col = 0; col < mapSize - 1; col++) {
			// 두 지점 높이의 차가 2 이상인 경우.
			if (map[row][col] > map[row][col + 1] + 1 || map[row][col] + 1 < map[row][col + 1]) {
				isAbleToCross = false;
				break;
			}

			if (map[row][col] == map[row][col + 1] + 1) {
				// 경사로 가능한지 확인.
				int runwayHeight = map[row][col + 1];

				// 경사로가 맵 밖으로 나가는 경우.
				if (col + runwaySize >= mapSize) {
					isAbleToCross = false;
					break;
				}

				for (int len = 1; len <= runwaySize; len++) {
					// 이미 다른 경사로가 있는 경우.
					if (runway[col + len] == true)
						isAbleToCross = false;

					if (map[row][col + len] != runwayHeight)
						isAbleToCross = false;
				}

				if (isAbleToCross == false)
					break;

				for (int len = 1; len <= runwaySize; len++) {
					runway[col + len] = true;
				}
			}

			if (map[row][col] + 1== map[row][col + 1]) {
				// 경사로 가능한지 확인.
				int runwayHeight = map[row][col];

				// 경사로가 맵 밖으로 나가는 경우.
				if (col - runwaySize + 1 < 0) {
					isAbleToCross = false;
					break;
				}

				for (int len = 1; len <= runwaySize; len++) {
					// 이미 다른 경사로가 있는 경우.
					if (runway[col - len + 1] == true)
						isAbleToCross = false;

					if (map[row][col - len + 1] != runwayHeight)
						isAbleToCross = false;
				}

				if (isAbleToCross == false) {
					break;
				}
				for (int len = 1; len <= runwaySize; len++) {
					runway[col - len + 1] = true;
				}
			}
		}
		if(isAbleToCross)
			runwayCnt += 1;
	}

	for (int col = 0; col < mapSize; col++) {
		bool isAbleToCross = true;
		bool runway[100];
		memset(runway, false, sizeof(runway));

		for (int row = 0; row < mapSize - 1; row++) {
			// 두 지점 높이의 차가 2 이상인 경우.
			if (map[row][col] > map[row + 1][col] + 1 || map[row][col] + 1 < map[row + 1][col]) {
				isAbleToCross = false;
				break;
			}

			if (map[row][col] == map[row + 1][col] + 1) {
				// 경사로 가능한지 확인.
				int runwayHeight = map[row + 1][col];

				// 경사로가 맵 밖으로 나가는 경우.
				if (row + runwaySize >= mapSize) {
					isAbleToCross = false;
					break;
				}

				for (int len = 1; len <= runwaySize; len++) {
					// 이미 다른 경사로가 있는 경우.
					if (runway[row + len] == true)
						isAbleToCross = false;

					if (map[row + len][col] != runwayHeight)
						isAbleToCross = false;
				}

				if (isAbleToCross == false)
					break;

				for (int len = 1; len <= runwaySize; len++) {
					runway[row + len] = true;
				}
			}

			if (map[row][col] + 1 == map[row + 1][col]) {
				// 경사로 가능한지 확인.
				int runwayHeight = map[row][col];

				// 경사로가 맵 밖으로 나가는 경우.
				if (row - runwaySize + 1 < 0) {
					isAbleToCross = false;
					break;
				}

				for (int len = 1; len <= runwaySize; len++) {
					// 이미 다른 경사로가 있는 경우.
					if (runway[row - len + 1] == true)
						isAbleToCross = false;

					if (map[row - len + 1][col] != runwayHeight)
						isAbleToCross = false;
				}

				if (isAbleToCross == false) {
					break;
				}
				for (int len = 1; len <= runwaySize; len++) {
					runway[row - len + 1] = true;
				}
			}
		}

		if (isAbleToCross)
			runwayCnt += 1;
	}

	printf("%d", runwayCnt);
	return 0;
}
