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
};

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

void _inorder(node *root)
{
	if(root == NULL)
	{
		//cout<<"empty\n";
		return;
	}
	_inorder(root->left);
	cout<<root->val<<' ';
	_inorder(root->right);
}

void _fill_height_bf(node *ptr)
{
	if(ptr->left == NULL && ptr->right == NULL)
	{
		ptr->height = 1;
		return;
	}
	else if(ptr->left && ptr->right)
	{
		_fill_height_bf(ptr->left);
		_fill_height_bf(ptr->right);
		ptr->height = 1+max(ptr->left->height)
	}
}

node *_find_parent(node *ptr, node *root)
{
	ll value = ptr->val;
	node *seeker, *ptr1, *ptr2;
	seeker = root;
	while(1)
	{
		if(seeker->val < value)
		{
			if(seeker->right == ptr)
				return seeker;
			seeker = seeker->right;
		}
		else if(seeker->val > value)
		{
			if(seeker->left == ptr)
				return seeker;
			seeker = seeker->left;
		}
		else
		{
			if(seeker->left && seeker->right)
			{
				ptr1 = _find_parent(ptr, seeker->left);
				ptr2 = _find_parent(ptr, seeker->right);
				return (ptr1 == NULL)?ptr2:ptr1;
			}
			else if(seeker->left)
			{
				if(seeker->left == ptr)
					return seeker;
				seeker = seeker->left;
			}
			else if(seeker->right)
			{
				if(seeker->right == ptr)
					return seeker;
				seeker = seeker->right;
			}
		}
		if(seeker == NULL)
			return NULL;
	}
}

void _insert_AVL(node*& rnode, node *nnode)
{
	//cout<<"got "<<rnode<<endl;
	ll x = nnode->val;
	ll bfact;
	node *unbalanced = NULL;
	string temp;
	char ch;
	cout<<"inserting node "<<nnode->val<<endl;
	if(rnode == NULL)
	{
		//cout<<"initally empty\n";
		rnode = nnode;
		return;
	}
	node *tptr = rnode;
	do{
		//cnode = tptr;
		//unbalanced_par = cnode;
		//cout<<"unbalanced's parent "<<unbalanced_par->val<<endl;
		if(tptr->val < x)
		{
			cout<<"moving right\n";
			tptr->bal_fact -= 1;
			tptr->right_c += 1;
			if(tptr->right == NULL)
			{
				ch = 'r';
				break;
			}
			if(abs(tptr->bal_fact) > 1 )
			{
				unbalanced = tptr;
				cout<<"unbalanced node "<<unbalanced->val<<endl;
			}
			tptr = tptr->right;
		}
		else if(tptr->val > x)
		{
			cout<<"moving left\n";
			tptr->bal_fact += 1;
			tptr->left_c += 1;
			if(tptr->left == NULL)
			{
				ch = 'l';
				break;
			}
			if(abs(tptr->bal_fact) > 1 )
			{
				unbalanced = tptr;
				cout<<"unbalanced node "<<unbalanced->val<<endl;
			}
			tptr = tptr->left;
		}
		else
		{
			if(bfact <= 0)
			{
				tptr->bal_fact += 1;
				if(tptr->left == NULL)
				{
					ch = 'l';
					break;
				}
				if(abs(tptr->bal_fact) > 1 )
				{
					unbalanced = tptr;
					cout<<"unbalanced node "<<unbalanced->val<<endl;
				}
				tptr = tptr->left;
			}
			else
			{
				tptr->bal_fact -= 1;
				if(tptr->right == NULL)
				{
					ch = 'r';
					break;
				}
				if(abs(tptr->bal_fact) > 1 )
				{
					unbalanced = tptr;
					cout<<"unbalanced node "<<unbalanced->val<<endl;
				}
				tptr = tptr->right;
			}
		}
		_fill_height_bf(rnode);
		//cout<<"parent->child "<<cnode->val<<' '<<tptr->val<<endl;
	}while(1);

	if(ch == 'r')
		tptr->right = nnode;
	else if(ch == 'l')
		tptr->left = nnode;
	if(unbalanced != NULL)
	{
		node *unbalanced_par = _find_parent(unbalanced, rnode);
		cout<<"rotn reqd at "<<unbalanced->val<<"'s subtree with "<<unbalanced_par->val<<" parent\n";
	}
	cout<<"inserted "<<nnode->val<<endl<<endl;
}

/*ll _median(ll* ptr, ll size)
{

}*/

int main()
{
	cout<<"main func\n";
	ll n, lv;
	cin>>n;
	node *root = NULL, *ptr;
	ll arr[n];
	for(lv=0;lv<n;lv++)
	{
		cin>>arr[lv];
		ptr = newAVLnode(arr[lv]);
		/*if(ptr == NULL)
			cout<<"node not created\n";
		cout<<"sending "<<root<<endl;*/
		_insert_AVL(root, ptr);
		//cout<<_median(arr, lv+1)<<endl;
	}
	cout<<endl;
	_inorder(root);
}
