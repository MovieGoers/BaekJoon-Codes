#include <iostream>

using namespace std;

#define MAXINT 99999999

int n;
int DP[50001];

void HandleInput(){
    cin >> n;
}

int MIN(int a, int b){
    if(a < b)
        return a;
    
    return b;
}

void SolveProblem(){
    DP[0] = 0;
    DP[1] = 1;

    for(int i=2;i<=n;i++){
        DP[i] = MAXINT;

        for(int j=1;j*j <= i;j++){
            DP[i] = MIN(DP[i], DP[i- j * j] + 1);
        }
    }
}

void PrintAnswer(){
    cout << DP[n] << '\n';
}

int main() {
    HandleInput();
    SolveProblem();
    PrintAnswer();

    return 0;
}
