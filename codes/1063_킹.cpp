#include <iostream>
#include <utility>
#include <string>

using namespace std;

string initialKingPosition, initialStonePosition;
string moveList[50];
int N;

pair<int, int> kingPosition, stonePosition;

void HandleInput(){
	cin >> initialKingPosition >> initialStonePosition >> N;

	for(int i=0;i<N;i++){
		cin >> moveList[i];
	}
}

pair<int, int> GetDiff(string move){
	int row = 0;
	int col = 0;

	for(int i=0;i<move.size();i++){
		if(move[i] == 'R')
			col++;
		if(move[i] == 'L')
			col--;
		if(move[i] == 'B')
			row++;
		if(move[i] == 'T')
			row--;
	}
	
	return {row, col};
}

pair<int, int> GetNextPosition(pair<int, int> currentPosition, string move){
	pair<int, int> diff = GetDiff(move);
	return {currentPosition.first + diff.first, currentPosition.second + diff.second};
}

void MoveKing(string move){
	pair<int, int> nextKingPosition = GetNextPosition(kingPosition, move);
	pair<int, int> nextStonePosition = {0, 0};
	bool didStoneMove = false;

	if(nextKingPosition.first == stonePosition.first && nextKingPosition.second == stonePosition.second){
		nextStonePosition = GetNextPosition(stonePosition, move);
		didStoneMove = true;
	}
		
	if(nextStonePosition.first < 0 || nextStonePosition.second < 0 || nextStonePosition.first >= 8 || nextStonePosition.second >= 8)
		return;

	if(nextKingPosition.first < 0 || nextKingPosition.second < 0 || nextKingPosition.first >= 8 || nextKingPosition.second >= 8)
		return;
	
	if(didStoneMove){
		stonePosition.first = nextStonePosition.first;
		stonePosition.second = nextStonePosition.second;
	}

	kingPosition.first = nextKingPosition.first;
	kingPosition.second = nextKingPosition.second;
}

void PrintPositions(){
	cout << char('A' + kingPosition.second) << 8-kingPosition.first <<'\n';
	cout << char('A' + stonePosition.second) << 8-stonePosition.first; 
}

void TranslatePositions(){
	kingPosition.first = 8 - (initialKingPosition[1] - '0');
	kingPosition.second = initialKingPosition[0] - 'A';

	stonePosition.first = 8 - (initialStonePosition[1] - '0');
	stonePosition.second = initialStonePosition[0] - 'A';
}

void PrintDebug(){
	cout << "King Position : (" << kingPosition.first << " , " << kingPosition.second << ")\n";
	cout << "StonePosition : (" << stonePosition.first << " , " << stonePosition.second << ")\n";
}

int main(){
	HandleInput();

	TranslatePositions();
	for(int i=0;i<N;i++){
		MoveKing(moveList[i]);
		//PrintDebug();
	}

	PrintPositions();

	return 0;
}
