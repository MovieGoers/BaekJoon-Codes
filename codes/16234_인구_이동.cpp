#include <stdio.h>
#include <memory.h>
#include <vector>
#include <utility>

using namespace std;

int N, L, R;
int map[50][50];
bool checked[50][50];
bool isChanged;
int unionSum;
int unionCount;
int answer;


int dR[4] = {0, 0, -1, 1};
int dC[4] = {-1, 1, 0, 0};

int Abs(int a){
  if(a < 0)
   return -a;

  return a;
}

bool CheckIfUnion(int a, int b){
  int abs = Abs(a - b);
  if(L <= abs && abs <= R)
    return true;

  return false;
}

void DFS(int row, int col, vector<pair<int, int>> & unions){
  checked[row][col] = true;
  unions.push_back({row, col});
  unionSum += map[row][col];
  unionCount++;

  for(int i=0;i<4;i++){
    int newRow = row + dR[i];
    int newCol = col + dC[i];

    if(newRow < 0 || newCol < 0 || newRow >= N || newCol >= N)
      continue;

    if(checked[newRow][newCol])
      continue;
    
    if(!CheckIfUnion(map[row][col], map[newRow][newCol]))
      continue;

    isChanged = true;
    DFS(newRow, newCol, unions);
  }
}

void PaintNewPopulation(int newValue, vector<pair<int, int>> & unions){
  for(auto & elem : unions){
    map[elem.first][elem.second] = newValue;
  }
}

int main(){
  answer = 0;
  scanf("%d%d%d", &N, &L, &R);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d", &map[i][j]);
    }
  }

  do{
    isChanged = false;
    memset(checked, false, sizeof(checked));
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(!checked[i][j]){
          vector<pair<int, int>> unions;
          unionSum = 0;
          unionCount = 0;
          DFS(i, j, unions);

          int newPopulation = unionSum / unionCount;

          PaintNewPopulation(newPopulation, unions);
        }
      }
    }

    answer++;
  }while(isChanged);

  printf("%d", answer - 1);

  return 0;
}
