#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int studentSize, edgeSize;
vector<vector<int>> graph;
vector<int> fanIn;

void SortTopology() {
	queue<int> topologyQ;

	for (int i = 1; i <= studentSize; i++) {
		if (fanIn[i] == 0)
			topologyQ.push(i);
	}

	for (int i = 0; i < studentSize; i++) {
		int currentStudent = topologyQ.front();
		topologyQ.pop();

		int nextStudentSize = graph[currentStudent].size();
		for (int j = 0; j < nextStudentSize; j++) {
			int nextStudent = graph[currentStudent][j];
			fanIn[nextStudent] -= 1;

			if (fanIn[nextStudent] == 0)
				topologyQ.push(nextStudent);
		}

		printf("%d ", currentStudent);
	}
}

int main() {
	scanf("%d %d", &studentSize, &edgeSize);

	// 학생 수에 맞게 초기화.
	graph.assign(studentSize + 1, vector<int>(0, 0));
	fanIn.assign(studentSize + 1, 0);

	int A, B;
	for (int i = 0; i < edgeSize; i++) {
		scanf("%d %d", &A, &B);

		graph[A].emplace_back(B);
		fanIn[B] += 1;
	}

	SortTopology();

	return 0;
}
