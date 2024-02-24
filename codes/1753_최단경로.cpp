#define _CRT_SECURE_NO_WARNINGS
#define INF 99999999

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

int V, E;
vector<pair<int, int>> graph[300001]; // ex) graph[1] -> pair<3, 5>  =  1에서 3까지의 거리 5.
int dist[20001];

void CalculateDijkstra(int start) {
	priority_queue<pair<int, int>> pq; // pair<start부터 end까지의 cost, end>, 이때 cost 부분은 음수로 들어감. (의미상 최소 힙 구조)
	// ex) pq.top -> <-1, 4> = start에서부터 4까지의 cost 1. 현재 가장 작은 cost.

	// distance 초기화.
	fill(dist, dist + V + 1, INF);
	dist[start] = 0;

	// start 지점 삽입.
	pq.push({0, start});

	while (pq.empty() == false) {
		int currentV = pq.top().second;
		int currentDist = pq.top().first * -1;
		pq.pop();

		if (dist[currentV] < currentDist)
			continue;

		for (auto& pair : graph[currentV]) { // currentV에서부터 이동 가능한 모든 지점들에 대한 for loop,
			if (dist[pair.first] > pair.second + currentDist) {
				dist[pair.first] = pair.second + currentDist;
				pq.push({ dist[pair.first] * -1, pair.first });
			}
		}
	}
};

int main() {
	int start;

	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	for (int i = 0; i < E; i++) {
		int st, end, cst;
		scanf("%d %d %d", &st, &end, &cst);

		graph[st].push_back({end, cst});
	}

	CalculateDijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}
