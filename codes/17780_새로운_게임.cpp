#include <stdio.h>
#include <vector>

using namespace std;

int N, K;
int board[12][12];
vector<int> indexVectorBoard[12][12];
int turns;

int dR[5] = {0, 0, 0, -1, 1};
int dC[5] = {0, 1, -1, 0, 0};

struct piece{
	int row;
	int col;
	int dir; // 1 : 오른쪽, 2 : 왼쪽, 3 : 위, 4 : 아래.
};

vector<piece> pieces;
int piecesSize;

void InitializeValues(){
	turns = 0;
}

void HandleInput(){
	scanf("%d%d", &N, &K);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &board[i][j]);
		}
	}

	for(int i=0;i<K;i++){
		int row, col, dir;
		scanf("%d%d%d", &row, &col, &dir);
		pieces.push_back({row - 1, col - 1, dir});
		indexVectorBoard[row - 1][col - 1].push_back(i);
	}
}

void PrintDebugMessages(){
	printf("---------- TURN #%d ------------\n", turns);
	for(int i=0;i<piecesSize;i++){
		printf("#%d : (%d, %d) with direction %d\n", i, pieces[i].row, pieces[i].col, pieces[i].dir);
	}
	printf("----------------------\n");
}

int GetOppositeDirection(int dir){
	if(dir == 1)
		return 2;
	
	if(dir == 2)
		return 1;
	
	if(dir == 3)
		return 4;
	
	if(dir == 4)
		return 3;
	
	printf("ERROR #2\n");
	return 1;
}

bool CheckIfBlueOrOutOfBound(int row, int col){
	if(row < 0 || col < 0 || row >= N || col >= N){
		return true;
	}

	if(board[row][col] == 2){
		return true;
	}

	return false;
}

void SolveProblem(){
	piecesSize = pieces.size();

	while(turns <= 1000){
		turns++;
		//PrintDebugMessages();
		for(int pieceIndex = 0; pieceIndex < piecesSize; pieceIndex++){
			int currentRow = pieces[pieceIndex].row;
			int currentCol = pieces[pieceIndex].col;

			// 만약 현재 piece가 가장 아래에 있지 않는 경우 skip.
			if(indexVectorBoard[currentRow][currentCol][0] != pieceIndex)
				continue;
			
			int nextRow = currentRow + dR[pieces[pieceIndex].dir];
			int nextCol = currentCol + dC[pieces[pieceIndex].dir];

			if(CheckIfBlueOrOutOfBound(nextRow, nextCol)){
				// 체스판 밖으로 나가는 경우 또는 파란색 칸의 경우.

				// 방향 반대로 변경.
				pieces[pieceIndex].dir = GetOppositeDirection(pieces[pieceIndex].dir);

				nextRow = currentRow + dR[pieces[pieceIndex].dir];
				nextCol = currentCol + dC[pieces[pieceIndex].dir];

				if(CheckIfBlueOrOutOfBound(nextRow, nextCol))
					// 방향 변경 후 이동했을 때 이전과 같을 경우 부동.
					continue;
				else{
					// 판 밖으로 나가거나 파랑색 칸이 아닌 경우 다시 현재 말부터 재이동.
					pieceIndex--;
					continue;
				}
			}else if(board[nextRow][nextCol] == 0){
				// 흰색 칸으로 가는 경우,
				int currentStackSize = indexVectorBoard[currentRow][currentCol].size();

				for(int i=0;i<currentStackSize;i++){
					// 현재 칸 가장 아래에 위치한 말부터 차례대로 다음 칸 위로 이동.
					pieces[indexVectorBoard[currentRow][currentCol][i]].row = nextRow;
					pieces[indexVectorBoard[currentRow][currentCol][i]].col = nextCol;
					indexVectorBoard[nextRow][nextCol].push_back(indexVectorBoard[currentRow][currentCol][i]);
				}
				indexVectorBoard[currentRow][currentCol].clear();
			}else if(board[nextRow][nextCol] == 1){
				// 빨강색 칸으로 가는 경우,
				int currentStackSize = indexVectorBoard[currentRow][currentCol].size();

				for(int i=currentStackSize - 1;i>=0;i--){
					// 현재 칸 가장 위에 위치한 말부터 차례대로 다음 칸 위로 이동.
					pieces[indexVectorBoard[currentRow][currentCol][i]].row = nextRow;
					pieces[indexVectorBoard[currentRow][currentCol][i]].col = nextCol;
					indexVectorBoard[nextRow][nextCol].push_back(indexVectorBoard[currentRow][currentCol][i]);
				}
				indexVectorBoard[currentRow][currentCol].clear();
			}else{
				printf("ERROR #1\n");
			}
		}

		// 4 개 이상의 말이 쌓인 칸이 있는 경우 함수 종료.
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(indexVectorBoard[i][j].size() >= 4)
					return;
			}
		}	
	}

	turns = -1;
	return;
}

void PrintAnswer(){
	printf("%d\n", turns);
}

int main(){
	InitializeValues();
	HandleInput();
	SolveProblem();
	PrintAnswer();
	return 0;
}
