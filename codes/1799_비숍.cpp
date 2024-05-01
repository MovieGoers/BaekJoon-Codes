#include <iostream>
#include <cstring>

using namespace std;

int N;
int board[10][10];
int answer[2];

bool leftUp[20];
bool rightUp[20];

void HandleInput(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
}

int MAX(int A, int B){
    if(A > B)
        return A;
    
    return B;
}

void FillInBoard(int row, int col, int count, int color){
    // col이 체스판 밖으로 나가는 경우.
    if(col >= N){
        // 다음 row의 첫 col (color에 따라 다름.)를 설정.
        row++;
        if(color == 0){
            col = row % 2;
        }else{
            col = (row + 1) % 2;
        }
    }

    // row이 체스판 밖으로 나가는 경우.
    if(row >= N){
        // color에 따라 count 최댓값으로 업데이트.
        answer[color] = MAX(answer[color], count);
        return;
    }

    // 1. 현재 보드 판에 비숍을 놓을 수 있고,
    // 2. 각 대각선으로 이미 비숍이 놓아지지 않았다면,
    if(board[row][col] && !leftUp[row - col + N - 1] && !rightUp[row + col]){
        leftUp[row - col + N - 1] = true;
        rightUp[row + col] = true;
        FillInBoard(row, col + 2, count + 1, color);
        leftUp[row - col + N - 1] = false;
        rightUp[row + col] = false;
    }

    FillInBoard(row, col + 2, count, color);
}

void SolveProblem(){
    answer[0] = answer[1] = 0;
    memset(leftUp, false, sizeof(leftUp));
    memset(rightUp, false, sizeof(rightUp));

    FillInBoard(0, 0, 0, 0); // color = 0 인 경우.
    FillInBoard(0, 1, 0, 1); // color = 1 인 경우.
}

void PrintAnswer(){
    cout << answer[0] + answer[1] << '\n';
}

int main(){
    HandleInput();
    SolveProblem();
    PrintAnswer();

    return 0;
}
