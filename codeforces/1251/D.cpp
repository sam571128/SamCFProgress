#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,s;
	cin >> n >> s;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int l,r;
		cin >> l >> r;
		v.push_back({l,r});
	}
	
	auto bs = [&](int mid, int tmp){
		int cnt = 0;
		sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
			return ((a.second>=mid)==(b.second>=mid)) ? a.first > b.first : a.second >= mid;
		});
		for(auto [l,r] : v){
			cnt++;
			if(cnt <= n/2+1){
				if(r < mid) return false;
				tmp -= max(l,mid);
			}else{
				tmp -= l;
			}
		}
		if(tmp < 0) return false;
		return true;
	};
	int l = 1, r = 1e9+7;
	while(l < r-1){
		int mid = l+r>>1;
		if(bs(mid,s)) l = mid;
		else r = mid-1;
	}
	if(bs(r,s)) cout << r << "\n";
	else cout << l << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}