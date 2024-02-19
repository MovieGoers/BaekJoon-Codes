#include <iostream>

#define INF 9999999

using namespace std;

int FIndNearestArea(int areaSize, bool visited[101], int distance[101]) {
	int nearest = -1;
	int distMin = INF;
	for (int i = 1; i <= areaSize; i++) {
		if (visited[i])
			continue;

		if (distMin > distance[i]) {
			distMin = distance[i];
			nearest = i;
		}
	}

	return nearest;
};

void UpdateDIstance(int graph[101][101], int nearestArea, int distance[101], int areaSize, bool visited[101]) {
	for (int i = 1; i <= areaSize; i++) {
		if (visited[i])
			continue;

		if (distance[i] > distance[nearestArea] + graph[nearestArea][i]) {
			distance[i] = distance[nearestArea] + graph[nearestArea][i];
		}
	}
};

int GetMaxItemDijkstra(int areaSize, int graph[101][101], int start, int items[101], int distLimit) {
	int max = 0;
	int distance[101] = { -1, };
	bool visited[101] = { false, };

	visited[start] = true;
	distance[start] = 0;

	for (int i = 1; i <= areaSize; i++) {
		distance[i] = graph[start][i];
	}

	for (int i = 0; i < areaSize - 1; i++) {
		// 가장 가까운 area index 구하기.
		int nearestArea = FIndNearestArea(areaSize, visited, distance);
		
		if (nearestArea == -1)
			continue;

		visited[nearestArea] = true;

		// 방문 표시 후, distance 배열 업데이트. 
		UpdateDIstance(graph, nearestArea, distance, areaSize, visited);
	}

	for (int i = 1; i <= areaSize; i++) {
		if (distLimit >= distance[i]) {
			max += items[i];
		}
	}

	return max;
}

void InitializeGraph(int graph[101][101], int areaSize) {
	for (int i = 1; i <= areaSize; i++) {
		for (int j = 1; j <= areaSize; j++) {
			graph[i][j] = INF;
		}
	}
}

int main() {
	int areaSize, distLimit, roadSize;
	cin >> areaSize >> distLimit >> roadSize;

	int items[101];
	int graph[101][101];

	InitializeGraph(graph, areaSize);
	
	for (int i = 1; i <= areaSize; i++) {
		cin >> items[i];
		graph[i][i] = 0;
	}

	for (int i = 0; i < roadSize; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		graph[a][b] = cost;
		graph[b][a] = cost;
	}

	int max = -1;

	for (int i = 1; i <= areaSize; i++) {
		int tempMax = GetMaxItemDijkstra(areaSize, graph, i, items, distLimit);
		if (tempMax > max) {
			max = tempMax;
		}
	}
	
	cout << max;

	return 0;
}
