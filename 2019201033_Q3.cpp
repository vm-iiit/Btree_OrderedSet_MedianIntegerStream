#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll n, lv;
	cin>>n;
	ll arr[n];
	for(lv=0;lv<n;lv++)
	{
		cin>>arr[lv];
		cout<<_median(arr, lv+1)<<endl;
	}
	
}