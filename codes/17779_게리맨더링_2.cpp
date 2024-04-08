#include <stdio.h>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int N, X, Y, d1, d2;
int A[21][21];
int divisionMap[21][21];
int minimumValue;

struct TestVariables{
	int X;
	int Y;
	int d1;
	int d2;
};

vector<TestVariables> tests;

int main(){
	minimumValue = 99999999;
	scanf("%d", &N);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d", &A[i][j]);
		}
	}

	for(int X = 1;X<N;X++){
		for(int Y = 1;Y<N;Y++){
			for(int d1 = 1;d1<=N;d1++){
				for(int d2 = 1;d2<=N;d2++){
					if(d1+d2 <= N && 1 <= Y-d1 && Y+d2 <= N)
						tests.push_back(TestVariables{X, Y, d1, d2});
				}
			}
		}
	}

	for(auto & test : tests){
		vector<int> peopleSize(5);

		for(int x=1;x<=N;x++){
			for(int y=1;y<=N;y++){
				if(1 <= x && x < test.X+test.d1 && 1 <= y &&  y <= test.Y)
					divisionMap[x][y] = 1;
				else if(1 <= x && x <= test.X+test.d2 && test.Y < y && y <= N)
					divisionMap[x][y] = 2;
				else if(test.X+test.d1 <= x && x <= N && 1 <= y && y < test.Y-test.d1+test.d2)
					divisionMap[x][y] = 3;
				else if(test.X+test.d2 < x && x <= N && test.Y-test.d1+test.d2 <= y && y <= N)
					divisionMap[x][y] = 4;
				else
					divisionMap[x][y] = 5;

				if(y >= -x + test.X + test.Y && y <= x - test.X + test.Y && y >= x - test.X + test.Y - 2 * test.d1 && y <= -x + test.X + test.Y + 2 * test.d2){
					divisionMap[x][y] = 5;
				}
			}
		}

		for(int x=1;x<=N;x++){
			for(int y=1;y<=N;y++){
				peopleSize[divisionMap[x][y] - 1] += A[x][y];
			}
		}

		sort(peopleSize.begin(), peopleSize.end());

		if(peopleSize[4] - peopleSize[0] < minimumValue)
			minimumValue = peopleSize[4] - peopleSize[0];
	}

	printf("%d\n", minimumValue);
	return 0;
}
