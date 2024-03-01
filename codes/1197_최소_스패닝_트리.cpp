#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int parent[10001]; // parent[2] = 1 -> 2번 노드의 parent는 1번 노드.
int V, E;

void InitializeParent() {
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	return;
};

int GetRoot(int node) {
	if (parent[node] == node)
		return node;

	parent[node] = GetRoot(parent[node]);

	return parent[node];
};

int main() {
	int total_weight = 0;
	vector<pair<int, pair<int, int>>> E_vector; // {3, {4, 5}} -> 4번과 5번을 연결하는 간선 가중치가 3.

	scanf("%d %d", &V, &E);
	
	InitializeParent(); // 각 노드의 parent를 자기 자신으로 설정.

	for (int i = 0; i < E; i++) {
		int A, B, weight;
		scanf("%d %d %d", &A, &B, &weight);
		E_vector.push_back({ weight, {A, B} });
	}

	sort(E_vector.begin(), E_vector.end());

	for (int i = 0; i < E; i++) {
		int A, B, weight;

		A = E_vector[i].second.first;
		B = E_vector[i].second.second;
		weight = E_vector[i].first;

		// 1. 사이클이 생기는 경우 판단, 생길 경우 무시.
		if (GetRoot(A) == GetRoot(B))
			continue;

		// 2. 간선 추가 (가중치 더하기)
		total_weight += weight;

		// 3. 부모 정보 추가. (parent)
		A = GetRoot(A);
		B = GetRoot(B);
		parent[A] = B;
	}

	printf("%d", total_weight);

	return 0;
}
