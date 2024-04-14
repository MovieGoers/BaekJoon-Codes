#include <stdio.h>

using namespace std;

int N; // 지역의 크기 (N x N), 2 이상 100 이하.
int heights[100][100]; // 각 지역의 높이. 각 높이는 1 이상 100 이하.
int minHeight, maxHeight; // 지역 내 최소, 최대 높이.

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool isWatered[100][100]; // 각 지역이 물에 잠겼는지 저장.
bool visited[100][100];

int answer;

void SetInitialValues(){
	minHeight = 101;
	maxHeight = 0;

	answer = 1;
}

void HandleInput(){
	scanf("%d", &N);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &heights[i][j]);
		}
	}
}

void SetIsWatered(bool value){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			isWatered[i][j] = value;
		}
	}
}

void SetVisited(bool value){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j] = value;
		}
	}
}

void FillWater(int waterHeight){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(waterHeight >= heights[i][j]){
				isWatered[i][j] = true;
			}
		}
	}
}

void DoDFS(int row, int col){
	visited[row][col] = true;

	for(int i=0;i<4;i++){
		int newRow = row + dr[i];
		int newCol = col + dc[i];

		if(newRow < 0 || newCol < 0 || newRow >= N || newCol >= N)
			continue;
		
		if(visited[newRow][newCol] || isWatered[newRow][newCol])
			continue;
		
		DoDFS(newRow, newCol);
	}
}

int CountSafeAreas(){
	int count = 0;

	SetVisited(false);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!isWatered[i][j] && !visited[i][j]){
				DoDFS(i, j);
				count++;
			}
		}
	}

	return count;
}

void PrintDebug(int waterH, int safeAreaCount){
	printf("------------- Water Height : %d -------------\n", waterH);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(isWatered[i][j]){
				printf("0 ");
			}else{
				printf("%d ", heights[i][j]);
			}
		}
		printf("\n");
	}
	printf("Safe Area Quantity : %d\n", safeAreaCount);
	printf("---------------------------------------------\n");
}

void SolveProblem(){
	// 지역 내 최소, 최대 높이를 구한다.
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(heights[i][j] < minHeight)
				minHeight = heights[i][j];
			
			if(heights[i][j] > maxHeight)
				maxHeight = heights[i][j];
		}
	}

	SetIsWatered(false);

	// 차오른 물의 높이를 1씩 증가시키며 물에 잠기지 않은 영역 개수 구함.
	for(int waterH = minHeight; waterH < maxHeight; waterH++){
		// 물 채우기.
		FillWater(waterH);

		// 안전한 지역의 수를 구함.
		int safeAreaCount = CountSafeAreas();

		//PrintDebug(waterH, safeAreaCount);

		// 최대 안전 지역의 수인지 확인 후 answer 업데이트.
		if(safeAreaCount > answer)
			answer = safeAreaCount;
	}

}

void PrintAnswer(){
	printf("%d\n", answer);
}

int main(){
	SetInitialValues();
	HandleInput();
	SolveProblem();
	PrintAnswer();

	return 0;
}
