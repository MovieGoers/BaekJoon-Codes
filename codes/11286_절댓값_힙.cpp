#include <iostream>
#include <queue>

using namespace std;

int N;
long long command;
priority_queue<pair<long long, bool>, vector<pair<long long, bool>>,greater<pair<long long, bool>>> pq; // pair의 first 는 절댓값, second는 절댓값이 원래 양수였을 경우 true.

void HandleInput(){
	cin >> N;
}

void SolveProblem(){
	for(int i=0;i<N;i++){
		cin >> command;
		if(command == 0){
			if(pq.empty()){
				cout << 0 << '\n';
				continue;
			}
			long long value = pq.top().first;
			if(!pq.top().second)
				value *= -1;
			
			cout << value << '\n';
			pq.pop();
		}else{
			if(command<0){
				pq.push({command * -1, false});
			}else{
				pq.push({command, true});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	HandleInput();
	SolveProblem();

	return 0;
}
