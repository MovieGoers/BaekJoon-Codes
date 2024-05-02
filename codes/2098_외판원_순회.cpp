#include <iostream>
#include <cstring>

#define INF 99999999

using namespace std;

int N;
int W[16][16];
int answer;
int DP[16][1 << 16];

void HandleInput(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> W[i][j];
        }
    }
}

int MIN(int a, int b){
    if(a < b)
        return a;
    
    return b;
}

int VisitDFS(int curr, int bits){
    // 모든 정점을 방문한 경우,
    if(bits == (1 << N) - 1){
        // 다시 시작 정점으로 돌아가는 길이 없는 경우,
        if(W[curr][0] == 0)
            return INF;
        
        // 시작 정점으로 돌아가는 길이 있으므로 cost 반환.
        return W[curr][0];
    }

    // 이미 DP를 통해 최소값을 구한 경우,
    if(DP[curr][bits] != -1)
        return DP[curr][bits];

    DP[curr][bits] = INF;

    // 각 정점들에 대해서
    for(int next = 0;next < N;next++){
        // 현재 정점 curr에서 다음 정점 next로 이동을 할 수 없는 경우,
        if(W[curr][next] == 0)
            continue;

        // 이미 방문했던 정점인 경우,
        // bits와 next의 정점 AND 연산 값이 0이 아닌 경우 이미 방문했다는 의미.
        if(bits & (1 << next))
            continue;

        // next를 거쳐 이동하는 경로와 그렇지 않은 경로를 비교, cost 최솟값 구하기.
        DP[curr][bits] = MIN(DP[curr][bits], W[curr][next] + VisitDFS(next, bits | (1 << next)));
    }

    return DP[curr][bits];
}

void SolveProblem(){
    memset(DP, -1, sizeof(DP));
    answer = VisitDFS(0, 1);
}

void PrintAnswer(){
    cout << answer << '\n';
}

int main() {
    HandleInput();
    SolveProblem();
    PrintAnswer();

    return 0;
}
