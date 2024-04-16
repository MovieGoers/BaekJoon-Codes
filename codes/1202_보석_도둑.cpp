#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
pair<int, int> jewelry[300000];
int bags[300000];
priority_queue<int> pq;

long long answer;

void HandleInput(){
	cin >> N >> K;

	for(int i=0;i<N;i++){
		cin >> jewelry[i].first >> jewelry[i].second;
	}

	for(int i=0;i<K;i++){
		cin >> bags[i];
	}
}

void SolveProblem(){
	answer = 0;

	// 보석의 무게, 가방의 무게를 오름차순으로 정렬.
	sort(jewelry, jewelry + N);
	sort(bags, bags + K);

	int jewelIndex = 0;

	// 각 가방에 대해서,
	for(int i = 0;i<K;i++){
		// 현재 가방의 최대 무게보다 작거나 같은 무게의 모든 보석을 우선순위 큐에 입력.
		// 큐에 입력되는 값은 보석의 value.
		while(bags[i] >= jewelry[jewelIndex].first && jewelIndex < N){
			pq.push(jewelry[jewelIndex].second);
			++jewelIndex;
		}

		if(!pq.empty()){
			// 현재 가방에 넣을 수 있는 모든 보석들 중 가격이 가장 높은 보석의 값을 Pop.
			answer += pq.top();
			pq.pop();
		}
	}
}

void PrintAnswer(){
	cout << answer << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	HandleInput();
	SolveProblem();
	PrintAnswer();

	return 0;
}
