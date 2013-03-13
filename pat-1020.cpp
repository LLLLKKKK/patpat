#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _a *PNode;
typedef struct _a Node;
typedef struct _a 
{
	PNode left;
	PNode right;
	int me;
};

int postorder[30] = {0};
int inorder[30] = {0};
int n;
PNode root = new Node();

int search(int pleft, int pright, int ileft, int iright, PNode root)
{
	root->me = postorder[pright];
	if (pleft <= pright)
	{
		int i;
		for (i = ileft;i <= iright ;i++ )
			if (inorder[i] == postorder[pright])
			break;

		if (pleft <= i-ileft+pleft-1){
			root->left = new Node();
			search(pleft, i-ileft+pleft-1, ileft, i-1, root->left);
		}else
			root->left = NULL;

		if (i-ileft+pleft <= pright-1)
		{
			root->right = new Node();
			search(i-ileft+pleft, pright-1, i+1, iright, root->right);
		}
		else
			root->right = NULL;
	}
}

int main()
{
	cin >> n;
	for (int i = 0;i < n ;i++ )
		cin >> postorder[i];
	for (int i = 0;i < n ;i++ )
		cin >> inorder[i];

	search(0, n - 1, 0, n - 1, root);

	queue<PNode> lel;
	vector<int> ls;

	lel.push(root);
	while (!lel.empty())
	{
		root =lel.front();
		lel.pop();
		
		if (root->left != NULL)
			lel.push(root->left);
		if (root->right != NULL)
			lel.push(root->right);


		ls.push_back(root->me);
	}

	for (int i = 0;i < ls.size() - 1 ;i++ )
		cout << ls[i] << ' ';
	cout << ls[ls.size() - 1] << endl;

	return 0;
}

