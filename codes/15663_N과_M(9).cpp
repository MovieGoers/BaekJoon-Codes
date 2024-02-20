#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
vector<int> stack;
vector<int> vec;
unordered_map<string, bool> checkMap;
unordered_map<int, int> usedMap;

void DFS(int depth) {
	if (depth == M) {
		string newStr = "";
		for (auto& elem : stack) {
			newStr += to_string(elem);
			newStr += ".";
		}
		if (!checkMap[newStr]) {
			checkMap[newStr] = true;
			for (auto& elem : stack) {
				cout << elem << ' ';
			}
			cout << '\n';
		}

		return;
	}

	for (int i = 0; i < N; i++) {
		if (usedMap[vec[i]] == 0)
			continue;

		stack.push_back(vec[i]);
		usedMap[vec[i]]--;
		DFS(depth + 1);
		stack.pop_back();
		usedMap[vec[i]]++;
	}
};

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
		usedMap[temp]++;
	}

	sort(vec.begin(), vec.end());

	DFS(0);

	return 0;
}
