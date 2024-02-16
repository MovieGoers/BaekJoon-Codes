#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int personSize, partySize;
bool graph[51][51] = { false, };
unordered_map<int, bool> doesKnow;

void MakeGraph(vector<int> party) {
	int partySize = party.size();
	for (int i = 0; i < partySize - 1; i++) {
		for (int j = i + 1; j < partySize; j++) {
			graph[party[i]][party[j]] = true;
			graph[party[j]][party[i]] = true;
		}
	}
};

void CheckAllNewKnowers(int knower) {
	for (int i = 1; i <= personSize; i++) {
		if (graph[knower][i]) {
			if (doesKnow[i] == false) {
				doesKnow[i] = true;
				CheckAllNewKnowers(i);
			}
		}
	}
}

int main() {
	cin >> personSize >> partySize;

	int knowerSize;
	vector<int> knowers;
	
	cin >> knowerSize;
	for (int i = 0; i < knowerSize; i++) {
		int knower;
		cin >> knower;
		doesKnow[knower] = true;
		knowers.push_back(knower);
	}

	vector<vector<int>> parties(50);

	for (int i = 0; i < partySize; i++) {
		int personSize;
		cin >> personSize;
		for (int j = 0; j < personSize; j++) {
			int person;
			cin >> person;
			parties[i].push_back(person);
		}
		MakeGraph(parties[i]);
	}

	for (int i = 0; i < knowerSize; i++) {
		CheckAllNewKnowers(knowers[i]);
	}
	
	int cnt = 0;

	for (int i = 0; i < partySize; i++) {
		int personSize;
		bool flag = false;
		personSize = parties[i].size(); 
		for (int j = 0; j < personSize; j++) {
			if (doesKnow[parties[i][j]]) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
