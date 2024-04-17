#include <iostream>
#include <unordered_map>

using namespace std;

int N, S;
int arr[21];
unordered_map<int,  int> sumCount; // 키 값은 부분 수열의 합, value 값은 그런 합이 나온 부분 수열의 총 개수.
long long answer;

void HandleInput(){
	cin >> N >> S;

	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
}

// current는 현재 고려중인 arr의 index, sum은 current까지의 arr의 부분 집합의 합.
void HandleLeft(int current, int sum){
	// 전체 수열 arr의 좌측 절반에 대해서, 부분 수열을 구한 경우,
	if(current == N / 2){
		// 해시맵에 이미 구한 부분 수열의 합을 key 값으로 하고, value를 그 합이 나온 횟수로 저장하도록 한다.
		sumCount[sum]++;
		return;
	}
	
	// current 인덱스의 arr 값을 선택하지 않았을 때,
	HandleLeft(current + 1, sum);

	// current 인덱스의 arr 값을 선택했을 때,
	HandleLeft(current + 1, sum + arr[current]);
}

// current는 현재 고려중인 arr의 index, sum은 current까지의 arr의 부분 집합의 합.
void HandleRight(int current, int sum){
	// 전체 수열 arr의 우측 절반에 대해서, 부분 수열을 구한 경우,
	if(current == N){
		// S - sum는 찾으려는 값 S에다 현재 구한 우측 절반의 부분 수열의 합인 sum을 빼는 것.
		// 따라서 S - sum을 키 값으로 가지는 sumCount[S - sum]가 존재한다는 것은 (1 이상),
		// 이전에 구했던 좌측 절반의 부분 수열의 합과 sum을 더할 때 S가 되는 경우가 존재한다는 것이므로, (좌측 sum = S - 우측 sum)
		// sumCount[S - sum]는 곧 좌측 부분 수열과 우측 부분 수열의 합이 S가 되는(좌측 sum + 우측 sum = S) 모든 경우의 수를 나타낸다.
		answer += sumCount[S - sum];
		return;
	}

	// current 인덱스의 arr 값을 선택하지 않았을 때,
	HandleRight(current + 1, sum);

	// current 인덱스의 arr 값을 선택했을 때,
	HandleRight(current + 1, sum + arr[current]);
}

void SolveProblem(){
	// 전체 arr의 좌측 절반에 대해서 해시맵을 구한다.
	// 이때 해시 맵에 담기는 내용은 각 부분수열의 합에 대해서 그 합이 나오는 총 횟수이다.
	HandleLeft(0, 0);

	// 전체 arr의 우측 절반에 대해서 해시맵을 구한다.
	HandleRight(N / 2, 0);
}

void PrintAnswer(){
	if(S == 0){
		// S가 0인 경우, answer에 좌측, 우측의 부분 수열이 모두 공집할일 때의 경우를 포함하고 있다.
		// 따라서 이 경우는 크기가 양수인 부분수열이라는 조건에 부합하지 않으므로 빼주어야 한다.
		cout << answer - 1<< '\n';
	}	
	else
		cout << answer << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	HandleInput();
	SolveProblem();
	PrintAnswer();

	return 0;
}
