#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int value;
	int left;
	int right;
};

int main() {
	int N;
	cin >> N;

	vector<struct Node *> nodes;

	struct Node *initialNode = (struct Node*)malloc(sizeof(struct Node));
	initialNode->value = -1;
	initialNode->left = -1;
	initialNode->right = -1;

	nodes.push_back(initialNode);

	for (int i = 0; i < N; i++) {
		// 값 입력 받기
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		int input;
		cin >> input;
		newNode->value = input;

		// left 원소 값 구하기
		newNode->left = -1;
		for (auto& node : nodes) {
			if (node->value < newNode->value) {
				if (node->left + 1> newNode->left) {
					newNode->left = node->left + 1;
				}
			}
		}

		nodes.push_back(newNode);
	}

	struct Node* lastNode = (struct Node*)malloc(sizeof(struct Node));
	lastNode->value = -1;
	lastNode->left = -1;
	lastNode->right = -1;

	nodes.push_back(lastNode);

	// right 원소 값 구하기.
	for (int i = N; i > 0; i--) {
		nodes[i]->right = -1;
		for (int j = i + 1; j <= N + 1; j++) {
			if (nodes[i]->value > nodes[j]->value) {
				if (nodes[i]->right < nodes[j]->right + 1) {
					nodes[i]->right = nodes[j]->right + 1;
				}
			}
		}
	}

	int max = -1;
	for (int i = 1; i <= N; i++) {
		if (nodes[i]->left + nodes[i]->right + 1 > max) {
			max = nodes[i]->left + nodes[i]->right + 1;
		}
	}

	cout << max;

	return 0;
}
