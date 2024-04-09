#include <stdio.h>

using namespace std;

void DrawTriangle(int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<i+1;j++)
			printf("*");
		printf("\n");
	}
}

int main(){
	while(true){
		int N;
		scanf("%d", &N);

		if(N == 0)
			break;
		
		DrawTriangle(N);
	}
	return 0;
}
