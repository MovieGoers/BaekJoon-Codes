// 미완성 코드!!!!!!!!!

#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

int N, K;

int map[14][14];
vector<int> indexVectorMap[14][14];

int dR[5] = {0, 0, 0, -1, 1};
int dC[5] = {0, 1, -1, 0, 0};

struct Piece{
	int row;
	int col;
	int dir; // 1 : right, 2 : left, 3 : up, 4 : down.
};

vector<Piece> pieces;

void HandleInput(){
	scanf("%d%d", &N, &K);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int i=0;i<K;i++){
		int row, col, dir;
		scanf("%d%d%d", &row, &col, &dir);

		indexVectorMap[row][col].push_back(i);
		pieces.push_back({row, col, dir});
	}
}

void MoveSinglePiece(Piece & piece){
	int newRow, newCol;

	newRow = piece.row + dR[piece.dir];
	newCol = piece.col + dC[piece.dir];

	if(map[newRow][newCol] == 0){
		piece.row = newRow;
		piece.col = newCol;

		for(auto & upper)
	}
}

void MoveEveryPieces(){
	for(auto & piece : pieces){
		MoveSinglePiece(piece);
	}
}

bool CheckCondition(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(indexVectorMap[i][j].size() >= 4)
				return true;
		}
	}

	return false;
}

int main(){
	memset(map, 2, sizeof(map));

	HandleInput();

	for(int turn = 1;turn <= 1000;turn++){
		MoveEveryPieces();

		if(CheckCondition()){
			printf("%d", turn);
			return 0;
		}
	}

	printf("-1");

	return 0;
}
