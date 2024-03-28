/*
미완성 코드 입니다!!!!!!!!
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M, H;
int minAnswer = 9999;

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
};

struct Ladder {
	vector<int> ladder[31]; // ladder[4][0] = 3 -> 4번 점선의 0번째 index에 있는 값 3은 4번 점선에서 3번 세로줄, 4번(3 + 1) 세로줄이 연결되어 있음을 의미.
	int addedCnt;
};

vector<int> originalLadder[31]; // 이미 그려진 가로선들을 저장함.

vector<Ladder> ladders; // 만들어진 사다리들의 모든 경우를 저장해놓은 Vector.

bool CheckIfCorrectLadder(Ladder ladder) {
	int vertical[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int h = 1; h <= H; h++) {
		int indexSize = ladder.ladder[h].size();
		for (int i = 0; i < indexSize; i++) {
			Swap(&vertical[ladder.ladder[h][i]], &vertical[ladder.ladder[h][i] + 1]);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (vertical[i] != i)
			return false;
	}

	return true;
};

void CheckAllLadders() {
	int laddersSize = ladders.size();

	for (int i = 0; i < laddersSize; i++) {
		// ladders[i]를 가지고 결과가 조건에 맞는 경우 addedCnt를 확인.
		if (CheckIfCorrectLadder(ladders[i])) {
			if (ladders[i].addedCnt < minAnswer) {
				minAnswer = ladders[i].addedCnt;
			}
		}
	}
}

void MakeLadders() {
	Ladder newLadder;
	newLadder.addedCnt = 0;

	for (int h = 1; h <= H; h++) {
		// newLadder.ladder[h] 벡터에, 이어질 사다리들을 모두 push_back.
		vector<int> availables;

	}
}

int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;
		originalLadder[a].push_back(b);
	}

	// 사다리 만들기. (Ladders 벡터 저장.)
	MakeLadders();

	// 각 사다리 조건에 맞는지 확인.
	CheckAllLadders();

	if (minAnswer > 3)
		cout << -1;
	else
		cout << minAnswer;

	return 0;
}
