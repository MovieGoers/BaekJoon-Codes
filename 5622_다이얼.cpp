#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int GetNumberFromDial(char dial) {
	if (dial <= 'O') {
		return (dial - 'A' + 6) / 3;
	}
	else if ('O' < dial && dial <= 'S') {
		return 7;
	}
	else if('S' < dial && dial <= 'V') {
		return 8;
	}
	else {
		return 9;
	}
}

int main() {
	string dials;

	cin >> dials;
	int dialsSize = dials.size();
	int sum = 0;

	for (int i = 0; i < dialsSize; i++) {
		sum += GetNumberFromDial(dials[i]);
		sum += 1;
	}

	cout << sum;

	return 0;
}
