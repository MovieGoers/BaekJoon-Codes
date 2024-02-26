#include <stdio.h>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    long long arr[91];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2;i<=N;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    printf("%lld", arr[N]);

    return 0;
}
