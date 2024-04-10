#include <stdio.h>

#define MAXVALUE 999999

int N;
int cost[1001][3];
int DP[1001][3];
int startingCost[3];
int answer = MAXVALUE;

void HandleInput(){
	scanf("%d", &N);

	for(int i=1;i<=N;i++){
		scanf("%d%d%d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}

	startingCost[0] = cost[1][0];
	startingCost[1] = cost[1][1];
	startingCost[2] = cost[1][2];
}

int GetMinimum(int A, int B){
	if(A < B)
		return A;
	
	return B;
}

int GetMinimumTriple(int a, int b, int c){
	if(a < b){
		if(a < c){
			return a;
		}else
			return c;
	}else{
		if(b < c)
			return b;
		else
			return c;
	}
}

void DoDP(){
	for(int i=0;i<3;i++){
		DP[1][i] = cost[1][i];
	}

	// start는 각각 처음 DP에서 고르는 색 r, g, b를 의미.
	for(int start = 0;start<3;start++){
		int tempAnswer = MAXVALUE;

		// start 색에 맞는 DP의 마지막 같은 색의 cost를 MAXVALUE로 설정하여 선택되지 않도록 구현.
		int temp = cost[N][start];
		cost[N][start] = MAXVALUE;
		
		// 그리고 DP의 1번째 색깔은 무조건 start로 시작하므로 나머지 색깔을 MAXVALUE로 설정하여 역시 선택되지 않도록 구현. 
		for(int i=0;i<3;i++){
			if(i != start)
				DP[1][i] = MAXVALUE;
		}

		for(int i=2;i<=N;i++){
			DP[i][0] = GetMinimum(DP[i-1][1], DP[i-1][2]) + cost[i][0];
			DP[i][1] = GetMinimum(DP[i-1][0], DP[i-1][2]) + cost[i][1];
			DP[i][2] = GetMinimum(DP[i-1][0], DP[i-1][1]) + cost[i][2];
		}

		// DEBUG.
		// printf("In start of %d, (%d, %d, %d). So, minimum value is %d\n", start, DP[N][0], DP[N][1], DP[N][2],  GetMinimumTriple(DP[N][0], DP[N][1], DP[N][2]));
		
		tempAnswer = GetMinimumTriple(DP[N][0], DP[N][1], DP[N][2]);

		if(tempAnswer < answer)
			answer = tempAnswer;

		// 다음 start 색을 골랐을 경우를 계산하기 위해, 이전에 MAXVALUE로 설정한 값들을 리셋.
		cost[N][start] = temp;
		for(int i=0;i<3;i++){
			if(i != start)
				DP[1][i] = startingCost[i];
		}
	}
}

void PrintAnswer(){
	printf("%d\n", answer);
}

int main(){
	HandleInput();
	DoDP();
	PrintAnswer();

	return 0;
}
