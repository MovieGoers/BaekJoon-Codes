#include <iostream>
#include <vector>
#include <unordered_map>

#define endl '\n'

using namespace std;

int N;
int answer;
int DP[101][10];

void HandleInput(){
    cin >> N;
}

void SolveProblem(){

        DP[0][0] = 0;
    for(int i=1;i<=9;i++)
        DP[0][i] = 1;

    for(int i=1;i<N;i++){
        DP[i][0] = DP[i-1][1];
        DP[i][9] = DP[i-1][8];

        for(int j=1;j<=8;j++){
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j+1];
            DP[i][j] %= 1000000000;
        }
    }

    for(int i=0;i<=9;i++){
        answer = (answer + DP[N-1][i]) % 1000000000;
    }
}

void PrintAnswer(){
    cout << answer << endl;
}

int main(){
    HandleInput();
    SolveProblem();
    PrintAnswer();
    return 0;
}
