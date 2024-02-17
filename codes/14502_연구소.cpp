#include <iostream>
#include <vector>

using namespace std;

int height, width;

int map[8][8];
bool checked[8][8];

int dh[4] = { -1, 1, 0, 0 };
int dw[4] = { 0, 0, -1, 1 };

vector<vector<int>> newThreeWalls;
int currentTestCaseIndex;

void ResetChecked() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			checked[i][j] = false;
		}
	}
};

void DFS(int h, int w) {
	checked[h][w] = true;

	for (int i = 0; i < 4; i++) {
		int newHeight = h + dh[i];
		int newWidth = w + dw[i];

		if (newHeight < 0 || newHeight >= height || newWidth < 0 || newWidth >= width)
			continue;

		if (map[newHeight][newWidth] != 0 || checked[newHeight][newWidth] == true)
			continue;

		int conversionToIndex = newHeight * width + newWidth;

		if (conversionToIndex == newThreeWalls[currentTestCaseIndex][0])
			continue;

		if (conversionToIndex == newThreeWalls[currentTestCaseIndex][1])
			continue;

		if (conversionToIndex == newThreeWalls[currentTestCaseIndex][2])
			continue;

		DFS(newHeight, newWidth);
	}
}

int main() {
	int max = 0;
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	// 벽 3개 생성 가능한 모든 경우의 수 생성 및 관련 데이터 만들기.

	for (int i = 0; i < height * width; i++) {
		if(map[i/ width][i% width] == 0)
			for (int j = i + 1; j < height * width; j++) {
				if (map[j / width][j % width] == 0)
					for (int k = j + 1; k < height * width; k++) {
						if (map[k / width][k % width] == 0) {
							vector<int> newVec;
							newVec.push_back(i);
							newVec.push_back(j);
							newVec.push_back(k);
							newThreeWalls.push_back(newVec);
						}
					}
			}
	}

	int casesSize = newThreeWalls.size();

	// while 모든 테스트
	for (int i = 0; i < casesSize; i++) {
		// 0. 모든 테스트 환경 초기화.
		ResetChecked();
		currentTestCaseIndex = i;
		int safeAreaSize = 0;
		
		// 1. DFS
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				if (map[j][k] == 2) {
					DFS(j, k);
				}
			}
		}

		// 2. 안전 영역 구하기.
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				if (checked[j][k] == false && map[j][k] == 0) {
					int conversionToIndex = j * width + k;
					if(newThreeWalls[i][0] != conversionToIndex 
						&& newThreeWalls[i][1] != conversionToIndex 
						&& newThreeWalls[i][2] != conversionToIndex)
						++safeAreaSize;
				}
			}
		}
		// 3. 구한 안전 영역 수와 max 비교 및 업데이트.
		if (max < safeAreaSize) {
			max = safeAreaSize;
		}

	}

	// max 출력.
	cout << max;
	return 0;
}
