#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

 int V;
vector<vector<pair<int, int>>> tree(100001); // tree[2][0] first -> 2번 정점에서 이어진 다음 정점, second -> 그 정점까지의 cost.

bool checked[100001] = {false, };

int maxCost = -1;
int maxCostV = 0;

void ResetChecked(){
    for(int i = 1;i<=V;i++){
        checked[i] = false;
    }
}

void DFS(int current, int costSum){
    checked[current] = true;

    if(costSum > maxCost){
        maxCost = costSum;
        maxCostV = current;
    }

    for(auto & elem : tree[current]){
        int next = elem.first;
        int nextCost = elem.second;

        if(checked[next])
            continue;

        DFS(next, costSum + nextCost);
    }
}

int main(){
    scanf("%d", &V);

    for(int i=1;i<=V;i++){
        int start, end, cost;
        scanf("%d", &start);
        while(true){
            scanf("%d", &end);

            if(end == -1)
                break;

            scanf("%d", &cost);
            tree[start].push_back({end, cost});
        }
    }

    // 1. 1번 정점에서부터 시작해서 가장 먼 거리의 정점 구하기.
    DFS(1, 0);

    ResetChecked();

    // 2. 1.에서 구한 가장 먼 거리의 정점에서부터 가장 먼 거리의 cost 구하기.
    DFS(maxCostV, 0);

    printf("%d", maxCost);

    return 0;
}
