#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<string> nameVector;
	unordered_map<string, int> nameMap;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int strSize = str.size();
		int pointIndex = -1;
		
		for (int j = 0; j < strSize; j++) {
			if (str[j] == '.') {
				pointIndex = j;
				break;
			}
		}

		string newStr = str.substr(pointIndex + 1, strSize - pointIndex);
		if (nameMap[newStr] == 0) {
			nameVector.push_back(newStr);
		}

		nameMap[newStr]++;
	}

	sort(nameVector.begin(), nameVector.end());
	int nameVectorSize = nameVector.size();

	for (int i = 0; i < nameVectorSize; i++) {
		cout << nameVector[i] << ' ' << nameMap[nameVector[i]] << '\n';
	}

	return 0;
}
