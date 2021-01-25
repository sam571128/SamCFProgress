#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	int ans = 0;
	pair<int,int> a[k];
	for(auto &x : a) cin >> x.first;
	for(auto &x : a) cin >> x.second;
	map<int,int> cnt;
	sort(a,a+k);
	int now = 0, all = 0;
	for(auto &x : a){
		if(cnt[x.first]==0) now = all;
		ans += now;
		cnt[x.first]++;
		all++;
		swap(x.first,x.second);
	}
	sort(a,a+k);
	map<int,int> cnt2;
	cnt.clear();
	now = 0;
	for(auto &x : a){
		swap(x.first,x.second);
		if(cnt2[x.second]==0) now = 0, cnt.clear();
		ans -= now-cnt[x.first];
		//cout << x.first << " " << x.second << " " << now << " " << cnt[x.first] << "\n";
		cnt[x.first]++;
		cnt2[x.second]++;
		now++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}