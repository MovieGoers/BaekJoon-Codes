#include <stdio.h>
#include <memory.h>
#include <vector>
#include <utility>

using namespace std;

int N, M;
int map[50][50];
bool checked[13];
int chickenSize = 0;
int houseSize = 0;
int minChickenDistance = 99999999;
vector<pair<int,int>> chickenPositions;
vector<pair<int, int>> housePositions;
vector<pair<int, int>> selectedChickenPositions(13);

int Abs(int a){
  if(a < 0)
    return -a;
  
  return a;
}

int chickenDist(pair<int,int> A, pair<int, int> B){
  return Abs(A.first - B.first) + Abs(A.second - B.second);
}

int GetChickenDistance(){
  int distance = 0;
  for(int house = 0;house<houseSize;house++){
    int localMinDist = 999999;
    int localDist;
    int houseR = housePositions[house].first, houseC = housePositions[house].second;
    for(int chicken = 0;chicken<M;chicken++){
      localDist = chickenDist(housePositions[house], selectedChickenPositions[chicken]);
      if(localDist < localMinDist){
        localMinDist = localDist;
      }
    }
    distance += localMinDist;
  }
  return distance;
};

void PickChickenPlaceDFS(int count, int limit){
  if(count == M){
    // chickenStack의 치킨집으로 치킨 거리 구하기.
    int chickenDistance = GetChickenDistance();
    if(minChickenDistance > chickenDistance){
      minChickenDistance = chickenDistance;
    }
    return;
  }

  for(int i=limit;i<chickenSize;i++){
    if(!checked[i]){
      checked[i] = true;
      selectedChickenPositions[count] = {chickenPositions[i].first, chickenPositions[i].second};
      PickChickenPlaceDFS(count + 1, i);
      checked[i] = false;
    }
  }
}

int main(){
  memset(checked, false, sizeof(checked));

  scanf("%d%d", &N, &M);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d", &map[i][j]);
      if(map[i][j] == 2){
        chickenPositions.push_back({i, j});
        chickenSize++;
      }
      if(map[i][j] == 1){
        housePositions.push_back({i, j});
        houseSize++;
      }
    }
  }

  PickChickenPlaceDFS(0, 0);

  printf("%d", minChickenDistance);

  return 0;
}
