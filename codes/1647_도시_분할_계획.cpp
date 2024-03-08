#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int GetRoot(vector<int>& roots, int x) {
    if (roots[x] == x)
        return x;

    return roots[x] = GetRoot(roots, roots[x]);
};

void Union(vector<int>& roots, int A, int B) {
    A = GetRoot(roots, A);
    B = GetRoot(roots, B);

    if (A < B)
        roots[B] = A;
    else
        roots[A] = B;
};

int main() {
    int houseSize, roadSize, minimumCost = 0;
    vector<pair<int, pair<int, int>>> roads; // roads.first -> 도로의 cost, roads.second.first -> 도로의 처음 집, ..second -> 도로의 두 번째 집.

    scanf("%d %d", &houseSize, &roadSize);

    vector<int> roots(houseSize + 1); // roots[2] = 1 -> 2번 노드의 root 노드는 1. cycle 확인용.

    // root를 본인 값으로 초기화.
    for (int i = 1; i <= houseSize; i++) {
        roots[i] = i;
    }

    for (int i = 0; i < roadSize; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);

        roads.push_back({ cost, {start, end} });
    }

    sort(roads.begin(), roads.end());

    int selectCnt = 0; // road가 선택된 총 갯수.
    int roadIndex = 0;

    // 최소 스패닝 트리는 간선의 수가 노드 - 1 개가 나오지만 현재 문제에서는 마지막 선택 간선은 무시하므로 -2로 하였다.
    while (selectCnt < houseSize - 2) {
        int cost, start, end;
        cost = roads[roadIndex].first;
        start = roads[roadIndex].second.first;
        end = roads[roadIndex].second.second;

        roadIndex++;

        // start 와 end의 root 노드 비교. 
        // 같을 경우, 무시. (연결 시 cycle 형성, 원치 않은 결과.)
        if (GetRoot(roots, start) == GetRoot(roots, end)) {
            continue;
        }

        // 다를 경우, 연결. (cost 추가.)
        Union(roots, start, end);

        minimumCost += cost;
        selectCnt += 1;
    }

    printf("%d", minimumCost);

    return 0;
}
