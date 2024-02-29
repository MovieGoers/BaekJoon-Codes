#include <stdio.h>

using namespace std;

int N;
int chess[15]; // ex) chess[0] = 3 -> 0번째 행, 3번째 열에 Queen 존재.
int cnt;

int Abs(int a){
    if(a < 0)
        return -a;
    
    return a;
}

void FillInQueen(int row){
    if(row == N){
        cnt++;
        return;
    }

    for(int i=0;i<N;i++){
        bool flag = false;

        for(int j=0;j<row;j++){
            if(chess[j] == i || Abs(row - j) == Abs(i - chess[j]))
                flag = true;
        }

        if(flag == false){
            chess[row] = i;
            FillInQueen(row+1);
        }
    }
}

int main(){
    scanf("%d", &N);

    cnt = 0;

    FillInQueen(0);

    printf("%d", cnt);

    return 0;
}
