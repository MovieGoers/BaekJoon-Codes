#include <stdio.h>
#include <utility>

using namespace std;
int N;
char map[1001][1001];

pair<int, int> ReturnHeartPosition(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(map[i][j] == '*'){
				return {i + 1, j};
			}
		}
	}

	return {-1, -1};
}

int main(){	
	scanf("%d", &N);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf(" %c", &map[i][j]);
		}
	}

	pair<int, int> heartPosition = ReturnHeartPosition();

	int leftArm = 0, rightArm = 0, body = 0, leftLeg = 0, rightLeg = 0;

	int currentRow = heartPosition.first, currentCol = heartPosition.second - 1;

	// leftArm
	while(currentCol >= 1 && map[heartPosition.first][currentCol] == '*'){
		leftArm++;
		currentCol--;
	}

	// right Arm
	currentCol = heartPosition.second + 1;
	while(currentCol <= N && map[heartPosition.first][currentCol] == '*'){
		rightArm++;
		currentCol++;
	}

	// body
	currentRow = heartPosition.first + 1;
	currentCol = heartPosition.second;
	while(currentRow <= N && map[currentRow][currentCol] == '*'){
		body++;
		currentRow++;
	}

	int bodyRow = currentRow;

	// leftLeg
	while(currentRow <= N && map[currentRow][currentCol - 1] == '*'){
		leftLeg++;
		currentRow++;
	}

	// rightLeg
	currentRow = bodyRow;
	while(currentRow <= N && map[currentRow][currentCol + 1] == '*'){
		rightLeg++;
		currentRow++;
	}

	printf("%d %d\n%d %d %d %d %d\n", heartPosition.first, heartPosition.second, leftArm, rightArm, body, leftLeg, rightLeg);

	return 0;
}
