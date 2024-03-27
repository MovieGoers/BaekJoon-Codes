#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int mapHeight, mapWidth;
int minBlindSpot;

struct Map {
	int map[8][8];
};

stack<Map> mapStack;

Map originalMap;

struct CCTV {
	int row;
	int col;
	int type; // 1 ~ 5;
	int numOfCases; // 각 CCTV마다 달라지는 회전 경우의 수.
};

vector<CCTV> cctvs;

int GetNumberOfCases(int type) {
	switch (type) {
	case 1:
		return 4;
	case 2:
		return 2;
	case 3:
		return 4;
	case 4:
		return 4;
	case 5:
		return 1;
	default:
		return 1;
	}
}

void DrawMapLeft(Map& map, int cctvRow, int cctvCol) {
	int pos = cctvCol - 1;
	while (true) {
		// 맵 밖.
		if (pos < 0)
			break;

		// 벽.
		if (map.map[cctvRow][pos] == 6)
			break;

		// 아직 CCTV가 칠해지지 않은 곳.
		if (map.map[cctvRow][pos] == 0)
			map.map[cctvRow][pos] = 7;

		pos--;
	}
};

void DrawMapRight(Map& map, int cctvRow, int cctvCol) {
	// 우측 방향.
	int pos = cctvCol + 1;
	while (true) {
		// 맵 밖.
		if (pos >= mapWidth)
			break;

		// 벽.
		if (map.map[cctvRow][pos] == 6)
			break;

		// 아직 CCTV가 칠해지지 않은 곳.
		if (map.map[cctvRow][pos] == 0)
			map.map[cctvRow][pos] = 7;

		pos++;
	}
};

void DrawMapUp(Map& map, int cctvRow, int cctvCol) {
	// 윗 방향.
	int pos = cctvRow - 1;
	while (true) {
		// 맵 밖.
		if (pos < 0)
			break;

		// 벽.
		if (map.map[pos][cctvCol] == 6)
			break;

		// 아직 CCTV가 칠해지지 않은 곳.
		if (map.map[pos][cctvCol] == 0)
			map.map[pos][cctvCol] = 7;

		pos--;
	}
};

void DrawMapDown(Map& map, int cctvRow, int cctvCol) {
	// 아래 방향.
	int pos = cctvRow + 1;
	while (true) {
		// 맵 밖.
		if (pos >= mapHeight)
			break;

		// 벽.
		if (map.map[pos][cctvCol] == 6)
			break;

		// 아직 CCTV가 칠해지지 않은 곳.
		if (map.map[pos][cctvCol] == 0)
			map.map[pos][cctvCol] = 7;

		pos++;
	}
};

