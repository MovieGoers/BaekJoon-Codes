#include <stdio.h>

int main(){
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);

	if(A + B + C == 180){
		if(A == B && B == C)
			printf("Equilateral");
		else{
			if(A == B || B == C || C == A)
				printf("Isosceles");
			else
				printf("Scalene");
		}
	}else{
		printf("Error");
	}
	return 0;
}
