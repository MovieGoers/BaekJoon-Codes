#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int main(){
	int N, cnt = 0;
	char play;
	unordered_map<string, bool> boolMap;

	cin >> N >> play;

	for(int i=0;i<N;i++){
		string str;
		cin >> str;

		if(!boolMap[str]){
			boolMap[str] = true;
			cnt++;
		}
	}

	int div = 0;

	switch(play){
		case 'Y':
		div = 1;
		break;
		case 'F':
		div = 2;
		break;
		case 'O':
		div = 3;
		break;
	}

	cout << cnt / div;

	return 0;
}
