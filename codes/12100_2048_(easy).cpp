#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>

using namespace std;

int boardSize;
int maxScore;

struct State {
	int board[20][20];
	int moveCount;
};

State initState;

State MakeNextState(State currentState, char nextDirection) {
	State nextState;

	for (int h = 0; h < boardSize; h++) {
		for (int w = 0; w < boardSize; w++) {
			nextState.board[h][w] = 0;
		}
	}
	
	if(nextDirection == 'L')
		for (int h = 0; h < boardSize; h++) {
			int currentValue = 0;
			int currentIndex = 0;
			for (int w = 0; w < boardSize; w++) {
				if (currentState.board[h][w] != 0) {
					if (currentValue == currentState.board[h][w]) {
						nextState.board[h][currentIndex] = currentValue * 2;
						currentIndex++;
						currentValue = 0;
					}
					else {
						if (currentValue == 0)
							currentValue = currentState.board[h][w];
						else {
							nextState.board[h][currentIndex] = currentValue;
							currentIndex++;
							currentValue = currentState.board[h][w];
						}
					}
				}
			}
			nextState.board[h][currentIndex] = currentValue;
		}
	else if(nextDirection == 'R')
		for (int h = 0; h < boardSize; h++) {
			int currentValue = 0;
			int currentIndex = boardSize - 1;
			for (int w = boardSize - 1; w >= 0; w--) {
				if (currentState.board[h][w] != 0) {
					if (currentValue == currentState.board[h][w]) {
						nextState.board[h][currentIndex] = currentValue * 2;
						currentIndex--;
						currentValue = 0;
					}
					else {
						if (currentValue == 0)
							currentValue = currentState.board[h][w];
						else {
							nextState.board[h][currentIndex] = currentValue;
							currentIndex--;
							currentValue = currentState.board[h][w];
						}
					}
				}
			}
			nextState.board[h][currentIndex] = currentValue;
		}
	else if(nextDirection == 'U')
		for (int w = 0; w < boardSize; w++) {
			int currentValue = 0;
			int currentIndex = 0;
			for (int h = 0; h < boardSize; h++) {
				if (currentState.board[h][w] != 0) {
					if (currentValue == currentState.board[h][w]) {
						nextState.board[currentIndex][w] = currentValue * 2;
						currentIndex++;
						currentValue = 0;
					}
					else {
						if (currentValue == 0)
							currentValue = currentState.board[h][w];
						else {
							nextState.board[currentIndex][w] = currentValue;
							currentIndex++;
							currentValue = currentState.board[h][w];
						}
					}
				}
			}
			nextState.board[currentIndex][w] = currentValue;
		}
	else if(nextDirection == 'D')
		for (int w = 0; w < boardSize; w++) {
			int currentValue = 0;
			int currentIndex = boardSize - 1;
			for (int h = boardSize - 1; h >= 0; h--) {
				if (currentState.board[h][w] != 0) {
					if (currentValue == currentState.board[h][w]) {
						nextState.board[currentIndex][w] = currentValue * 2;
						currentIndex--;
						currentValue = 0;
					}
					else {
						if (currentValue == 0)
							currentValue = currentState.board[h][w];
						else {
							nextState.board[currentIndex][w] = currentValue;
							currentIndex--;
							currentValue = currentState.board[h][w];
						}
					}
				}
			}
			nextState.board[currentIndex][w] = currentValue;
		}
	nextState.moveCount = currentState.moveCount + 1;

	return nextState;
};

int GetMaxScore(State state) {
	int max = -1;

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (max < state.board[i][j])
				max = state.board[i][j];
		}
	}

	return max;
};

void DoBFS() {
	queue<State> stateQueue;
	
	stateQueue.push(initState);

	while (!stateQueue.empty()) {
		// 1. State 큐에서 Pop
		State currentState = stateQueue.front();
		stateQueue.pop();

		//for (int h = 0; h < boardSize; h++) {
		//	for (int w = 0; w < boardSize; w++) {
		//		printf("%d ", currentState.board[h][w]);
		//	}
		//	printf("\n");
		//}


		// 2. 현재 고려중인 State의 최대 점수 계산.
		if (currentState.moveCount == 5) {
			int score = GetMaxScore(currentState);

			if (score > maxScore)
				maxScore = score;
			// 최대 점수 구하기.
			continue;
		}


		// 3. 다음 State 생성 및 큐에 집어넣기.
		stateQueue.push(MakeNextState(currentState, 'L'));
		stateQueue.push(MakeNextState(currentState, 'R'));
		stateQueue.push(MakeNextState(currentState, 'U'));
		stateQueue.push(MakeNextState(currentState, 'D'));
	}
}

int main() {
	scanf("%d", &boardSize);

	maxScore = -1;

	for (int h = 0; h < boardSize; h++) {
		for (int w = 0; w < boardSize; w++) {
			scanf("%d", &initState.board[h][w]);
		}
	}
	initState.moveCount = 0;

	DoBFS();

	printf("%d", maxScore);

	return 0;
}
