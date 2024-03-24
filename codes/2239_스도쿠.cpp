#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int map[9][9];
vector<pair<int,int>> blanks;
int blanksSize = 0;

bool isValid(int row, int col, int value){
  // 행 확인
  for(int i=0;i<9;i++){
    if(map[row][i] == value)
      return false;
  }
  
  // 열 확인
  for(int i=0;i<9;i++){
    if(map[i][col] == value)
      return false;
  }
  
  // 3x3 구역 내 확인
  int subRow = (row / 3) * 3;
  int subCol = (col / 3) * 3;
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(map[subRow + i][subCol + j] == value)
        return false;
    }
  }
  
  return true;
}

void PrintMap(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout << map[i][j];
    }
    cout << '\n';
  }
};

bool isDone = false;

void DFS(int currentBlank){
  if(blanksSize == currentBlank){
	isDone = true;
    PrintMap();
    return;
  }
  
  if(!isDone){
	int blankRow = blanks[currentBlank].first;
	int blankCol = blanks[currentBlank].second;
	
	for(int i=1;i<=9;i++){
		if(isValid(blankRow, blankCol, i)){
		map[blankRow][blankCol] = i;
		DFS(currentBlank + 1);
		map[blankRow][blankCol] = 0;
		}
	}
    }
};

int main() 
{
  for(int i=0;i<9;i++){
    string inputStr;
    cin >> inputStr;
    for(int j=0;j<9;j++){
      map[i][j] = inputStr[j] - '0';
      if(map[i][j] == 0){
        blanksSize++;
        blanks.push_back({i, j});
      }
    }
  }
  
  DFS(0);
  
  return 0;
}
