#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;



int main() {
	int TCSize;

	scanf("%d", &TCSize);

	for (int i = 0; i < TCSize; i++) {
		int goal;
		int buildingSize, ruleSize;
		int buildTimes[1001] = {0, }; // buildTime[2] -> 2번 건물의 건설 소요 시간.

		scanf("%d %d", &buildingSize, &ruleSize);

		for (int j = 1; j <= buildingSize; j++) {
			scanf("%d ", &buildTimes[j]);
		}

		int A, B;
		vector<int> prevBuildings[1001]; // prevBuildings[8] : 3, 5, 7  ->  8번 건물이 지어지기 위한 선수 빌딩들.
		vector<int> nextBuildings[1001]; // nextBuildings[8] : 3, 5, 7  ->  8번 건물이 선수 건물인 빌딩들.
		unordered_map<int, int> fanIn; // fanIn[4] = 5 -> 4번 건물을 짓기 위한 선수 건물들의 총 개수.

		for (int j = 0; j < ruleSize; j++) {
			scanf("%d %d", &A, &B);

			// 간선 생성.
			prevBuildings[B].push_back(A);
			nextBuildings[A].push_back(B);
			fanIn[B]++;
		}

		scanf("%d", &goal);

		int totalBuildTimes[1001] = {0, }; // totalBuildTimes[8] = 10 -> 8번 건물을 짓기위한 총 소요 시간.
		queue<int> Q;
		unordered_map<int, bool> checked;

		for (int j = 1; j <= buildingSize; j++) {
			if (fanIn[j] == 0) {
				checked[j] = true;
				Q.push(j);
			}
				
		}

		while (!Q.empty()) {


			// 1. 큐 Pop
			int currentBuilding = Q.front();
			Q.pop();

			// 2. currentBuilding의 이전 소요 시간들 중 max인 값 구하기.
			int prevMax = 0;
			int prevBuildingsSize = prevBuildings[currentBuilding].size();

			for (int j = 0; j < prevBuildingsSize; j++) {
				int prevBuilding = prevBuildings[currentBuilding][j];
				int prevTotalBuildTime = totalBuildTimes[prevBuilding];

				if (prevMax < prevTotalBuildTime) {
					prevMax = prevTotalBuildTime;
				}
			}

			int nextBuildingsSize = nextBuildings[currentBuilding].size();

			// 현재 고려중인 건물 다음 순서의 건물들의 fanIn - 1.
			for (int j = 0; j < nextBuildingsSize; j++) {
				fanIn[nextBuildings[currentBuilding][j]]--;
			}

			// 3. totalBuildTime 업데이트.
			totalBuildTimes[currentBuilding] = prevMax + buildTimes[currentBuilding];

			// 4. 다음 fanIn이 0인 모든 건물들 큐에 Push.

			for (int j = 1; j <= buildingSize; j++) {
				if (fanIn[j] == 0 && checked[j] == false) {
					checked[j] = true;
					Q.push(j);
				}
					
			}
			
		}
		printf("%d\n", totalBuildTimes[goal]);
	}
	
	return 0;
}
