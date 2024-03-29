#include <stdio.h>
#include <memory.h>

using namespace std;

int N, M, H;
int min = 99999999;
int depthLimit = 0;

bool ladders[31][11];
bool resultFlag = false;

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool CheckLadderResult() {
	int arr[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int h = 1; h <= H; h++) {
		for (int n = 1; n < N; n++) {
			if (ladders[h][n]) {
				Swap(&arr[n], &arr[n+1]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		
		if (arr[i] != i)
			return false;
	}
	

	return true;
}

void DoDFS(int depth, int prevH) {
	if (depth == depthLimit) {
		if (CheckLadderResult()) {
			if (depth < min)
				min = depth;
		}
		return;
	}

	for (int h = prevH; h <= H; h++) {
		for (int n = 1; n < N; n++) {
			// 현재 사다리를 놓으려는 근처에 다른 사다리가 존재하는 경우,
			if (ladders[h][n - 1] || ladders[h][n] || ladders[h][n + 1]) {
				continue;
			}

			ladders[h][n] = true;
			DoDFS(depth + 1, h);
			ladders[h][n] = false;
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &H);

	memset(ladders, false, sizeof(ladders));

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ladders[a][b] = true;
	}

	for (int i = 0; i <= 3; i++) {
		depthLimit = i;
		DoDFS(0, 1);
	}

	if (min <= 3)
		printf("%d", min);
	else
		printf("-1");

	return 0;
}
