#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        int A, B;
        scanf("%d %d", &A, &B);

        if(A >= B){
            printf("MMM BRAINS\n");
        }else{
            printf("NO BRAINS\n");
        }
    }
    return 0;
}
