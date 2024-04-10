#include <stdio.h>
#include <unordered_map>

using namespace std;

int Max(int a, int b) {
	if (a > b)
		return a;

	return b;
}

int times[1500001];
int costs[1500001];
int maxCosts[1500001];

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &times[i], &costs[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		int chosen, notChosen;

		if (i + times[i] > N) {
			maxCosts[i] = maxCosts[i + 1];
			continue;
		}

		chosen = Max(costs[i] + maxCosts[i + times[i]], maxCosts[i + 1]);
		notChosen = maxCosts[i + 1];

		maxCosts[i] = Max(chosen, notChosen);
	}

	printf("%d", maxCosts[0]);
	return 0;
}
