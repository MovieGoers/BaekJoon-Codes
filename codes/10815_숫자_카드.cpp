#include <stdio.h>
#include <unordered_map>

using namespace std;

int N, M;
int cards[500000];
unordered_map<int, bool> map;
int verifyingNumbers[500000];
int answer;

void HandleInput(){
	scanf("%d", &N);

	for(int i=0;i<N;i++){
		scanf("%d", &cards[i]);
	}

	scanf("%d", &M);

	for(int i=0;i<M;i++){
		scanf("%d", &verifyingNumbers[i]);
	}
}

void SolveProblem(){
	for(int i=0;i<N;i++){
		map[cards[i]] = true;
	}
}

void PrintAnswer(){
	for(int i=0;i<M;i++){
		if(map[verifyingNumbers[i]])
			printf("1 ");
		else
			printf("0 ");
	}
}

int main(){
	HandleInput();
	SolveProblem();
	PrintAnswer();
	
	return 0;
}
