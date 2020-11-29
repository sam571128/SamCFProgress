#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 50;
int n,m;
int arr[N], ans;
vector<int> v;

void dfs1(int idx = 0, int sum = 0){
	v.push_back(sum);
	if(idx!=n/2-1) dfs1(idx+1,sum);
	sum = (sum+arr[idx])%m;
	v.push_back(sum);
	if(idx!=n/2-1) dfs1(idx+1,sum);
}

void dfs2(int idx = n/2, int sum = 0){
	auto itr = upper_bound(v.begin(),v.end(),m-1-sum);
	ans = max(ans,sum+*(itr-1));
	if(idx!=n-1) dfs2(idx+1,sum);
	sum = (sum+arr[idx])%m;
	itr = upper_bound(v.begin(),v.end(),m-1-sum);
	ans = max(ans,sum+*(itr-1));
	if(idx!=n-1) dfs2(idx+1,sum);
}

signed main(){
	fastio
	cin >> n >> m;
	v.push_back(0);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		arr[i]%=m;
	}
	if(n==1){
		cout << arr[0] << "\n";
		return 0;
	}
	dfs1();
	sort(v.begin(),v.end());
	dfs2();
	cout << ans << "\n";
}