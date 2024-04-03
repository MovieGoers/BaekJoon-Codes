#include <stdio.h>
#include <unordered_map>
#include <set>
#include <utility>
#include <algorithm>
#include <memory.h>

using namespace std;

int r, c, k;
int rowSize, colSize;
int A[101][101];
int time;

void DoRAction(){
	for(int i=1;i<=rowSize;i++){
		unordered_map<int, int> mp;
		set<int> st;
		vector<pair<int, int>> pairVector;

		for(int j=1;j<=colSize;j++){
			if(A[i][j] != 0){
				mp[A[i][j]]++;
				st.insert(A[i][j]);
			}
		}

		for(auto & elem : st){
			pairVector.push_back({mp[elem], elem}); // {빈도, value}
		}

		sort(pairVector.begin(), pairVector.end());

		int pairVectorSize = pairVector.size();

		if(pairVectorSize > 50)
			pairVectorSize = 50;
	
		if(pairVectorSize * 2 > colSize){
			colSize = pairVectorSize * 2;
		}

		for(int j=1;j<100;j++){
			A[i][j] = 0;
		}

		for(int j=0;j<pairVectorSize;j++){
			A[i][j * 2 + 1] = pairVector[j].second;
			A[i][j * 2 + 2] = pairVector[j].first;
		}
	}
};

void DoCAction(){
	for(int i=1;i<=colSize;i++){
		unordered_map<int, int> mp;
		set<int> st;
		vector<pair<int, int>> pairVector;

		for(int j=1;j<=rowSize;j++){
			if(A[j][i] != 0){
				mp[A[j][i]]++;
				st.insert(A[j][i]);
			}
		}

		for(auto & elem : st){
			pairVector.push_back({mp[elem], elem}); // {빈도, value}
		}

		sort(pairVector.begin(), pairVector.end());

		int pairVectorSize = pairVector.size();

		if(pairVectorSize > 50)
			pairVectorSize = 50;
	
		if(pairVectorSize * 2 > rowSize){
			rowSize = pairVectorSize * 2;
		}

		for(int j=1;j<100;j++){
			A[j][i] = 0;
		}

		for(int j=0;j<pairVectorSize;j++){
			A[j * 2 + 1][i] = pairVector[j].second;
			A[j * 2 + 2][i] = pairVector[j].first;
		}
	}
};

void PrintArray(){
	for(int i=1;i<=rowSize;i++){
		for(int j=1;j<=colSize;j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
};

int main(){
	rowSize = 3;
	colSize = 3;
	time = 0;

	scanf("%d%d%d", &r, &c, &k);

	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			scanf("%d", &A[i][j]);
		}
	}

	if(A[r][c] == k)
	{
		printf("0");
		return 0;
	}

	while(time <= 100){
		if(rowSize >= colSize)
			DoRAction();
		else
			DoCAction();
		
		time++;

		if(A[r][c] == k)
			break;
	}

	if(time > 100)
		time = -1;
	printf("%d", time);
	
	return 0;
}
