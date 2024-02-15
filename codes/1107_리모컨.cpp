#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> availables;
vector<int> madeValues;
vector<int> stack;

void stuff() {

}

int abs(int a) {
	if (a < 0)
		return -1 * a;

	return a;
}

// DFS 사용 integer 생성
void DFS(int depth, int maxSize) {
	if (maxSize <= depth) {
		int value = 0;
		for (auto& elem : stack) {
			value += elem;
			value *= 10;
		}

		madeValues.push_back(value / 10);
		return;
	}

	for (auto& available : availables) {
		stack.push_back(available);
		DFS(depth + 1, maxSize);
		stack.pop_back();
	}
}

int main() {
	int N, M, min;
	unordered_map<int, bool> u_map;

	cin >> N >> M;

	int NSize = to_string(N).size();

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		u_map[temp] = true;
	}

	for (int i = 0; i < 10; i++) {
		if (!u_map[i])
			availables.push_back(i);
	}

	if (N >= 100) {
		min = N - 100;
	}
	else {
		min = 100 - N;
	}

	if (NSize - 1 >= 1) {
		DFS(0, NSize - 1);
	}
	DFS(0, NSize);
	DFS(0, NSize + 1);

	for (auto& elem : madeValues) {
		int elemSize = to_string(elem).size();
		if (min > abs(N - elem) + elemSize) {
			min = abs(N - elem) + elemSize;
		}
	}

	cout << min << '\n';

	return 0;
}