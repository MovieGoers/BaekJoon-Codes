#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

/*
    F : 건물의 층 수
    S : 시작 층
    G : 목표 층
    U : 올라가는 층 수
    D : 내려가는 층 수
*/
int F, S, G, U, D;
int answer;
bool visited[1000001];
bool isFound;


void HandleInput(){
    cin >> F >> S >> G >> U >> D;
}

void DoBFS(){
    queue<pair<int, int>> q; // pair의 첫 인자는 현재 층, 두 번째 인자는 이동 횟수.
    int nextMove[2] = {U, -D};

    // 현재 위치 Q에 입력.
    q.push({S, 0});
    visited[S] = true;

    while(!q.empty()){
        int current = q.front().first;
        int count = q.front().second;
        q.pop();

        // 현재 위치가 스타트링크의 층 수인 경우.
        if(current == G){
            answer = count;
            isFound = true;
            return;
        }

        for(int i=0;i<2;i++){
            int next = current + nextMove[i];

            // 범위 밖.
            if(next < 1 || next > F)
                continue;
            
            // 이미 방문한 경우.
            if(visited[next])
                continue;

            visited[next] = true;
            q.push({next, count + 1});
        }
    }
}

void SolveProblem(){
    answer = 0;
    memset(visited, false, sizeof(visited));
    isFound = false;
    DoBFS();
}

void PrintAnswer(){
    if(isFound)
        cout << answer << '\n';
    else
        cout << "use the stairs" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    HandleInput();
    SolveProblem();
    PrintAnswer();

    return 0;
}
