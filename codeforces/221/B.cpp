#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool f[10];
bool chk(int d)
{
	while(d)
	{
		if (f[d%10]) return true;
		d/=10;
	}
	return false;
}
 
int main()
{
	int x;
	cin>>x;
	int d=x;
	while(d)
	{
		f[d%10]=true;
		d/=10;
	}
	int ans=0,i;
	for (i=1;i*i<x;i++)
		if (x%i==0)
		{
			if (chk(i)) ans++;
			if (chk(x/i)) ans++;
		}
	if (i*i==x&&chk(i)) ans++;
	cout<<ans<<endl;
}