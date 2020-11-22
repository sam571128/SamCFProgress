#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> v;
int n, t;
int arr[40];
int ans = 0;

void recur1(int i = 0, int sum = 0){
	if(sum > t) return;
	v.push_back(sum);
	if(i == n/2) return;
	recur1(i+1,sum);
	recur1(i+1,sum+arr[i]);
}

void recur2(int i = n/2, int sum = 0){
	if(sum > t) return;
	ans = max(sum,ans);
	auto x = upper_bound(v.begin(),v.end(),t-sum);
	if(x!=v.begin()){
		if(sum+*(x-1) <= t) 
			ans = max(sum+*(x-1),ans);
	}
	if(i==n) return;
	recur2(i+1,sum);
	recur2(i+1,sum+arr[i]);
}

void solve(){
	cin >> n >> t;
	for(int i = 0;i < n;i++) cin >> arr[i];
	recur1();
	sort(v.begin(),v.end());
	recur2();
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}