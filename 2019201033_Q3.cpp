#include<iostream>
using namespace std;
typedef long long ll;
typedef struct AVL_node node;


struct AVL_node{
	ll val;
	ll height;
	ll bal_fact;
	ll left_c;
	ll right_c;
	struct AVL_node* left = NULL;
	struct AVL_node* right = NULL;
}

node* newAVLnode(ll data)
{
	node* cnode = new struct AVL_node;
	cnode->val = data;
	cnode->height = 0;
	cnode->bal_fact = 0;
	cnode->left_c = 0;
	cnode->right_c = 0;
	return cnode;
}

void _insert_AVL(node *rnode, node *nnode)
{
	ll x = nnode->val;
	ll bfact;
	node *unbalanced, *unbalanced_par;
	string temp;
	if(rnode == NULL)
	{
		rnode = nnode;
		return;
	}
	node *tptr = rnode, *cnode;
	do{
		cnode = tptr;
		if(tptr->val < x)
		{
			tptr->bal_fact -= 1;
			tptr = tptr->right;
			right_c += 1;
		}
		else if(tptr->val > x)
		{
			tptr->bal_fact += 1;
			tptr = tptr->left;
			left_c += 1;
		}
		else
		{
			if(bfact <= 0)
			{
				tptr->bal_fact += 1;
				tptr = tptr->left;
			}
			else
			{
				tptr->bal_fact -= 1
				tptr = tptr->right;
			}
		}
	}while();
}

ll _median(ll* ptr, ll size)
{

}

int main()
{
	ll n, lv;
	cin>>n;
	node *root = NULL, *ptr;
	ll arr[n];
	for(lv=0;lv<n;lv++)
	{
		cin>>arr[lv];
		ptr = newAVLnode(arr[lv]);
		_insert_AVL(root, ptr);
		cout<<_median(arr, lv+1)<<endl;
	}
