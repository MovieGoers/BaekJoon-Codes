#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
vector<int> stack;

void PrintDFS(int depth) {
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << stack[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] >= stack[depth]) {
			stack.push_back(arr[i]);
			PrintDFS(depth + 1);
			stack.pop_back();
		}
	}
}

int main() {	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	stack.push_back(-1);
	PrintDFS(0);

	return 0;
}
