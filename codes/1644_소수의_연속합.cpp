#include <iostream>
#include <vector>
#include <unordered_map>

#define endl '\n'

using namespace std;

int N;
vector<int> primeNumbers;
vector<bool> isChecked(4000001, false);
int answer;

void HandleInput(){
    cin >> N;
}

void CalculatePrimeNumbers(){
    for(int i=2;i*i<=N;i++){
        if(!isChecked[i]){
            for(int j=2 * i;j<=N;j+=i){
                isChecked[j] = true;
            }
        }
    }

    for(int i=2;i<=N;i++){
        if(!isChecked[i])
            primeNumbers.push_back(i);
    }
}

void CountPartialSums(){
    int start = 0, end = 0, sum = 0;
    int primeSize = primeNumbers.size();

    while(true){
        if(sum < N){
            if(end >= primeSize)
                break;
            sum += primeNumbers[end];
            end++;
        }else if(sum > N){
            sum -= primeNumbers[start];
            start++;
        }else{
            answer++;
            if(end >= primeSize)
                break;
            sum += primeNumbers[end];
            end++;
        }
    }
}

void PrintAnswer(){
    cout << answer << endl;
}

void SolveProblem(){
    answer = 0;

    CalculatePrimeNumbers();
    CountPartialSums();
}

int main(){
    HandleInput();
    SolveProblem();
    PrintAnswer();
    return 0;
}
