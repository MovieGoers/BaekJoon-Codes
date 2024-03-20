#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <deque>
#include <unordered_map>
#include <utility>

using namespace std;

pair<int, int> GetNextHeadPosition(pair<int, int> head, char direction) {
	pair<int, int> nextPos;
	nextPos = { head.first, head.second };

	switch (direction) {
	case 'L':
		nextPos.second--;
		break;
	case 'R':
		nextPos.second++;
		break;
	case 'U':
		nextPos.first--;
		break;
	case 'D':
		nextPos.first++;
		break;
	default:
		break;
	}

	return nextPos;
}

bool IsBodyContacted(deque<pair<int, int>> snake) {
	pair<int, int> head = snake.front();

	int contactCnt = 0;

	for (auto& elem : snake) {
		if (elem.first == head.first && elem.second == head.second) {
			contactCnt++;
			if (contactCnt == 2) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int boardSize, appleSize, commandSize;
	bool apples[101][101] = { false, };
	
	unordered_map<int, char> commands; // commands[3] = 'L' -> 3초가 끝난 뒤 왼쪽으로 방향 회전.
	deque<pair<int, int>> snake;

	int currentTime = 0;
	pair<int, int> head = { 1, 1 };
	char movement = 'R'; // L, R, U, D;
	snake.push_back({ 1, 1 });

	scanf("%d", &boardSize);
	scanf("%d", &appleSize);

	for (int i = 0; i < appleSize; i++) {
		int appleRow, appleCol;
		scanf("%d%d", &appleRow, &appleCol);
		apples[appleRow][appleCol] = true;
	}

	scanf("%d", &commandSize);

	for (int i = 0; i < commandSize; i++) {
		int time;
		char direction;
		scanf("%d %c", &time, &direction);
		commands[time] = direction;
	}

	bool isGameOver = false;
	while (!isGameOver) {
		currentTime++;

		// 1. 몸 길이를 늘려 머리를 다음칸에 위치.
		head = GetNextHeadPosition(head, movement);
		snake.push_front(head);

		// 2. 벽 또는 자기 자신과 부딪히면 게임 종료.
		if (head.first <= 0 || head.first > boardSize || head.second <= 0 || head.second > boardSize) {
			isGameOver = true;
			break;
		}

		if (IsBodyContacted(snake)) {
			isGameOver = true;
			break;
		}

		// 3. 이동한 칸에 사과 있을 경우 사과 제거 후 꼬리 움직이지 않음.
		if (apples[head.first][head.second]) {
			apples[head.first][head.second] = false;
		}
		// 4. 사과 없을 경우 꼬리 위치 칸 비워주기.
		else {
			snake.pop_back();
		}
		
		// 5. 방향 전환 필요시 시켜주기.
		switch (commands[currentTime]) {
		case 'L':
			switch (movement) {
			case 'L':
				movement = 'D';
				break;
			case 'R':
				movement = 'U';
				break;
			case 'U':
				movement = 'L';
				break;
			case 'D':
				movement = 'R';
				break;
			default:
				break;
			}
			break;
		case 'D':
			switch (movement) {
			case 'L':
				movement = 'U';
				break;
			case 'R':
				movement = 'D';
				break;
			case 'U':
				movement = 'R';
				break;
			case 'D':
				movement = 'L';
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	printf("%d", currentTime);

	return 0;
}
