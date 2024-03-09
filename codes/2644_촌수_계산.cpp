#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

bool graph[101][101] = { false, };
int personSize;

int GetChonNumber(int a, int b) {
	queue<pair<int, int>> Q;
	bool checked[101] = { false, };

	Q.push({a, 0});

	checked[a] = true;
	while (!Q.empty()) {
		int current = Q.front().first;
		int chon = Q.front().second;
		Q.pop();

		if (current == b) {
			return chon;
		}

		for (int i = 1; i <= personSize; i++) {
			if (graph[current][i] && !checked[i]) {
				checked[i] = true;
				Q.push({i, chon + 1});
			}
		}
	}

	return -1;
}

int main() {
	int person1, person2;

	scanf("%d", &personSize);

	scanf("%d %d", &person1, &person2);

	int graphSize;
	scanf("%d", &graphSize);

	for (int i = 0; i < graphSize; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = true;
		graph[b][a] = true;
	}

	printf("%d", GetChonNumber(person1, person2));

	return 0;
}
