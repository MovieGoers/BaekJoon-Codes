#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
int S[21][21];

int team1[10];
int team2[10];

int minDiff = 99999999;

int Abs(int a) {
    if (a < 0)
        return -a;
    
    return a;
}

void DFS(int prev, int cnt) {
    if (cnt == N / 2) {
        int index = 0;
        unordered_map<int, bool> uMap;
        for (int i = 0; i < cnt; i++) {
            uMap[team1[i]] = true;
        }

        for (int i = 1; i <= N; i++) {
            if (uMap[i] == false) {
                team2[index] = i;
                index++;
            }
        }

        int team1Sum = 0;
        int team2Sum = 0;

        for (int i = 0; i < N / 2; i++) {
            for (int j = i + 1; j < N / 2; j++) {
                team1Sum += (S[team1[i]][team1[j]] + S[team1[j]][team1[i]]);
                team2Sum += (S[team2[i]][team2[j]] + S[team2[j]][team2[i]]);
            }
        }

        int diff = Abs(team1Sum - team2Sum);

        if (diff < minDiff) {
            minDiff = diff;
        }
        return;
    }

    for (int i = prev+1; i <= N; i++) {
        team1[cnt] = i;
        DFS(i, cnt + 1);
    }
};

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }

    DFS(0, 0);

    cout << minDiff;

    return 0;
}
