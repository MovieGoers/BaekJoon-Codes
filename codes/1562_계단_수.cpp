#include <iostream>
#include <vector>
#include <unordered_map>

#define endl '\n'

using namespace std;

int N;
int answer;
int DP[100][10][1024]; 
// DP[현재 자릿수 - 1][현재 자릿수에 있는 값][0부터 9까지의 비트].
// ex) '656'의 세번째 자릿수의 6에 대해서 DP[3 - 1][6][96 (= 0001100000)] = x, 즉 x개의 계단 수가 만들어지는 것.

void HandleInput(){
    cin >> N;
}

void SolveProblem(){

    DP[0][0][1] = 0;
    for (int index = 1; index < 10; index++){
        DP[0][index][1 << index] = 1;
    }

    for (int index = 1; index < N; index++)
    {
        for (int currentValue = 0; currentValue < 10; currentValue++)
        {
            for (int bits = 0; bits < (1 << 10); bits++)
            {
                // (bits | 1 << currentValue) 값은,
                // 이전 비트에 현재 자리에 위치한 값인 currentValue의 이진수 비트 값을 마스킹해준 값.
                if (currentValue == 0){
                    DP[index][currentValue][bits | 1 << currentValue] = (DP[index][currentValue][bits | 1 << currentValue] +DP[index - 1][currentValue + 1][bits]) % 1000000000;
                }
                else if (currentValue == 9){
                    DP[index][currentValue][bits | 1 << currentValue] = (DP[index][currentValue][bits | 1 << currentValue] + DP[index - 1][currentValue - 1][bits]) % 1000000000;
                } 
                else {
                    DP[index][currentValue][bits | 1 << currentValue] = (DP[index][currentValue][bits | 1 << currentValue] + DP[index - 1][currentValue - 1][bits] + DP[index - 1][currentValue + 1][bits]) % 1000000000;
                }
            }
        }
    }
    for(int i=0;i<=9;i++){
        answer = (answer + DP[N-1][i][1023]) % 1000000000;
        // 1023은 1111111111의 십진수 값, 즉 0부터 9까지의 숫자가 최소 한 번 이상 나왔다는 것을 의미.
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
