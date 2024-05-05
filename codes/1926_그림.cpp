#include <iostream>
#include <cstring>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int n, m;
int map[500][500];
bool visited[500][500];
int maxArea;
int subArea;
int count;

void HandleInput(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
}

int MAX(int a, int b){
    if(a > b)
        return a;
    
    return b;
}

void DoDFS(int row, int col){
    subArea += 1;
    visited[row][col] = true;

    for(int i=0;i<4;i++){
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
            continue;
        
        if(visited[newRow][newCol] || map[newRow][newCol] == 0)
            continue;

        DoDFS(newRow, newCol);
    }
}

void SolveProblem(){
    memset(visited, false, sizeof(visited));
    maxArea = 0;
    count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && map[i][j] == 1){
                count++;
                subArea = 0;
                DoDFS(i, j);
                maxArea = MAX(maxArea, subArea);
            }
        }
    }
}

void PrintAnswer(){
    cout << count << '\n' << maxArea << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    HandleInput();
    SolveProblem();
    PrintAnswer();

    return 0;
}
