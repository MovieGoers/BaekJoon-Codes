#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>

#define INTMAX 9999999

using namespace std;

int mapWidth, mapHeight;
char map[10][10];
int minCnt;

int holeH, holeW;

struct Points {
	int redH;
	int redW;
	int blueH;
	int blueW;
	int movedCnt;
	char prevAction; // 이전에 기울인 값, L, R, U, D, X (X는 초깃값.)
};

bool IsBlueInHole(Points points) {
	if (points.blueH == holeH && points.blueW == holeW)
		return true;

	return false;
};

bool IsRedInHole(Points points) {
	if (points.redH == holeH && points.redW == holeW)
		return true;

	return false;
};

// 현재 Points, 기울이는 방향 받고 새롭게 이동된 Points 생성, 반환.
Points MakeNewPoints(Points currentPoints, char direction) {
	int dH = 0;
	int dW = 0;

	int newRedH = currentPoints.redH;
	int newRedW = currentPoints.redW;
	int newBlueH = currentPoints.blueH;
	int newBlueW = currentPoints.blueW;

	// 이동할 방향 대해 더해줄 값 지정.
	if (direction == 'L') {
		dW = -1;
	}
	else if (direction == 'R') {
		dW = 1;
	}
	else if (direction == 'U') {
		dH = -1;
	}
	else if (direction == 'D') {
		dH = 1;
	}
	// 파란 구슬 이동.
	do {
		newBlueH += dH;
		newBlueW += dW;

		// 새롭게 이동한 파란 구슬이 벽 또는 빨간 구슬에 있는 경우, 그전 위치로 이동 후 종료.
		if (map[newBlueH][newBlueW] == '#' || (newBlueH == newRedH && newBlueW == newRedW)) {
			newBlueH -= dH;
			newBlueW -= dW;
			break;
		}

		// 파란 구슬이 구멍에 들어가는 경우 그 자리에서 종료.
		if (map[newBlueH][newBlueW] == 'O') {
			currentPoints.blueH = newBlueH;
			currentPoints.blueW = newBlueW;
			currentPoints.movedCnt += 1;
			currentPoints.prevAction = direction;
			return currentPoints;
		}
	} while (1);

	bool isRedIn = false;

	// 빨간 구슬 이동.
	do {
		newRedH += dH;
		newRedW += dW;

		if (map[newRedH][newRedW] == '#' || (newBlueH == newRedH && newBlueW == newRedW)) {
			newRedH -= dH;
			newRedW -= dW;
			break;
		}

		if (map[newRedH][newRedW] == 'O') {
			isRedIn = true;
			break;
		}
	} while (1);

	// 다시 파란 구슬 이동.
	do {
		newBlueH += dH;
		newBlueW += dW;

		// 새롭게 이동한 파란 구슬이 벽 또는 빨간 구슬에 있는 경우, 그전 위치로 이동 후 종료.
		if (map[newBlueH][newBlueW] == '#') {
			newBlueH -= dH;
			newBlueW -= dW;
			break;
		}

		if ((newBlueH == newRedH && newBlueW == newRedW)) {
			if (!isRedIn) {
				newBlueH -= dH;
				newBlueW -= dW;
				break;
			}
		}

		// 파란 구슬이 구멍에 들어가는 경우 그 자리에서 종료.
		if (map[newBlueH][newBlueW] == 'O') {
			break;
		}
	} while (1);

	currentPoints.blueH = newBlueH;
	currentPoints.blueW = newBlueW;
	currentPoints.redH = newRedH;
	currentPoints.redW = newRedW;
	currentPoints.movedCnt += 1;
	currentPoints.prevAction = direction;
	return currentPoints;
};

void DoDFS(Points initPoints) {
	queue<Points> pointsQ;
	bool isAnswerFound = false;

	pointsQ.push(initPoints);

	while (!pointsQ.empty()) {
		// 1. 큐 Pop.
		Points currentPoints = pointsQ.front();
		pointsQ.pop();

		// 2. 조건 만족하는 지 파악 (빨간 구슬이 구멍에 들어갔는지 등)

		// 만약 이동 횟수가 10번 이상이라면 더이상 탐색 안함. (구현 필요.)
		if (currentPoints.movedCnt > 10)
			continue;

		if (IsBlueInHole(currentPoints))
			continue;

		if (IsRedInHole(currentPoints)) {
			// 최소 이동 거리인지 확인 및 업데이트.
			if (currentPoints.movedCnt < minCnt) {
				minCnt = currentPoints.movedCnt;
			}
			break;
		}

		// 3. 다음 기울인 경우들 생성 및 큐 Push.
		if (currentPoints.prevAction == 'L' || currentPoints.prevAction == 'R') {
			pointsQ.push(MakeNewPoints(currentPoints, 'U'));
			pointsQ.push(MakeNewPoints(currentPoints, 'D'));
		}
		else if (currentPoints.prevAction == 'U' || currentPoints.prevAction == 'D') {
			pointsQ.push(MakeNewPoints(currentPoints, 'L'));
			pointsQ.push(MakeNewPoints(currentPoints, 'R'));
		}
		else {
			pointsQ.push(MakeNewPoints(currentPoints, 'U'));
			pointsQ.push(MakeNewPoints(currentPoints, 'D'));
			pointsQ.push(MakeNewPoints(currentPoints, 'L'));
			pointsQ.push(MakeNewPoints(currentPoints, 'R'));
		}
	}
}

int main() {
	minCnt = INTMAX;

	scanf("%d %d", &mapHeight, &mapWidth);

	int initRedH, initRedW, initBlueH, initBlueW;

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] == 'R') {
				initRedH = i;
				initRedW = j;
			}
			else if (map[i][j] == 'B') {
				initBlueH = i;
				initBlueW = j;
			}
			else if (map[i][j] == 'O') {
				holeH = i;
				holeW = j;
			}
		}
	}

	Points initPoints = { initRedH, initRedW, initBlueH, initBlueW, 0, 'X' };

	DoDFS(initPoints);

	if (minCnt != INTMAX)
		printf("%d", minCnt);
	else
		printf("-1");

	return 0;
}
