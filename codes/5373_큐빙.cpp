#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// map의 char key : W, B, R, O, Y, G
unordered_map<char, vector<vector<char>>> cube;

void InitCube(){
  cube['W'] = {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}};
  cube['Y'] = {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}};
  cube['B'] = {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}};
  cube['G'] = {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}};
  cube['R'] = {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}};
  cube['O'] = {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}};

  // cube['W'] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  // cube['Y'] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  // cube['B'] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  // cube['G'] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  // cube['R'] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  // cube['O'] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
}

// color 가 중심에 있는 면을 회전시킨다.
void RotateFront(char color, bool isClockwise){
  vector<char> temp = cube[color][0];

  if(isClockwise){
    for(int i=0;i<3;i++){
      cube[color][0][2 - i] = cube[color][i][0];
    }
    for(int i=0;i<3;i++){
      cube[color][i][0] = cube[color][2][i];
    }
    for(int i=0;i<3;i++){
      cube[color][2][i] = cube[color][2 - i][2];
    }
    for(int i=0;i<3;i++){
      cube[color][i][2] = temp[i];
    }
  }else{
    for(int i=0;i<3;i++){
      cube[color][0][i] = cube[color][i][2];
    }
    for(int i=0;i<3;i++){
      cube[color][i][2] = cube[color][2][2-i];
    }
    for(int i=0;i<3;i++){
      cube[color][2][2-i] = cube[color][2-i][0];
    }
    for(int i=0;i<3;i++){
      cube[color][2-i][0] = temp[i];
    }
  }
}

// color 면을 기준으로 접해있는 4개의 옆면을 회전시킨다.
void RotateSides(char color, bool isClockwise){
  vector<char> temp;
  switch(color){
  case 'W':
    temp = cube['R'][0];
    if(isClockwise){
      for(int i=0;i<3;i++){
        cube['R'][0][i] = cube['B'][0][i];
        cube['B'][0][i] = cube['O'][0][i];
        cube['O'][0][i] = cube['G'][0][i];
        cube['G'][0][i] = temp[i];
      }
    }else{
      for(int i=0;i<3;i++){
        cube['R'][0][i] = cube['G'][0][i];
        cube['G'][0][i] = cube['O'][0][i];
        cube['O'][0][i] = cube['B'][0][i];
        cube['B'][0][i] = temp[i];
      }
    }
    break;
  case 'Y':
    temp = cube['R'][2];
    if(isClockwise){
      for(int i=0;i<3;i++){
        cube['R'][2][i] = cube['G'][2][i];
        cube['G'][2][i] = cube['O'][2][i];
        cube['O'][2][i] = cube['B'][2][i];
        cube['B'][2][i] = temp[i];
      }
    }else{
      for(int i=0;i<3;i++){
        cube['R'][2][i] = cube['B'][2][i];
        cube['B'][2][i] = cube['O'][2][i];
        cube['O'][2][i] = cube['G'][2][i];
        cube['G'][2][i] = temp[i];
      }
    }
    break;
  case 'G':
    if(isClockwise){
      for(int i=0;i<3;i++){
        char tempC = cube['R'][i][0];
        cube['R'][i][0] = cube['W'][i][0];
        cube['W'][i][0] = cube['O'][2-i][2];
        cube['O'][2-i][2] = cube['Y'][i][0];
        cube['Y'][i][0] = tempC;
      }
    }else{
      for(int i=0;i<3;i++){
        char tempC = cube['R'][i][0];
        cube['R'][i][0] = cube['Y'][i][0];
        cube['Y'][i][0] = cube['O'][2-i][2];
        cube['O'][2-i][2] = cube['W'][i][0];
        cube['W'][i][0] = tempC;
      }
    }
    break;
  case 'B':
    if(isClockwise){
      for(int i=0;i<3;i++){
        char tempC = cube['R'][i][2];
        cube['R'][i][2] = cube['Y'][i][2];
        cube['Y'][i][2] = cube['O'][2-i][0];
        cube['O'][2-i][0] = cube['W'][i][2];
        cube['W'][i][2] = tempC;
      }
    }else{
      for(int i=0;i<3;i++){
        char tempC = cube['R'][i][2];
        cube['R'][i][2] = cube['W'][i][2];
        cube['W'][i][2] = cube['O'][2-i][0];
        cube['O'][2-i][0] = cube['Y'][i][2];
        cube['Y'][i][2] = tempC;
      }
    }
    break;
  case 'R':
    temp = cube['W'][2];
    if(isClockwise){
      for(int i=0;i<3;i++){
        cube['W'][2][i] = cube['G'][2-i][2];
        cube['G'][2-i][2] = cube['Y'][0][2-i];
        cube['Y'][0][2-i] = cube['B'][i][0];
        cube['B'][i][0] = temp[i];
      }
    }else{
      for(int i=0;i<3;i++){
        cube['W'][2][i] = cube['B'][i][0];
        cube['B'][i][0] = cube['Y'][0][2-i];
        cube['Y'][0][2-i] = cube['G'][2-i][2];
        cube['G'][2-i][2] = temp[i];
      }
    }
    break;
  case 'O':
    temp = cube['W'][0];
    if(isClockwise){
      for(int i=0;i<3;i++){
        cube['W'][0][i] = cube['B'][i][2];
        cube['B'][i][2] = cube['Y'][2][2-i];
        cube['Y'][2][2-i] = cube['G'][2-i][0];
        cube['G'][2-i][0] = temp[i];
      }
    }else{
      for(int i=0;i<3;i++){
        cube['W'][0][i] = cube['G'][2-i][0];
        cube['G'][2-i][0] = cube['Y'][2][2-i];
        cube['Y'][2][2-i] = cube['B'][i][2];
        cube['B'][i][2] = temp[i];
      }
    }
    break;
  }
}

void RotateCube(string command){
  if(command == "U+"){
    RotateFront('W', true);
    RotateSides('W', true);
  }else if(command == "U-"){
    RotateFront('W', false);
    RotateSides('W', false);
  }else if(command == "D+"){
    RotateFront('Y', true);
    RotateSides('Y', true);
  }else if(command == "D-"){
    RotateFront('Y', false);
    RotateSides('Y', false);
  }else if(command == "L+"){
    RotateFront('G', true);
    RotateSides('G', true);
  }else if(command == "L-"){
    RotateFront('G', false);
    RotateSides('G', false);
  }else if(command == "R+"){
    RotateFront('B', true);
    RotateSides('B', true);
  }else if(command == "R-"){
    RotateFront('B', false);
    RotateSides('B', false);
  }else if(command == "F+"){
    RotateFront('R', true);
    RotateSides('R', true);
  }else if(command == "F-"){
    RotateFront('R', false);
    RotateSides('R', false);
  }else if(command == "B+"){
    RotateFront('O', true);
    RotateSides('O', true);
  }else if(command == "B-"){
    RotateFront('O', false);
    RotateSides('O', false);
  }
}

int main(){

  int T;
  cin >> T;

  for(int t=0;t<T;t++){
    int commandSize;
    cin >> commandSize;

    InitCube();

    for(int c =0;c<commandSize;c++){
      string command;
      cin >> command;
      RotateCube(command);
    }

    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cout << cube['W'][i][j];
      }
      cout <<'\n';
    }
  }


  return 0;
}
