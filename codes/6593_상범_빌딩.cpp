#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int L, R, C;
char building[30][30][30];
bool visited[30][30][30];
bool isTrapped;
int length;

int dr[6] = {0, 0, -1, 1, 0, 0};
int dc[6] = {1, -1, 0, 0, 0, 0};
int dl[6] = {0, 0, 0, 0, -1, 1};

struct position{
    int l;
    int r;
    int c;
    int count;
};

position start;

bool HandleInputs(){
    cin >> L >> R >> C;
    if(L == 0 && R == 0 && C == 0)
        return false;

    for(int l=0;l<L;l++){
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                cin >> building[l][r][c];

                if(building[l][r][c] == 'S')
                    start = {l, r, c, 0};
            }
        }
    }

    return true;
}
void SolveProblem(){
    memset(visited, false, sizeof(visited));
    isTrapped = true;
    length = 0;

    queue<position> Q;
    Q.push(start);
    visited[start.l][start.r][start.c] = true;

    while(!Q.empty()){
        position curr = Q.front();
        Q.pop();

        for(int i=0;i<6;i++){
            position next = {curr.l + dl[i], curr.r + dr[i], curr.c + dc[i], curr.count + 1};

            if(next.l < 0 || next.c < 0 || next.r < 0 || next.l >= L || next.c >= C || next.r >= R)
                continue;

            if(building[next.l][next.r][next.c] == 'E'){
                isTrapped = false;
                length = next.count;
                break;
            }

            if(building[next.l][next.r][next.c] == '#' || visited[next.l][next.r][next.c])
                continue;

            visited[next.l][next.r][next.c] = true;
            Q.push(next);
        }
    }
}

void PrintAnswer(){
    if(!isTrapped)
        cout << "Escaped in "<<length<<" minute(s).\n";
    else
        cout << "Trapped!\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true){
        if(!HandleInputs()){
            break;
        }
        SolveProblem();
        PrintAnswer();
    }
    return 0;
}
