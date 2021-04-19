#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
long long int tree[MAX];

int constSegTree(long long int arr[],int strt, int end, int idx)
{

  if(strt == end)
    return tree[idx] = arr[strt];
  int mid = (strt + end) / 2;
  return tree[idx] = constSegTree(arr,strt, mid, 2*idx+1) |
            constSegTree(arr,mid+1, end, 2*idx+2);
}
void constSegTree(long long int arr[],int n)
{
  constSegTree(arr,0, n-1, 0);
}

int getXor(int strt, int end, int l, int r, int idx)
{
  if(strt <= l && r <= end)
    return tree[idx];
  
  if(end < l || r < strt || l > r)
    return 0;
  
  int mid = (l + r) / 2;
  return getXor(strt, end, l, mid, 2*idx+1) |
      getXor(strt, end, mid+1, r, 2*idx+2);
}
int getXor(int n, int strt, int end)
{
  return getXor(strt, end, 0, n-1, 0);
}

void updtNode(int pos, long long int val, int l, int r, int idx)
{
  if(pos < l || r < pos)
    return;
  if(l == r)
  {
    tree[idx] = val;
    return;
  }
  int mid = (l + r) / 2;
  updtNode(pos, val, l, mid, 2*idx+1);
  updtNode(pos, val, mid+1, r, 2*idx+2);
  tree[idx] = tree[2*idx+1] | tree[2*idx+2];
}
void updtNode(int n, int pos, long long int val)
{
  updtNode(pos, val, 0, n-1, 0);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int n,q;
		cin >> n >> q;
		long long int arr[n];
		
		long long int ans;
		for(int i =0;i<n;i++)
		  {
		  	 cin >> arr[i];
		}
		if(n==1)
		{
			cout << arr[0] << "\n";
			while(q--)
			{
				int x;
				long long int v;
				cin >> x >> v;
				cout << v <<"\n";
			}
		}
		ans = arr[0];
		for(int i =1;i<n;i++)
		  {
		  	 ans = ans | arr[i];
		}
		cout << ans << "\n";
		constSegTree(arr,n);
		while(q--)
		{
			int x;
			long long int v;
			cin >> x >> v;
			updtNode(n, x-1, v);
			cout << getXor(n, 0, n-1) << "\n";
		}
	}
	return 0;
}

