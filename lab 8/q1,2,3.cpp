
#include<iostream>
using namespace std;
template<class T>
class TNode
{
public:
	T data;
	TNode* left;
	TNode* right;
	TNode()
	{
		left = right = nullptr;
	}
};
template<class T>
class BTree
{
private:
	TNode<T>* root;

public:
	TNode<T>* getRoot() {
		return root;
	}
	BTree()
	{
		root = nullptr;
	}

	void Insert(TNode<T>*& r, T d)
	{
		if (r == nullptr)
		{
			r = new TNode<T>;
			r->data = d;
			r->left = r->right = nullptr;
		}
		if (d < r->data)
		{
			Insert(r->left, d);
		}
		else if (d > r->data)
		{
			Insert(r->right, d);
		}
	}

	void INsert(T d)
	{
		Insert(root, d);
	}



	void destroy(TNode<T>* r)
	{
		if (r != nullptr)
		{
			
		}
	}


	int countleaf(TNode<T>* r)
	{
		if (r == nullptr)
			return 0;
		if (r->left == nullptr && r->right == nullptr)
			return 1;
		else
			return countleaf(r->left) + countleaf(r->right);
	}
	int Countleaf()
	{
		return countleaf(root);
	}



	void PrintSorted(TNode<T>* r)
	{
		if (r != nullptr)
		{
			PrintSorted(r->left);
			cout << r->data << endl;;
			PrintSorted(r->right);
		}
	}

	void Print()
	{
		PrintSorted(root);
	}
	void swaptree() {
		T temp;
		temp = root->right->right->data;
		root->right->right->data = root->right->left->data;
		root->right->left->data = temp;
	}

	void fixtree() {
		if (root->right->right != nullptr && root->right->left!=nullptr) {
			if (root->right->right->data < root->right->left->data) {
				swaptree();
			}

			else {
				return;
			}
		}
	}




	~BTree()
	{
		destroy(root);
	}



};
bool flip(TNode<int>* r, TNode<int>* r1)
{
	if (r == r1)
		return true;
	if (r == nullptr || r1 == nullptr || r->data != r1->data)
		return false;
	return(flip(r->left, r1->left) && flip(r->right, r1->right) || flip(r->left, r1->right) && flip(r->right, r1->left));


}
bool flipe(BTree<int> t1, BTree<int> t2)
{
	return flip(t1.getRoot(), t2.getRoot());
}




int main()
{
	BTree<int> t1;
	t1.INsert(4);
	t1.INsert(2);
	t1.INsert(6);
	t1.INsert(1);
	t1.INsert(3);
	t1.INsert(5);
	t1.INsert(7);

	BTree<int> t2;
	t2.INsert(4);
	t2.INsert(6);
	t2.INsert(2);
	t2.INsert(3);
	t2.INsert(1);
	t2.INsert(7);
	t2.INsert(5);

	int c = t1.Countleaf();
	cout << "number of leaf node" << "  " << c << endl;
	bool a = flipe(t1, t2);
	if (a == 1)
		cout << "equal  " << " " << a << endl;
	else  if (a == 0)
		cout << "not equal  " << " " << a << endl;
	BTree<int> t3;
	t3.INsert(4);
	t3.INsert(6);
	t3.INsert(2);
	t3.INsert(3);
	t3.INsert(1);
	cout << "after fixing t3 which is one step away from becoming bst" << endl;
	t3.fixtree();
	t3.Print();



	system("pause");
	return 0;
}
