#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int M, N, K;
bool isPainted[100][100];
bool visited[100][100];
int cnt, area;
vector<int> areas;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Paint(int a, int b, int c, int d){
    for(int i=a;i<c;i++){
        for(int j=b;j<d;j++){
            isPainted[i][j] = true;
        }
    }
}

void Print(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(isPainted[i][j])
                cout << "O ";
            else cout << "X ";
        }
        cout << '\n';
    }
}

void DoBFS(int x, int y){
    queue<pair<int,int>> Q;
    Q.push({x, y});
    visited[x][y] = true;

    while(!Q.empty()){
        pair<int, int> current = Q.front();
        Q.pop();

        for(int i=0;i<4;i++){
            pair<int, int> next = {current.first + dx[i], current.second + dy[i]};

            if(next.first < 0 || next.first >= M || next.second < 0 || next.second >= N)
                continue;

            if(visited[next.first][next.second] || isPainted[next.first][next.second])
                continue;

            visited[next.first][next.second] = true;
            area++;
            Q.push(next);
        }
    }
}

int main(){
    cin >> M >> N >> K;
    memset(isPainted, false, sizeof(isPainted));
    memset(visited, false, sizeof(visited));
    cnt = 0;

    int a, b, c, d;
    for(int k=0;k<K;k++){
        cin >> a >> b >> c >> d;
        Paint(b, a, d, c);
    }

    //Print();

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!isPainted[i][j] && !visited[i][j]){
                cnt++;
                area = 1;
                DoBFS(i, j);
                areas.push_back(area);
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << cnt << '\n';
    int areasSize = areas.size();
    for(int i=0;i<areasSize;i++){
        cout << areas[i] << ' ';
    }

    return 0;
}
