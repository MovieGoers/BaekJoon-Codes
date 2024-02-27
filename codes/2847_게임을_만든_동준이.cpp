#include <stdio.h>

using namespace std;

int main(){
    int N;
    int arr[100];

    scanf("%d", &N);

    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }

    int nextScore = arr[N-1] - 1;
    int decreasedScoreSum = 0;

    for(int i=N-2;i>=0;i--){
        if(arr[i] > nextScore){
            decreasedScoreSum += arr[i] - nextScore;
            nextScore--;
        }else{
            nextScore = arr[i] - 1;
        }
    }

    printf("%d", decreasedScoreSum);
    return 0;
}
