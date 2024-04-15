#include <iostream>

using namespace std;

int rowSize, colSize; // 3 이상, 300 이하.
int map[300][300]; // 0 이상, 10 이하. 빙산은 10000개 이하. 첫 행, 첫 열 그리고 마지막 행, 마지막 열에는 항상 0으로 채워진다.

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool visited[300][300];

int answer;
bool seperatedFlag;

void SetInitialValues(){
	seperatedFlag = false;
	answer = 0;
}

void HandleInput(){
	cin >> rowSize >> colSize;

	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			cin >> map[i][j];
		}
	}
}

bool DoesIcebergExist(){
	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			if(map[i][j] > 0)
				return true;
		}
	}

	return false;
}

void MeltIceberg(){
	int reduceMap[300][300] = {0, };

	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){

			// 각 빙산에 대해서,
			if(map[i][j] > 0){

				// 빙산 주변을 확인.
				for(int k=0;k<4;k++){
					int newRow = i+dr[k];
					int newCol = j+dc[k];

					// 맵 밖인 경우 무시.
					if(newRow < 0 || newCol < 0 || newRow >= rowSize || newCol >= colSize)
						continue;

					// 빙산에 인접한 칸이 바닷물인 경우.
					if(map[newRow][newCol] == 0){
						--reduceMap[i][j];
					}
				}
			}
		}
	}

	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			map[i][j] += reduceMap[i][j];
			if(map[i][j] < 0)
				map[i][j] = 0;
		}
	}
}

void PrintDebugMessages(){
	cout << "---------------------------\n";
	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void SetVisited(bool b){
	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			visited[i][j] = b;
		}
	}
}

void DoDFS(int row, int col){
	visited[row][col] = true;

	for(int i=0;i<4;i++){
		int newRow = row + dr[i];
		int newCol = col + dc[i];

		if(newRow < 0 || newCol < 0 || newRow >= rowSize || newCol >= colSize)
			continue;

		if(visited[newRow][newCol] || map[newRow][newCol] <= 0)
			continue;
		
		DoDFS(newRow, newCol);
	}
}

bool IsIceBergSeperated(){
	int icebergCount = 0;

	SetVisited(false);

	for(int i=0;i<rowSize;i++){
		for(int j=0;j<colSize;j++){
			if(map[i][j] > 0 && !visited[i][j]){
				++icebergCount;
				DoDFS(i, j);
			}
		}
	}

	if(icebergCount >= 2)
		return true;

	return false;
}

void SolveProblem(){
	// 빙산이 남아 있는 동안.
	while(DoesIcebergExist()){
		answer++;

		// 빙산 녹이기.
		MeltIceberg();

		//PrintDebugMessages();

		// 빙산이 두 조각 이상으로 분리되었는지 확인.
		if(IsIceBergSeperated()){
			seperatedFlag = true;
			break;
		}
	}
}

void PrintAnswer(){
	if(seperatedFlag)
		cout << answer << '\n';
	else
		cout << 0 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	SetInitialValues();
	HandleInput();
	SolveProblem();
	PrintAnswer();

	return 0;
}