void DrawMap(int cctvIndex, int caseIndex, Map &map) {
	CCTV cctvNow = cctvs[cctvIndex];
	int pos;

	switch (cctvNow.type) {
	// CCTV 1번.
	case 1:
		switch (caseIndex) {
		case 0:
			// 우측 방향.
			DrawMapRight(map, cctvNow.row, cctvNow.col);
			break;
		case 1:
			// 윗 방향.
			DrawMapUp(map, cctvNow.row, cctvNow.col);
			break;
		case 2:
			// 좌측 방향.
			DrawMapLeft(map, cctvNow.row, cctvNow.col);
			break;
		case 3:
			// 아래 방향.
			DrawMapDown(map, cctvNow.row, cctvNow.col);
			break;
		}
		break;
	
	// CCTV 2번
	case 2:
		switch (caseIndex) {
		// 좌우.
		case 0:
			DrawMapLeft(map, cctvNow.row, cctvNow.col);
			DrawMapRight(map, cctvNow.row, cctvNow.col);
			break;
		// 위, 아래
		case 1:
			DrawMapUp(map, cctvNow.row, cctvNow.col);
			DrawMapDown(map, cctvNow.row, cctvNow.col);
			break;
		}
		break;

	// CCTV 3번
	case 3:
		switch (caseIndex) {
		case 0:
			DrawMapUp(map, cctvNow.row, cctvNow.col);
			DrawMapRight(map, cctvNow.row, cctvNow.col);
			break;
		case 1:
			DrawMapDown(map, cctvNow.row, cctvNow.col);
			DrawMapRight(map, cctvNow.row, cctvNow.col);
			break;
		case 2:
			DrawMapDown(map, cctvNow.row, cctvNow.col);
			DrawMapLeft(map, cctvNow.row, cctvNow.col);
			break;
		case 3:
			DrawMapUp(map, cctvNow.row, cctvNow.col);
			DrawMapLeft(map, cctvNow.row, cctvNow.col);
			break;
		}
		break;
	
	//CCTV 4번
	case 4:
		switch (caseIndex) {
		case 0:
			DrawMapDown(map, cctvNow.row, cctvNow.col);
			DrawMapLeft(map, cctvNow.row, cctvNow.col);
			DrawMapRight(map, cctvNow.row, cctvNow.col);
			break;
		case 1:
			DrawMapUp(map, cctvNow.row, cctvNow.col);
			DrawMapLeft(map, cctvNow.row, cctvNow.col);
			DrawMapRight(map, cctvNow.row, cctvNow.col);
			break;
		case 2:
			DrawMapUp(map, cctvNow.row, cctvNow.col);
			DrawMapDown(map, cctvNow.row, cctvNow.col);
			DrawMapRight(map, cctvNow.row, cctvNow.col);
			break;
		case 3:
			DrawMapUp(map, cctvNow.row, cctvNow.col);
			DrawMapDown(map, cctvNow.row, cctvNow.col);
			DrawMapLeft(map, cctvNow.row, cctvNow.col);
			break;
		}
		break;

	//CCTV 5번
	case 5:
		DrawMapUp(map, cctvNow.row, cctvNow.col);
		DrawMapDown(map, cctvNow.row, cctvNow.col);
		DrawMapLeft(map, cctvNow.row, cctvNow.col);
		DrawMapRight(map, cctvNow.row, cctvNow.col);
		break;
	}
}

void PrintMap(Map map) {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			printf("%d ", map.map[i][j]);
		}
		printf("\n");
	}
}

int GetBlindSpotNumber(Map map) {
	int cnt = 0;
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map.map[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void DFS(int cctvIndex) {
	if (cctvIndex == cctvs.size()) {
		Map finalMap = mapStack.top();
		int blindSpotsNumber = GetBlindSpotNumber(finalMap);

		if (blindSpotsNumber < minBlindSpot) {
			minBlindSpot = blindSpotsNumber;
		}
		return;
	}

	for (int caseIndex = 0; caseIndex < cctvs[cctvIndex].numOfCases; caseIndex++) {
		// 스택에서 map 꺼내고 =새로운 cctv과 방향에 맞게 그린다.
		Map newMap = mapStack.top();
		DrawMap(cctvIndex, caseIndex, newMap);
		// 스택에 push
		mapStack.push(newMap);

		// DFS
		DFS(cctvIndex + 1);

		// 스택 pop.
		mapStack.pop();
	}
};

int main() {
	minBlindSpot = 999;

	scanf("%d %d", &mapHeight, &mapWidth);

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			scanf("%d", &originalMap.map[i][j]);
			
			if (1 <= originalMap.map[i][j] && 5 >= originalMap.map[i][j]) {
				CCTV newCCTV;
				newCCTV.row = i;
				newCCTV.col = j;
				newCCTV.type = originalMap.map[i][j];
				newCCTV.numOfCases = GetNumberOfCases(newCCTV.type);

				cctvs.push_back(newCCTV);
			}
		}
	}
	mapStack.push(originalMap);

	DFS(0);

	printf("%d", minBlindSpot);

	return 0;
}
