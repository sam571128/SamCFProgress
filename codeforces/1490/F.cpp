#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int mx = 0;
	map<int,int> cnt;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
		mx = max(cnt[tmp],mx);
	}
	if(n==1){
		cout << 0 << "\n";
		return;
	}

	map<int,int> m;
	map<int,int,greater<int>> m2;
	for(auto [a,b] : cnt){
		m[b]++;
		m2[b]++;
	}
	map<int,int> smallsum;
	int now = 0;
	for(auto [a,b] : m){
		smallsum[a] = now;
		now += a*b;
	}
	int ans = 1e18;
	int num = 0, sum = 0;
	for(auto [a,b] : m2){
		ans = min(sum-num*a+smallsum[a],ans);
		num += b;
		sum += a*b;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}