#include<iostream>
using namespace std;
typedef long long ll;
typedef struct AVL_node node;


struct AVL_node{
	ll val;
	ll height;
	ll bal_fact;
	struct AVL_node* left = NULL;
	struct AVL_node* right = NULL;
}

node* newAVLnode(ll data)
{
	node* cnode = new struct AVL_node;
	cnode->val = data;
	cnode->height = 1;
	cnode->bal_fact = 0;
	return cnode;
}

void _insert_AVL(node *rnode, node *nnode)
{
	ll x = nnode->val;
	ll bfact;
	if(rnode == NULL)
	{
		rnode = nnode;
		return;
	}
	node *tptr = rnode, *cptr;
	do{
		if(tptr->val < x)
		{
			cnode = tptr->right;
			tptr->bal_fact -= 1;
		}
		else if(tptr->val > x)
		{
			cnode = tptr->left;
			tptr->bal_fact += 1;
		}
		else
		{
			if(bfact <= 0)
			{
				cnode = tptr->left;
				tptr->bal_fact += 1;
			}
			else
			{
				cnode = tptr->right;
				tptr->bal_fact -= 1;
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
	
}