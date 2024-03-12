#include <stdio.h>

using namespace std;

int main(){
    int A, B, C;
    scanf("%d%d", &A, &B);
    scanf("%d", &C);

    if(A + B >= C * 2){
        printf("%d", A+B-C * 2);
    }else{
        printf("%d", A + B);
    }
    return 0;
}
