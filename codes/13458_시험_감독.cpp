#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int roomSize;
	int mainSupervisor, subSupervisor;
	scanf("%d", &roomSize);

	vector<int> personSize(roomSize);

	for (int i = 0; i < roomSize; i++) {
		int person;
		scanf("%d", &person);

		personSize[i] = person;
	}

	scanf("%d%d", &mainSupervisor, &subSupervisor);

	long long int total = 0;
	for (int i = 0; i < roomSize; i++) {
		personSize[i] -= mainSupervisor;
		if (personSize[i] < 0)
			personSize[i] = 0;
		total++;

		if (personSize[i] == 0)
			continue;

		total += ((personSize[i] - 1) / subSupervisor + 1);
	}

	printf("%lld", total);

	return 0;
}
