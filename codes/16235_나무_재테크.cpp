#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <stack>
#include <memory.h>
#include <deque>

using namespace std;

int N, M, K;
int A[11][11];
int food[11][11];

vector<int> trees[11][11];

stack<pair<int, pair<int, int>>> deadTrees;
stack<pair<int, pair<int, int>>> age5Trees;

int dr[8] = {0, 0, 1, 1, -1, -1, 1, -1};
int dc[8] = {1, -1, 1, -1, 1, -1, 0, 0};

// 각 나무들이 자신의 나이만큼 각 양분을 먹고 나이 1 증가. 만약 같은 곳 여러 나무인 경우,
// 작은 나이의 나무부터 양분 먹는다.
// 나이만큼 양분 못 먹은 경우 죽는다.
void DoSpring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int treesSize = trees[i][j].size();
			for (int k = 0; k < trees[i][j].size(); k++) {
				// 충분한 양분이 있는 경우.
				if (trees[i][j][k] <= food[i][j]) {
					food[i][j] -= trees[i][j][k];
					trees[i][j][k]++;
					if (trees[i][j][k] % 5 == 0) {
						age5Trees.push({ trees[i][j][k], {i, j} });
					}
				}
				else {
					deadTrees.push({ trees[i][j][k], {i, j} });
					trees[i][j].erase(trees[i][j].begin() + k);
					k--;
				}
			}
		}
	}
}

// 봄에 죽은 나무가 나이 / 2 만큼 양분을 남긴다.
void DoSummer() {
	while (!deadTrees.empty()) {
		pair<int, pair<int, int>> deadTree = deadTrees.top();
		deadTrees.pop();

		food[deadTree.second.first][deadTree.second.second] += deadTree.first / 2;
	}
}

// 나이 % 5 == 0 이 true 인 경우 그 나무 인접 8개 칸에 나이 1인 나무 생성.
void DoFall() {
	while (!age5Trees.empty()) {
		pair<int, pair<int, int>> age5Tree = age5Trees.top();
		age5Trees.pop();

		int r = age5Tree.second.first;
		int c = age5Tree.second.second;

		for (int i = 0; i < 8; i++) {
			int newR = r + dr[i];
			int newC = c + dc[i];
			if (newR < 1 || newC < 1 || newR > N || newC > N)
				continue;

			// 벡터의 첫 번째 인덱스로 넣는다. 가장 최근에 자라는 나무이기 때문에 정렬이 따로 불필요하게끔 만들기 위함.
			trees[newR][newC].insert(trees[newR][newC].begin(), 1);
		}
	}
}

// A[r][c]만큼 양분 추가.
void DoWinter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			food[i][j] += A[i][j];
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, age;
		scanf("%d%d%d", &r, &c, &age);
		trees[r][c].push_back(age);
	}

	for (int i = 0; i < K; i++) {
		DoSpring();
		DoSummer();
		DoFall();
		DoWinter();
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += trees[i][j].size();
		}
	}
	printf("%d", cnt);

	return 0;
}
