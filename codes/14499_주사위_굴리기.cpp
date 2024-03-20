#include <stdio.h>

using namespace std;

int dH[5] = {0, 0, 0, -1, 1};
int dW[5] = {0, 1, -1, 0, 0};

void RollDice(int dice[7], int direction){
	int temp = dice[1];

	switch(direction){
		case 1:
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
			break;
		case 2:
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
			break;
		case 3:
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
			break;
		case 4:
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
			break;
		default:
			break;
	}
}

int main(){
	int height, width;
	int diceH, diceW;
	int commandSize;
	int map[20][20];
	int dice[7] = {0, }; // dice[1]은 윗면, dice[3]은 동쪽을 바라보는 면.

	scanf("%d%d%d%d%d", &height, &width, &diceH, &diceW, &commandSize);

	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int i=0;i<commandSize;i++){
		int direction; // 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4.
		scanf("%d", &direction);

		int newDiceH = diceH + dH[direction];
		int newDiceW = diceW + dW[direction];

		// 주사위가 맵 밖으로 나갈 경우 확인.
		if(newDiceH < 0 || newDiceH >= height || newDiceW < 0 || newDiceW >= width)
			continue;

		// 주사위 이동.
		diceH = newDiceH;
		diceW = newDiceW;
		RollDice(dice, direction);
		
		if(map[diceH][diceW] == 0){
			// 주사위 바닥 면에 있는 숫자가 map에 복사된다.
			map[diceH][diceW] = dice[6];
		}
		else{
			// map에 쓰여진 숫자가 주사위 바닥면에 복사되고 map에는 0이 쓰여진다.
			dice[6] = map[diceH][diceW];
			map[diceH][diceW] = 0;
		}

		printf("%d\n", dice[1]);
	}

	return 0;
}
