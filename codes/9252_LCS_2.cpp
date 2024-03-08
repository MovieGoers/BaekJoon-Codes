#include <iostream>
#include <string>
#include <vector>

using namespace std;

int DP[1001][1001] = { 0, };
char from[1001][1001] = { '.', }; // 'L' : 왼쪽으로부터, 'U' : 위로부터, 'D' : 대각선으로부터.
char LCS[1000];

int Max(int A, int B) {
	if (A > B)
		return A;
	
	return B;
}

int main() {
	string str1, str2;

	int str1Size, str2Size;

	cin >> str1 >> str2;

	str1Size = str1.size();
	str2Size = str2.size();

	for (int i = 1; i <= str1Size; i++) {
		for (int j = 1; j <= str2Size; j++) {
			if (str1[i-1] == str2[j-1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
				from[i][j] = 'D';
			}
			else {
				if (DP[i - 1][j] > DP[i][j - 1]) {
					DP[i][j] = DP[i - 1][j];
					from[i][j] = 'U';

				}
				else {
					DP[i][j] = DP[i][j-1];
					from[i][j] = 'L';
				}
			}
				
		}
	}

	int LCSindex = 0;
	int LCSlen = DP[str1Size][str2Size];
	int LCSlen2 = DP[str1Size][str2Size];

	printf("%d\n", LCSlen);

	int str1Index = str1Size, str2Index = str2Size;
	while (LCSlen >= 1) {
		if (from[str1Index][str2Index] == 'D') {
			LCS[LCSindex] = str1[str1Index-1];
			str1Index--;
			str2Index--;
			LCSlen--;
			LCSindex++;
		}
		else if (from[str1Index][str2Index] == 'L') {
			str2Index--;
		}
		else{
			str1Index--;
		}
	}

	for (int i = LCSlen2 - 1; i >= 0; i--) {
		printf("%c", LCS[i]);
	}

	return 0;
}
