#include <stdio.h>

using namespace std;

int N, M;
int arr[7];
int current = 0;

void DFS(int depth){
    if(depth == M){
        for(int i=0;i<M;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=N;i++){
        arr[current++] = i; 
        DFS(depth + 1);
        current--;
    }
}

int main(){
    scanf("%d %d", &N, &M);

    DFS(0);
    return 0;
}
