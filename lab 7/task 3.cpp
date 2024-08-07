#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node() {
		left = right = NULL;
	}
};
class BST {


	Node* root;
public:
	BST() {
		root = NULL;
	}
	bool insert(int data, Node*& root) {
		if (root == NULL) {
			root = new Node;
			root->data = data;
			return 1;
		}
		if (data == root->data)
			return 0;

		if (root->data < data) {
			insert(data, root->right);
		}
		else {
			insert(data, root->left);
		}
	}

	void insertRec(int d) {
		insert(d, root);
	}

	void print() {
		print(root);
	}
	void print(Node* root) {
		cout << root->data << " ";
		if (root->right)
			print(root->right);
		if (root->left)
			print(root->left);
	}
	bool search(Node* root, int d) {
		if (root == NULL)
			return 0;
		if (root->data == d)
			return 1;
		if (root->data > d) {
			return search(root->left, d);
		}
		else
			return search(root->right, d);
	}
	bool search(int d) {
		return search(root, d);
	}

	int lenght(Node* root) {
		if (root == NULL)
			return 0;
		return lenght(root->right) + lenght(root->left) + 1;
	}

	int lenght() {
		return lenght(root);
	}

	void copy(Node*& r1, Node* r2) {
		if (!r2) {
			r1 = NULL;
			return;
		}
		if (r1 == NULL)
			r1 = new Node;
		r1->data = r2->data;
		copy(r1->right, r2->right);
		copy(r1->left, r2->left);
	}

	int minimum() {
		Node* curr = root;
		while (curr->left)
			curr = curr->left;
		return curr->data;
	}
	int maximum() {
		Node* curr = root;
		while (curr->right)
			curr = curr->right;
		return curr->data;
	}

	BST(BST& obj) {
		if (obj.root == NULL)
			return;
		copy(root, obj.root);
	}
};

int main() {
	BST tree;

	tree.insertRec(500);
	tree.insertRec(1000);
	tree.insertRec(1);
	tree.insertRec(600);

	tree.insertRec(700);
	tree.insertRec(10);
	tree.insertRec(30);
	tree.insertRec(9000);
	tree.insertRec(50000);
	tree.insertRec(20);

	cout << "\n COPY CONSTRUCTOR" << endl;
	BST tree1(tree);
	tree1.print();
	cout << endl << endl << "Tree Lenght: " << tree.lenght() << endl;

	cout << "\nSearch \n ";

	if (tree.search(1)) {
		cout << "Found" << endl;
	}
	else
		cout << "Not found" << endl;


	if (tree.search(123)) {
		cout << "Found" << endl;
	}
	else
		cout << "Not found" << endl;

	cout << "Maximum of tree is " << tree.maximum() << endl;
	cout << "Minimum of tree is " << tree.minimum() << endl;
}