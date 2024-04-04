#include <stdio.h>
#include <vector>
#include <utility>
#include <memory.h>
#include <queue>

using namespace std;

int N, M;
int map[50][50];
vector<pair<int, int>> viruses;
pair<int, int> activatedViruses[10];
int checked[50][50];
int virusSize;
int emptySize;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int SpreadViruses(){
	int time = 0;
	int maxValue = -2;
	int filledSize = 0; // 빈칸에 바이러스가 들어간 칸의 수.
	memset(checked, -1, sizeof(checked));
	queue<pair<int, pair<int, int>>> Q;

	for(int i=0;i<M;i++){
		checked[activatedViruses[i].first][activatedViruses[i].second] = 0;
		Q.push({0, activatedViruses[i]});
	}

	while(!Q.empty()){
		if(emptySize == filledSize){
			// 만약 모든 빈칸에 바이러스가 채워진 경우.
			break;
		}
		int currentTime = Q.front().first;
		int currentR = Q.front().second.first;
		int currentC = Q.front().second.second;
		Q.pop();

		for(int i=0;i<4;i++){
			int newR = currentR + dr[i];
			int newC = currentC + dc[i];

			if(newR < 0 || newC < 0 || newR >= N || newC >= N)
				continue;

			if(checked[newR][newC] != -1)
				continue;
			
			if(map[newR][newC] == 1)
				continue;

			if(map[newR][newC] == 0)
				filledSize++;
			checked[newR][newC] = currentTime + 1;
			Q.push({currentTime + 1,{newR, newC}});
		}
	}

	// DFS가 끝났음에도 빈칸이 다 채워지지 못한 경우.
	if(emptySize != filledSize)
		return 99999999;

	// 현재 상황에서 걸린 시간 구하고 반환.
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(checked[i][j] > maxValue)
				maxValue = checked[i][j];
		}
	}

	return maxValue;
};

int minValue = 10000000;
void DFS(int depth, int index){
	if(depth == M){
		int minVirus = SpreadViruses();
		if(minValue > minVirus)
			minValue = minVirus;

		return;
	}

	for(int i=index;i<virusSize;i++){
		activatedViruses[depth] = viruses[i];
		DFS(depth + 1, i + 1);
	}
}

int main(){
	scanf("%d%d", &N, &M);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &map[i][j]);

			if(map[i][j] == 2)
				viruses.push_back({i, j});
			
			if(map[i][j] == 0)
				emptySize++;
		}
	}

	virusSize = viruses.size();
	DFS(0, 0);

	if(minValue == 10000000)
		minValue = -1;
	printf("%d", minValue);

	return 0;
}
