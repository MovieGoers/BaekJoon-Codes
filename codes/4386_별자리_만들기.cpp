#include <stdio.h>
#include <math.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<double, double>> points(101);
double distances[101][101]; // distances[2][3] -> 2번과 3번 별 사이의 거리(double)

int parent[10001]; // parent[2] = 1 -> 2번 노드의 parent는 1번 노드.
int starSize;

void InitializeParent() {
	for (int i = 1; i <= starSize; i++) {
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

double GetDistance(int p1, int p2){
    return sqrt(pow(points[p1].first - points[p2].first, 2) + pow(points[p1].second - points[p2].second, 2));
}

int main() {
	double total_weight = 0.0;
	vector<pair<double, pair<int, int>>> E_vector; // {3.0, {4, 5}} -> 4번과 5번을 연결하는 간선 가중치가 3.0.

	scanf("%d", &starSize);
	
	InitializeParent(); // 각 노드의 parent를 자기 자신으로 설정.

	for (int i = 1; i <= starSize; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		points[i].first = x;
        points[i].second = y;
	}

    int ESizeCount = 0;
    for(int i=1;i<=starSize;i++){
        for(int j=i+1;j<=starSize;j++){
            E_vector.push_back({GetDistance(i, j), {i, j}});
            ESizeCount++;
        }
    }

	sort(E_vector.begin(), E_vector.end());

	for (int i = 0; i < ESizeCount; i++) {
		int A, B;
        double weight;

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

	printf("%lf", total_weight);

	return 0;
}
