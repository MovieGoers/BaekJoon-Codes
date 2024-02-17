#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, M;
vector<int> arr;
vector<int> stack;
unordered_map<int, bool> integerMap;

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
		int temp;
		cin >> temp;
		if (!integerMap[temp]) {
			arr.push_back(temp);
			integerMap[temp] = true;
		}
	}

	N = arr.size();

	sort(arr.begin(), arr.end());

	stack.push_back(-1);
	PrintDFS(0);

	return 0;
}
