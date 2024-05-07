#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int T, I, answer;
pair<int, int> startPos, endPos;

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

void HandleInput(){
    cin >> I;
    cin >> startPos.first >> startPos.second;
    cin >> endPos.first >> endPos.second;
}

bool IsPositionSame(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first && a.second == b.second)
        return true;
    
    return false;
}

void SolveProblem(){
    queue<pair<int, pair<int, int>>> Q;
    bool visited[300][300];

    answer = -1;

    memset(visited, false, sizeof(visited));

    Q.push({0, startPos});
    visited[startPos.first][startPos.second] = true;

    while(!Q.empty()){
        pair<int, int> currentPos = Q.front().second;
        int count = Q.front().first;
        Q.pop();

        if(IsPositionSame(currentPos, endPos)){
            answer = count;
            return;
        }

        for(int i=0;i<8;i++){
            pair<int, int> nextPos = {currentPos.first + dx[i], currentPos.second + dy[i]};

            if(nextPos.first < 0 || nextPos.first >= I || nextPos.second < 0 || nextPos.second >= I)
                continue;

            if(visited[nextPos.first][nextPos.second])
                continue;
            
            visited[nextPos.first][nextPos.second] = true;
            Q.push({count + 1, nextPos});
        }
    }

}

void PrintAnswer(){
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for(int t=0;t<T;t++){
        HandleInput();
        SolveProblem();
        PrintAnswer();
    }

    return 0;
}
