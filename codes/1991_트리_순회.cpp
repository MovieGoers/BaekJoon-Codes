#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
	char root;
	char left;
	char right;
};

struct Node* rootNode;

unordered_map<char, struct Node*> rootMap;

void Preorder(char ch) {
	cout << ch;

	if(rootMap[ch]->left != '.')
		Preorder(rootMap[ch]->left);
	if (rootMap[ch]->right != '.')
		Preorder(rootMap[ch]->right);
};

void Inorder(char ch) {
	if (rootMap[ch]->left != '.')
		Inorder(rootMap[ch]->left);

	cout << ch;

	if (rootMap[ch]->right != '.')
		Inorder(rootMap[ch]->right);
}

void Postorder(char ch) {
	if (rootMap[ch]->left != '.')
		Postorder(rootMap[ch]->left);

	if (rootMap[ch]->right != '.')
		Postorder(rootMap[ch]->right);

	cout << ch;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		struct Node* newRootNode = (struct Node*)malloc(sizeof(struct Node));
		rootMap[root] = newRootNode;

		newRootNode->root = root;
		newRootNode->left = left;
		newRootNode->right = right;
	}

	Preorder('A');
	cout << '\n';
	Inorder('A');
	cout << '\n';
	Postorder('A');

	return 0;
}
