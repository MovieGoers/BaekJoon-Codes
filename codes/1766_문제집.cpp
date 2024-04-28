#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int problemSize, infoSize;

    scanf("%d %d", &problemSize, &infoSize);

    vector<vector<int>> nextProblems(problemSize + 1);
    vector<int> prevCnt(problemSize + 1);
    vector<bool> checked(problemSize + 1);

    for(int i=0;i<infoSize;i++){
        int A, B;
        scanf("%d %d", &A, &B);

        nextProblems[A].push_back(B);
        prevCnt[B] += 1;
    }

    priority_queue<int> Q;

	// 선수 과목이 없는 과목들을 모두 큐에 삽입.
    for(int i=1;i<=problemSize;i++){
        if(prevCnt[i] == 0){
            Q.push(-i);
            checked[i] = true;
        }
    }

    while(!Q.empty()){
        int current = -Q.top();
        Q.pop();

        printf("%d ", current);

        int nextSize = nextProblems[current].size();

        for(int i=0;i<nextSize;i++){
            prevCnt[nextProblems[current][i]] -= 1;
        }

		for(int i=0;i<nextSize;i++){
            if(prevCnt[nextProblems[current][i]] == 0){
				Q.push(-nextProblems[current][i]);
				checked[nextProblems[current][i]] = true;
			}
        }
    }

    return 0;
}
