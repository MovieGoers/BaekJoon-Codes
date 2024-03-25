#include <stdio.h>
#include <limits.h>
#include <unordered_map>

using namespace std;

int maxVal = INT_MIN;
int minVal = INT_MAX;

int numberSize, operatorSize;
int numbers[11];
unordered_map<int, int> operatorMap;
int operatorSeq[10];

int DoOperation(int operatorSeq[10]) {
	
	int val = numbers[0];

	for (int i = 0; i < operatorSize; i++) {
		switch (operatorSeq[i]) {
		case 0:
			val += numbers[i + 1];
			break;
		case 1:
			val -= numbers[i + 1];
			break;
		case 2:
			val *= numbers[i + 1];
			break;
		case 3:
			val /= numbers[i + 1];
			break;
		default:
			break;
		}
	}
	return val;
}

void DFS(int depth) {
	if (depth == operatorSize) {
		int finalVal = DoOperation(operatorSeq);
		if (minVal > finalVal) {
			minVal = finalVal;
		}
		if (maxVal < finalVal) {
			maxVal = finalVal;
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operatorMap[i] > 0) {
			operatorMap[i] -= 1;
			operatorSeq[depth] = i;
			DFS(depth + 1);
			operatorMap[i] += 1;
		}
	}
}

int main() {
	scanf("%d", &numberSize);
	operatorSize = numberSize - 1;

	for (int i = 0; i < numberSize; i++) {
		scanf("%d", &numbers[i]);
	}

	for (int i = 0; i < 4; i++) {
		int cnt;
		scanf("%d", &cnt);
		operatorMap[i] = cnt;
	}

	DFS(0);

	printf("%d\n%d", maxVal, minVal);

	return 0;
}
