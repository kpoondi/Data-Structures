#include <iostream>
using namespace std;


class BST {
	class Node{ 
		public:
			int key;
			Node* left;
			Node* right;

			Node (int value) {
				this->key = value;
				this->left = nullptr;
				this->right = nullptr;
			}
	};

	public:
		Node* root;
		int max(int a, int b);
		void insert(int value, Node*& root);
		bool search(int value, Node*& root);
		void postOrder(Node*& root);
		void inOrder(Node*& root);
		void preOrder(Node*& root);
		int height(Node*& root);
		BST() {root = nullptr; }
		~BST() { }
};

int BST::height(Node*& root) {
	if (root == nullptr) return 0;
	return max(1 + height(root->left), 1 + height(root->right));
}

int BST::max(int a, int b) {
	return a > b ? a : b;
}

void BST::inOrder(Node*& root) {
	if (root == nullptr) return;
	inOrder(root->left);
	cout << root->key << endl;
	inOrder(root->right);
}

void BST::preOrder(Node*& root) {
	if (root == nullptr) return;
	cout << root->key << endl;
	preOrder(root->left);
	preOrder(root->right);
}

void BST::postOrder(Node*& root) {
	if (root == nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->key << endl;
}

void BST::insert(int value, Node*& root) {
	if (root == nullptr) {
		root = new Node(value);
	}
	else if (root->key < value) {
		BST::insert(value, root->right);
	}
	else {
		BST::insert(value, root->left);
	}
}

bool BST::search(int value, Node*& root) {
	if (root == nullptr) return false;
	if (root->key == value) return true;
	if (root->key < value) return BST::search(value, root->left);
	else return BST::search(value, root->right);
}

int main() {
	BST tree = BST(); 
	tree.insert(5,tree.root);
	tree.insert(2,tree.root);
	tree.insert(6,tree.root);
	tree.insert(7,tree.root);
	tree.insert(1,tree.root);
	tree.insert(10,tree.root);
	cout << tree.height(tree.root) << endl;
}