#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 시작 row, col의 수는 1.

int row, col, sharkNum;

struct Shark {
	int row;
	int col;
	int speed;
	int dir; // 방향 -> 1은 위, 2는 아래, 3은 오른쪽, 4는 왼쪽.
	int size;
};

vector<Shark> sharks;

int sharkIndexMap[101][101];

// 디버그용.
void PrintSharks(){
	int sharkNewNum = sharks.size();
	for (int i = 0; i < sharkNewNum; i++) {
		cout << sharks[i].row << sharks[i].col << sharks[i].speed << sharks[i].dir << sharks[i].size;
	}
}

// 디버그 용.
void PrintSharkMap() {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j < col; j++) {
			cout << sharkIndexMap[i][j] << " ";
		}
		cout << endl;
	}
}

void HandleInput() {
	int sharkRow, sharkCol, sharkSpeed, sharkDirection, sharkSize;
	cin >> row >> col >> sharkNum;

	for (int i = 0; i < sharkNum; i++) {
		cin >> sharkRow >> sharkCol >> sharkSpeed >> sharkDirection >> sharkSize;
		sharks.push_back({ sharkRow, sharkCol, sharkSpeed, sharkDirection, sharkSize});
		sharkIndexMap[sharkRow][sharkCol] = i;
	}

	PrintSharkMap();
}

void CatchShark(int col) {
	int sharkNewNum = sharks.size();

	for (int i = 0; i < sharkNewNum; i++) {
		if (sharks[i].col == col) {
			cout << "Catch Shark Index " << i << endl;
		}
	}
}

void MoveEachSharks(int sharkIndex) {
	cout << "sharkIndex : " << sharkIndex << endl;

	cout << "Original Position : " << sharks[sharkIndex].row << ", " << sharks[sharkIndex].col << endl;

	for (int count = 0; count < sharks[sharkIndex].speed; count++) {
		if (sharks[sharkIndex].dir == 1) // 위.
		{
			sharks[sharkIndex].row--;
			if (sharks[sharkIndex].row < 1) {
				sharks[sharkIndex].dir = 2;
				sharks[sharkIndex].row += 2;
			}
		}
		else if (sharks[sharkIndex].dir == 2) // 아래
		{
			sharks[sharkIndex].row++;
			if (sharks[sharkIndex].row > row) {
				sharks[sharkIndex].dir = 1;
				sharks[sharkIndex].row -= 2;
			}
		}
		else if (sharks[sharkIndex].dir == 3) // 오른쪽
		{
			sharks[sharkIndex].col++;
			if (sharks[sharkIndex].col > col) {
				sharks[sharkIndex].dir = 4;
				sharks[sharkIndex].col -= 2;
			}
		}
		else if (sharks[sharkIndex].dir == 4) // 왼쪽
		{
			sharks[sharkIndex].col--;
			if (sharks[sharkIndex].col < 1) {
				sharks[sharkIndex].dir = 3;
				sharks[sharkIndex].col += 2;
			}
		}
		else {
			cout << "ERROR! #1" << endl;
		}
	}
	cout << "New Position : " << sharks[sharkIndex].row << ", " << sharks[sharkIndex].col << endl;
}

void MoveSharks() {
	int sharkNewNum = sharks.size();
	for (int i = 0; i < sharkNewNum; i++) {
		MoveEachSharks(i);
	}
}

void EatAllSharks() {
	int sharkNewNum = sharks.size();
	for (int i = 0; i < sharkNewNum; i++) {
		if (sharkIndexMap[sharks[i].row][sharks[i].col] != -1) {
			// 이미 어떤 상어가 있는 경우.
			int prevIndex = sharkIndexMap[sharks[i].row][sharks[i].col];
			if (sharks[i].size > sharks[prevIndex].size) {
				// 현재 고려중인 상어가 더 큰 경우.
				sharkIndexMap[sharks[i].row][sharks[i].col] = i;
			}
			else {
				// 이전 상어가 더 큰 경우.
				sharkIndexMap[sharks[i].row][sharks[i].col] = prevIndex;
			}
		}
		else {
			sharkIndexMap[sharks[i].row][sharks[i].col] = i;
		}
	}
}

void SetInitials() {
	memset(sharkIndexMap, -1, sizeof(sharkIndexMap));
}


void SolveProblem() {
	for (int fishingCol = 1; fishingCol <= col; fishingCol++) {
		//CatchShark(fishingCol);
		MoveSharks();
		//EatAllSharks();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	SetInitials();
	HandleInput();
	SolveProblem();

	return 0;
}
