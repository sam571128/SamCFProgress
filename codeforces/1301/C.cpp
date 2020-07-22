#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cin>>n>>m;
		ll ans1=(n+1ll)*n/2ll;
		ll cnt1=(n-m)/(m+1ll);
		ll cnt2=(n-m)%(m+1ll);
		cout<<ans1-(cnt1*(cnt1+1ll)/2ll)*(m+1ll)-(cnt1+1ll)*cnt2<<endl;
	}
	return 0;
}