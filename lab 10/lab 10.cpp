#include<iostream>
#include<string>
using namespace std;

template<class T>
class Atree {
	class Anode {
	public:
		T data;
		Anode* left;
		Anode* right;
		int height;
		Anode(T d, Anode* l, Anode* r, int h) {
			data = d;
			left = nullptr;
			right = nullptr;
			height = h;
		}
	};
	Anode* root;
public:
	Atree() {
		root = nullptr;
	}
	int geth(Anode* r) {
		if (r == nullptr)
			return -1;
		else
			return r->height;
	}
	int max(int h1, int h2) {

		if (h1 > h2) {
			return h1;
		}
		else if (h1 <= h2) {
			return h2;
		}
	}

	void rotateleft(Anode*& X) {
		Anode* Y = X->right;
		X->right = Y->left;
		Y->left = X;
		X->height = 1 + max(geth(X->left), geth(X->right));
		Y->height = 1 + max(X->height, geth(Y->right));
		X = Y;
	}

	void rotateright(Anode*& X) {
		Anode* Y = X->left;
		X->left = Y->right;
		Y->right = X;
		X->height = 1 + max(geth(X->right), geth(X->left));
		Y->height = 1 + max(X->height, geth(Y->left));
		X = Y;
	}

	void doublerotateleft(Anode*& X) {
		rotateright(X->right);
		rotateleft(X);
	}
	void doublerotateright(Anode*& X) {
		rotateleft(X->left);
		rotateright(X);
	}


	void insert(Anode*& r, T d) {
		if (r == nullptr) {
			r = new Anode(d, nullptr, nullptr, 0);
		}
		else {
			if (d < r->data) {
				insert(r->left, d);
				if (geth(r->left) - geth(r->right) == 2) {
					if (d < r->left->data) {
						rotateright(r);
					}
					else
						doublerotateright(r);
				}
			}

			else if (d > r->data) {
				insert(r->right, d);
				if (geth(r->left) - geth(r->right) == -2) {
					if (d > r->right->data) {
						rotateleft(r);
					}
					else {
						doublerotateleft(r);
					}
				}
			}
		}
		r->height = 1 + max(geth(r->left), geth(r->right));

	}
	void insert(T d) {
		insert(root, d);
	}


	int balancefactor(Anode* r) {
		int lh, rh;
		//if (r == nullptr) {
		//	return -1;
		//}
		//return (geth(r->left) - geth(r->right));
		if (r == NULL)
			return(0);
		if (r->left == NULL)
			lh = 0;
		else
			lh = 1 + r->left->height;
		if (r->right == NULL)
			rh = 0;
		else
			rh = 1 + r->right->height;
		return(lh - rh);

	}

	void wrappermin() {
		cout << endl;
		cout << "The minimum is " << findmin(root);
		cout << endl;
		cout << "The second minimum is " << find2min(root);
		cout << endl;
	}

	T findmin(Anode* r) {
		if (r == nullptr)
			return 0;
		else if (r != nullptr && r->left == nullptr && r->right == nullptr) {
			return r->data;
		}
		else if (r->left != nullptr) {
			return findmin(r->left);
		}

	}

	T find2min(Anode* r) {
		if (r == nullptr)
			return 0;
		else if (r != nullptr && r->left->left == nullptr && r->right != nullptr) {
			return r->data;
		}
		if (r->left != nullptr) {
			return find2min(r->left);
		}

	}

	void wrapperprintinorder() {
		cout << endl << "inorder" << endl;
		printinorder(root);

	}
	void wrapperprintpost() {
		cout << endl << "postorder" << endl;
		printpostorder(root);

	}
	void wrapperprintpre() {
		cout << endl << "preorder" << endl;
		printpreorder(root);

	}



	void printinorder(Anode* r) {
		if (r != nullptr) {

			printinorder(r->left);
			cout << r->data << endl;
			printinorder(r->right);
		}
	}
	void printpostorder(Anode* r) {
		if (r != nullptr) {
			
			printinorder(r->left);
			
			printinorder(r->right);
			
			cout << r->data << endl;
		}
	}
	void printpreorder(Anode* r) {
		if (r != nullptr) {
			
			cout << r->data << endl;
			
			printinorder(r->left);
		
			printinorder(r->right);
		}
	}

	bool wrappersearch(T d)

	{
		return search(root, d);

	}

	bool search(Anode* r, T d)

	{

		bool found = false;

		while ((r != nullptr) && !found)

		{

			int root_data = r->data;

			if (d < r->data)

				r = r->left;

			else if (d > r->data)

				r = r->right;

			else {

				found = true;
				break;
			}

			found = search(r, d);

		}

		return found;

	}


	void wrapperisAVL(Atree<int>a1) {
		if (isAVL(root)) {
			cout << "Tree is AVL" << endl;
		}
		else {
			cout << "Tree is not AVL" << endl;
		}
	}

	bool isAVL(Anode* r) {
		if (r == nullptr)
			return 1;
		if ((geth(r->left) - geth(r->right)) <= 1 && isAVL(r->left) && isAVL(r->right)) {
			return 1;
		}
		return 0;
	}

	void wrapperremove(T d) {
		remove(d, root);
	}


	void wrapperprint2D(int space) {
		print2D(root, space);
	}
	void print2D(Anode* r, int space) {
		int SPACE = 4;
		if (r == NULL) // Base case  1
			return;
		space += SPACE; // Increase distance between levels   2
		print2D(r->right, space); // Process right child first 3 
		cout << endl;
		for (int i = SPACE; i < space; i++) // 5 
			cout << " "; // 5.1  
		cout << r->data << "\n"; // 6
		print2D(r->left, space); // Process left child  7
	}

	void remove(const int& x, Anode*& t) {
		if (t == nullptr)
			return; // Item not found; do nothing
		if (x < t->data)
			remove(x, t->left);
		else if (t->data < x)
			remove(x, t->right);
		else if (t->left != nullptr && t->right != nullptr) {//Two children
			t->data = findmin(t->right);
			remove(t->data, t->right);
		}
		else {
			Anode* oldNode = t;
			if (t->left != nullptr) {
				t = t->left;
			}

			else {
				t = t->right;
			}

			delete oldNode;
		}
		balance(t);
	}
	void balance(Anode*& x) {
		if (x == nullptr) return;
		if (geth(x->right) - geth(x->left) > -1)
			if (geth(x->left->left) >= geth(x->left->right))
				rotateright(x);
			else
				doublerotateright(x);

		else if (geth(x->right) - geth(x->left) > 1)
			if (geth(x->right->right) >= geth(x->right->left))
				rotateleft(x);
			else
				doublerotateleft(x);
		x->height = max(geth(x->left), geth(x->right)) + 1;
	}



};




int main() {



	string arr[12] = { "Jan", "Feb","Mar","April","May","June","July","Aug","Sept","Oct","Nov","Dec" };

	//string arr[3];
	//arr[0] = 'Jan';
	//arr[1] = 'Feb';
	//arr[2] = 'Mar';


	Atree<string>t1;

	t1.insert("Jan");
	t1.insert("Feb");
	t1.insert("Mar");
	t1.insert("April");
	t1.insert("May");
	t1.insert("June");
	t1.insert("July");
	t1.insert("Aug");
	t1.insert("Sept");
	t1.insert("Oct");
	t1.insert("Nov");
	t1.insert("Dec");
	t1.wrapperprintinorder();
	t1.wrappermin();






	system("pause");
	return 0;
}