#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, strSize, cnt = 0;
	string str;

	cin >> N >> strSize >> str;

	for (int i = 0; i < strSize; i++) {
		int IOILen = 0;

		if (str[i] == 'I') {	
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				IOILen++;

				if (N == IOILen) {
					cnt++;
					IOILen--;
				}

				i += 2;
			}
		}
	}
	
	cout << cnt;

	return 0;
}
