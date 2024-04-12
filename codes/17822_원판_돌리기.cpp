#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int N, M, T; // N : 원판 개수, M : 원판 내 정수의 개수, T : 회전 명령 수.
int plates[51][50]; // 1~N 번째의 원판. (0 index는 미사용) 한 원판 당 0 번째 index의 값이 원판의 위에 위치한 값.
int spinOrders[50][3]; // 각 order의 0 index 값의 배수 번째의 원판을 1 index 방향으로 2 index 값만큼 회전시킨다.
int answer;

vector<pair<int, int>> markedValuePositions; // 제거 대상으로 마킹된 값들의 위치 (plate 순서, 값 index).

void HandleInput(){
	scanf("%d%d%d", &N, &M, &T);

	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			scanf("%d", &plates[i][j]);
		}
	}

	for(int i=0;i<T;i++){
		for(int j=0;j<3;j++){
			scanf("%d", &spinOrders[i][j]);
		}
	}
}

// 원판 내 모든 값의 합 반환.
int GetSumOfPlates(){
	int sum = 0;

	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			sum += plates[i][j];
		}
	}

	return sum;
}

// 원판 내 모든 값의 개수 반환.
int GetCountOfPlates(){
	int count = 0;

	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			if(plates[i][j] != 0)
				count++;
		}
	}

	return count;
}

// 디버그 용.
void PrintAllPlateContents(){
	printf("\n");
	for(int i=1;i<=N;i++){
		printf("Plate #%d : ", i);
		for(int j=0;j<M;j++){
			printf("%d ", plates[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SpinSinglePlate(int plate, int d, int k){
	int tempPlate[50];

	for(int i=0;i<M;i++){
		tempPlate[i] = plates[plate][i];
	}

	if(d == 0){
		// 시계 방향 회전.
		for(int i=0;i<M;i++){
			plates[plate][(i + k) % M] = tempPlate[i];
		}
	}else{
		// 반시계 방향 회전.
		for(int i=0;i<M;i++){
			plates[plate][(i + M - k) % M] = tempPlate[i];
		}
	}
}

void SpinPlates(int x, int d, int k){
	for(int i=1;i*x <= N;i++){
		int curr = i * x; // 현재 회전하려는 plate의 index.

		SpinSinglePlate(curr, d, k);
	}
}

int MarkAllCloseSameValues(){
	// 이전에 마킹된 위치들 모두 비우기.
	markedValuePositions.clear();

	// 각 plate 간의 인접하고 같은 값 마킹하기.
	for(int i=0;i<M;i++){
		for(int j=1;j<N;j++){
			if(plates[j][i] == 0)
				continue;

			if(plates[j][i] == plates[j+1][i]){
				markedValuePositions.push_back({j, i});
				markedValuePositions.push_back({j+1, i});
			}
		}
	}

	// plate 내부의 value 간의 인접하고 같은 값 마킹하기.

	for(int i=1;i<=N;i++){
		for(int j=0;j<M - 1;j++){
			if(plates[i][j] == 0)
				continue;
				
			if(plates[i][j] == plates[i][j+1]){
				markedValuePositions.push_back({i, j});
				markedValuePositions.push_back({i, j+1});
			}
		}

		if(plates[i][M-1] != 0 && plates[i][M-1] == plates[i][0]){
			markedValuePositions.push_back({i, 0});
			markedValuePositions.push_back({i, M-1});
		}
	}

	return markedValuePositions.size();
}

void RemoveAllMarkedValues(){
	for(auto & elem : markedValuePositions){
		plates[elem.first][elem.second] = 0;
	}
}

void DoUnmarkedAction(){
	int sum = GetSumOfPlates();
	int count = GetCountOfPlates();

	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			if(plates[i][j] != 0){
				if(plates[i][j] * count < sum){
					// 평균보다 작은 경우,
					plates[i][j]++;
				}else if(plates[i][j] * count > sum){
					// 평균보다 큰 경우,
					plates[i][j]--;
				}
			}
		}
	}
}

void SolveProblem(){
	int markedValuesCount = 0;
	for(int order = 0;order < T;order++){
		// 원판들 회전.
		SpinPlates(spinOrders[order][0], spinOrders[order][1], spinOrders[order][2]);

		// 가까운 두 수가 같은 경우들을 모두 마킹.
		markedValuesCount = MarkAllCloseSameValues();

		if(markedValuesCount != 0){
			// 마킹된 수 모두 지우기.
			RemoveAllMarkedValues();
		}else{
			// 존재하지 않는 경우 처리.
			DoUnmarkedAction();
		}

		//PrintAllPlateContents();
	}

	// 원판에 적힌 모든 숫자의 합을 계산.
	answer = GetSumOfPlates();
}

void PrintAnswer(){
	printf("%d\n", answer);
}

int main(){
	HandleInput();
	SolveProblem();
	PrintAnswer();
	return 0;
}
