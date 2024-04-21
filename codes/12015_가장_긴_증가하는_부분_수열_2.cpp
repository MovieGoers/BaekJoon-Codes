#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000000];
int LIS[1000000];
int LISBackIndex;

void HandleInput(){
	 cin >> N;
	 for(int i=0;i<N;i++){
		cin >> arr[i];
	 }
}

int DoBinarySearch(int value, int low, int high){
	int mid = 0;

	while(low < high){
		mid = (low + high) / 2;

		if(LIS[mid] < value){
			low = mid + 1;
		}else{
			high = mid;
		}
	}

	return high;
}

void SolveProblem(){
	LISBackIndex = 0;
	// LIS에 arr의 첫 원소 삽입.
	LIS[0] = arr[0];
	int newLISIndex = -1;

	for(int i=1;i<N;i++){
		if(LIS[LISBackIndex] < arr[i]){
			// 마지막으로 LIS에 추가된 원소보다 값이 더 큰 경우. 즉, LIS back에 추가해야 할 경우.
			LISBackIndex++;
			LIS[LISBackIndex] = arr[i];	
		}else{
			// LIS의 마지막 원소보다 arr 값이 더 작은 경우,
			// 이분 탐색으로 arr 값을 넣을 LIS의 인덱스 값을 찾는다.
			newLISIndex = DoBinarySearch(arr[i], 0, LISBackIndex);

			LIS[newLISIndex] = arr[i];
		}
	}
}

void PrintAnswer(){
	cout << LISBackIndex + 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	HandleInput();
	SolveProblem();
	PrintAnswer();

	return 0;
}
