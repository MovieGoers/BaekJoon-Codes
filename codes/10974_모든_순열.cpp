#include <stdio.h>
#include <unordered_map>

using namespace std;

int N;
int arr[8];
unordered_map<int, bool> uMap;

void DFS(int depth){
    if(N == depth){
        for(int i=0;i<N;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=N;i++){
        if(uMap[i] == false){
            arr[depth] = i;
            uMap[i] = true;
            DFS(depth+1);
            uMap[i] = false;
        }
    }
}

int main(){
    scanf("%d", &N);

    DFS(0);

    return 0;
}
