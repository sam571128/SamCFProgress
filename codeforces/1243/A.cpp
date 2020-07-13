# include <bits/stdc++.h>
using namespace std;
int a[1005];
int n;
bool check(int x) {
	int cnt=0;
	for (int i=1;i<=n;i++) if (a[i]>=x) cnt++;
	if (cnt>=x) return 1;
	else return 0;
}
int main()
{
	int t;cin>>t;
	while (t--) {
		cin>>n;
	for (int i =1;i<=n;i++) cin>>a[i];
	int l=1,r=n,ans;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	}
 
	return 0;
}