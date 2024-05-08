#include <iostream>

using namespace std;

long long A, B, C;

void HandleInput(){
    cin >> A >> B >> C;
}

long long Pow(long long b){
    if(b == 0)
        return 1;
    if(b == 1)
        return A % C;

    long long dividedResult = Pow(b/2) % C;

    if(b % 2 == 0)
        return dividedResult * dividedResult % C;
    else
        return (dividedResult * dividedResult % C) * (A % C);
}

void SolveProblem(){
    cout << Pow(B) % C <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    HandleInput();
    SolveProblem();

    return 0;
}
