#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAXINT 999999

int N;
int map[100][100];
bool visited[100][100];
int answer;

vector<pair<int, pair<int, int>>> startingPosVec;

int dr[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dc[8] = {0, 0, -1, 1, 1, -1, 1, -1};

void GetInputs(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
}

void PrintDebug(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    for(auto & elem : startingPosVec){
        cout << elem.first << ' ' << elem.second.first << ' ' << elem.second.second << '\n';
    }
}

void MarkIsland(int row, int col, int number){
    queue<pair<int, int>> Q;
    Q.push({row, col});
    visited[row][col] = true;
    map[row][col] = number;

    while(!Q.empty()){
        pair<int, int> current = Q.front();
        Q.pop();

        for(int i=0;i<4;i++){
            pair<int, int> next = {current.first + dr[i], current.second + dc[i]};

            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
                continue;
            
            if(visited[next.first][next.second] || !map[next.first][next.second])
                continue;

            visited[next.first][next.second] = true;
            map[next.first][next.second] = number;
            Q.push(next);
        }
    }
}

void MarkIslands(){
    int currentNumber = 1;

    memset(visited, false, sizeof(visited));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j] && map[i][j]){
                MarkIsland(i, j, currentNumber);
                currentNumber++;
            }
        }
    }
}

void GetAllStartingPositions(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == 0){
                for(int k=0;k<4;k++){
                    if(i+dr[k] < 0 || j+dc[k] < 0 || i+dr[k] >= N || j+dc[k] >= N)
                        continue;

                    if(map[i+dr[k]][j+dc[k]]){
                        // 근처에 섬이 있는 경우이므로 벡터에 추가.
                        startingPosVec.push_back({map[i+dr[k]][j+dc[k]], {i, j}});
                        break;
                    }
                }
            }
        }
    }
}

int Min(int a, int b){
    if(a < b)
        return a;

    return b;
}

int GetBridgeSize(int row, int col, int start){
    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int, int>>> Q;

    Q.push({1, {row, col}});
    visited[row][col] = true;

    while(!Q.empty()){
        pair<int, int> current = Q.front().second;
        int size = Q.front().first;
        Q.pop();

        for(int i=0;i<4;i++){
            pair<int, int> next = {current.first + dr[i], current.second + dc[i]};

            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
                continue;

            // 근처에 다른 종류의 섬 타일이 존재할 경우.
            if(map[next.first][next.second] != 0 && map[next.first][next.second] != start){
                return size;
            }
            
            if(visited[next.first][next.second] || map[next.first][next.second])
                continue;

            visited[next.first][next.second] = true;
            Q.push({size + 1, next});
        }
    }

    return 999999;
}

void SolveProblem(){
    answer = MAXINT;

    MarkIslands(); // 각 섬에 다른 번호를 매김.
    GetAllStartingPositions(); // 섬 인근 바다 타일을 모두 구함(위치, 근접 섬 번호를 저장)

    //PrintDebug();
    int posCount = startingPosVec.size();
    for(int i=0;i<posCount;i++){
        // 각 섬 인근 바다 타일들에 대해서 BFS를 이용한 다리의 최소 길이를 구하고 최솟값과 비교 후 업데이트.
        answer = Min(answer, GetBridgeSize(startingPosVec[i].second.first, startingPosVec[i].second.second, startingPosVec[i].first));
    }
}

void PrintAnswer(){
    cout << answer << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    GetInputs();
    SolveProblem();
    PrintAnswer();

    return 0;
}
