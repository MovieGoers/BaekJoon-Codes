#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Gear {
	int NS[8];
	int leftIndex;
	int rightIndex;
};

int main() {
	Gear gears[4];
	int instructionSize;
		
	for (int i = 0; i < 4; i++) {
		string inputStr;
		cin >> inputStr;
		for (int j = 0; j < 8; j++) {
			gears[i].NS[j] = inputStr[j] - '0';
		}
		// input은 12시 방향으로부터 주어지므로 leftIndex는 -2(6) 이어야 한다.
		gears[i].leftIndex = 6;
		gears[i].rightIndex = 2;
	}

	cin >> instructionSize;

	for (int i = 0; i < instructionSize; i++) {
		int gearToRotate, rotationDirection;

		// 0 index는 A와 B가 서로 다른 극일때 true, 1은 B와 C, 2는 C와 D.
		bool isConnected[3]; 

		// -1은 반시계, 1은 시계.
		int mustSpin[4] = { 0, };

		cin >> gearToRotate >> rotationDirection;

		gearToRotate -= 1;
		mustSpin[gearToRotate] = rotationDirection;

		// 가까운 기어들간의 관계 파악.
		for (int j = 0; j < 3; j++) {
			if (gears[j].NS[gears[j].rightIndex] != gears[j + 1].NS[gears[j + 1].leftIndex])
				isConnected[j] = true;
			else
				isConnected[j] = false;
		}

		// 회전시킬 기어 확인. (기어 번호, 방향)

		// 오른쪽 방향으로 확인. 0 -> 1 -> 2
		for (int j = gearToRotate; j < 3; j++) {
			if (isConnected[j])
				mustSpin[j + 1] = mustSpin[j] * -1;
			else
				break;
		}

		// 그 다음 왼쪽 방향으로 확인. 3 -> 2 -> 1
		for (int j = gearToRotate; j > 0; j--) {
			if (isConnected[j-1])
				mustSpin[j - 1] = mustSpin[j] * -1;
			else
				break;
		}

		// 회전시키기.
		for (int j = 0; j < 4; j++) {
			if (mustSpin[j] == 1) // 시계
			{
				gears[j].leftIndex = (gears[j].leftIndex + 7) % 8;
				gears[j].rightIndex = (gears[j].leftIndex + 4) % 8;
			}

			if (mustSpin[j] == -1) // 반시계
			{
				gears[j].leftIndex = (gears[j].leftIndex + 1) % 8;
				gears[j].rightIndex = (gears[j].leftIndex + 4) % 8;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (gears[i].NS[(gears[i].leftIndex + 2) % 8] == 1) {
			sum += pow(2, i);
		}
	}

	cout << sum;

	return 0;
}
