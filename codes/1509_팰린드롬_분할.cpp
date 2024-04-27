#include <iostream>
#include <string>

#define MAXVALUE 99999999

using namespace std;

string inputString;
int stringSize;
bool isPalin[2500][2500]; // isPalin[A][B] -> A번째 문자부터 B번째 문자까지 팰린드롬인가?
int minimumPalins[2500]; // minimumPalins[A] -> 첫 문자부터 A 번째 문자까지의 최소 팰린드롬 개수.

void HandleInput(){
	cin >> inputString;
}

void FillOutIsPalin(){
	for(int i=0;i<stringSize;i++)
		isPalin[i][i] = true;
	
	for(int i=0;i<stringSize-1;i++){
		if(inputString[i] == inputString[i+1])
			isPalin[i][i+1] = true;
		else
			isPalin[i][i+1] = false;
	}

	for(int len = 3;len <= stringSize;len++){
		for(int start = 0;start + len - 1 < stringSize; start++){
			if(inputString[start] == inputString[start + len - 1])
				isPalin[start][start + len - 1] = isPalin[start + 1][start + len - 2];
			else
				isPalin[start][start + len - 1] = false;
		}
	}
}

int MININT(int a, int b){
	if(a > b)
		return b;
	
	return a;
}

void SolveProblem(){
	stringSize = inputString.size();

	FillOutIsPalin();

	for(int end = 0; end < stringSize; end++){
		minimumPalins[end] = MAXVALUE;
		for(int start=0;start <= end; start++){
			if(isPalin[start][end]){
				if(start != 0)
					minimumPalins[end] = MININT(minimumPalins[end],minimumPalins[start - 1] + 1);
				else
					minimumPalins[end] = 1;
			}
				
		}
	}
}

void PrintAnswer(){
	cout << minimumPalins[stringSize - 1] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	HandleInput();
	SolveProblem();
	PrintAnswer();

	return 0;
}
