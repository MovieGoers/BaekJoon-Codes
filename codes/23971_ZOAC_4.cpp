#include <stdio.h>

using namespace std;

int main(){
	int H, W, N, M;
	scanf("%d%d%d%d", &H, &W, &N, &M);

	int hSeats = 0, wSeats = 0;

	hSeats = H / (N + 1);
	if(H % (N + 1) > 0)
		hSeats++;
	
	wSeats = W / (M + 1);
	if(W % (M + 1) > 0)
		wSeats++;

	printf("%d", hSeats * wSeats);

	return 0;
}
