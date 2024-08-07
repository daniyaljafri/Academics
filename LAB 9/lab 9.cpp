
#include<iostream>
using namespace std;
template<class T>
class TNode
{
public:
	T data;
	TNode* left;
	TNode* right;
	int height;
	TNode()
	{
		left = right = nullptr;
		height = 0;
	}
	TNode(int d, TNode* r, TNode* l, int h)
	{
		left = l; right = r;
		height = h;
		data = d;
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
	int max(int n, int m)
	{
		if (n > m)
			return n;
		else if (n <= m)
			return m;


	}

	void Insert(TNode<T>*& r, T d)
	{
		if (r == nullptr)
			r = new TNode<T>(d, nullptr, nullptr, 0);
		else
		{
			if (d < r->data)
			{
				Insert(r->left, d);
				if (geth(r->left) - geth(r->right) == 2)
				{
					if (d < r->left->data)
						rotateright(r);
					else
						doublerotateright(r);

				}
			}
			else if (d > r->data)
			{
				Insert(r->right, d);
				if (geth(r->left) - geth(r->right) == -2) {
					if (d > r->right->data)
						rotateleft(r);
					else
						doublerotateleft(r);
				}

			}
			
		}
		r->height = 1 + max(geth(r->left), geth(r->right));
	}
	void wrapperInsert(T d)
	{
		Insert(root, d);
	}
	T geth(TNode<T>*r)
	{
		if (r == nullptr)
			return -1;
		else
			return r->height;
	}
	void rotateleft(TNode<T>*& x)
	{
		TNode<T>* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = 1 + max(geth(x->left), geth(x->right));
		y->height = 1 + max((x->height), geth(y->right));
		x = y;
	}
	void rotateright(TNode<T>*& x)
	{
		TNode<T>* y = x->left;
		x->left = y->right;
		y->right = x;
		x->height = 1 + max(geth(x->right), geth(x->left));
		y->height = 1 + max(x->height, geth(y->left));
		x = y;
	}
	void doublerotateleft(TNode<T>*& x)
	{
		rotateright(x->right);
		rotateleft(x);
	}
	void doublerotateright(TNode<T>*& x)
	{
		rotateright(x->left);
		rotateleft(x);
	}
	int blancefactor(TNode<T>* n)
	{

		if (n->left != nullptr && n->right != nullptr)
			return(n->left->height - n->right->height);
		if (n->left->height != nullptr && n->right->height == nullptr)
			return (n->left->height);
		if (n->left->height == nullptr && n->right->height != nullptr)
			return (n->right->height);
	}
	T findmin(TNode<T>* r)
	{
		if (r == nullptr)
			return 0;
		else if (r->left == nullptr)
			return r->data;

		return(findmin(r->left));


	}
	void wrapperfindmin()
	{
		cout<< findmin(root);
		

	}

	T secondfindmin(TNode<T>*r)
	{
		if (r == nullptr)
			return 0;
		else if (r->left->left == nullptr)
			return r->data;
			return (secondfindmin(r->left));


	}
	T wrappersecondfindmin()
	{
		T a = secondfindmin(root);
		return a;

	}
	void inorderprint(TNode<T>* r)
	{
		if (r != nullptr) {
			inorderprint(r->left);
			cout << r->data;
			inorderprint(r->right);
		}
	}
	void postorderprint(TNode<T>* r)
	{
		if (r != nullptr) {
			cout << endl << "left tree" << endl;
			inorderprint(r->left);
			cout << endl << "right tree" << endl;
			inorderprint(r->right);
			cout << endl << "root" << endl;
			cout << r->data;
		}

	}
	void preorderprint(TNode<T>* r)
	{
		if (r != nullptr) {
			cout << endl << "root" << endl;
			cout << r->data;
			cout << endl << "left tree" << endl;
			inorderprint(r->left);
			cout << endl << "right tree" << endl;
			inorderprint(r->right);

		}
	}
	void wrapperprint()
	{
		cout << endl << "inorder" << endl;
		inorderprint(root);
		cout << endl << "postorder" << endl;
		postorderprint(root);
		cout << endl << "preorder" << endl;
		preorderprint(root);

	}
	bool search(TNode<T>* r, T d)
	{
		bool flag = 0;
		while ((r != nullptr) && (flag == 0))
		{
			int rd = root->data;
			if (d < r->data)
				r = r->left;
			else if (d > r->data)
				r = r->right;
			else
			{
				flag = 1;
				break;
			}
			flag = search(r, d);
		}
		return flag;
	}
	bool wrappersearch(T d)
	{
		bool a = search(root, d);
		return a;
	}

	bool isaval(TNode<T>* r)
	{
		if (r == nullptr)
			return 1;
		else if (geth(r->left) - geth(r->right) >= 2 && geth(r->left) - geth(r->right) <= -2)
			return 0;
		return ((isaval(r->right)) && (isaval(r->left)));

	}
	void wrapperisaval()
	{
		if (isaval(root))
		{
			cout << "Is AVL";
		}
		else
			cout << "Not AVL";

	}


};



int main()
{
	BTree<int> t1;
	t1.wrapperInsert(8);
	t1.wrapperInsert(7);
	t1.wrapperInsert(6);
	t1.wrapperInsert(5);
	t1.wrapperInsert(4);
	t1.wrapperInsert(3);
	t1.wrapperprint();
	cout << endl << "searching 7" << endl;
	int a = t1.wrappersearch(7);
	if(a==1)
	cout << "found" << endl;
	cout << "minimum is" << endl;
		t1.wrapperfindmin();
		cout<< endl<<"second minimum is"<< t1.wrappersecondfindmin()<<endl;
		t1.wrapperisaval();





	system("pause");
	return 0;
}