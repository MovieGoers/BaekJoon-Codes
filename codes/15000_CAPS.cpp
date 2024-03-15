#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;

	transform(str.begin(), str.end(), str.begin(), ::toupper);

	cout << str;

	return 0;
}
