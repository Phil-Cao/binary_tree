#include <iostream>
#include <ctime>
#include "binary_tree.h"
using namespace std;

#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

void display(btree<int> * tree)
{
	cout << "\n== Pro view: ";
	tree->preorder();

	cout << "\n== In view: ";
	tree->inorder();

	cout << "\n== Post view: ";
	tree->postorder();
	cout << endl;

	cout << "== Maximum: " << tree->minimum() << endl;
	cout << "== Minimum: " << tree->maximum() << endl;
	cout << "== Show the tree: " << endl;
	tree->print();

}

int main()
{
	int i, ilen;
	int n, f;
	int * arr;
	srand((unsigned int)time(NULL));
	btree<int>* tree = new btree<int>();

	cout << "How many nodes insert?";
	cin >> n;
	arr = new int [n];
	for (i = 0; i < n; i++)
	{
		cout << "This is " << i + 1 << " numbers" ;
		arr[i]= rand ()/200;
		cout << arr[i] << " " << endl;;
		tree->insert(arr[i]);
	}
		
	display(tree);
	cout << "Are you want to delete(1:yes,0:no)?";
	cin >> f;
	while (f)
	{
    cout << "What are you want to delete?" << endl;
	cin >> n;
	cout << "== Delete node: " << n<<endl;
	tree->remove(n);
	cout << "Are you want to continue(1:yes,0:no)?";
	cin >> f;
	}
	
	display(tree);

	cout << "Are you want to insert(1:yes,0:no)?";
	cin >> f;
	while (f)
	{
		cout << "What are you want to insert?" << endl;
		n= rand()/200;
		cout << "== Insert nodes: " << n<<endl;
		tree->insert(n);
		cout << "Are you want to continue(1:yes,0:no)?";
		cin >> f;
	}
	display(tree);

	// Ïú»Ù¶þ²æÊ÷
	tree->destroy();
	system("pause");
	return 0;
}

