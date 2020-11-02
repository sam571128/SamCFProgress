#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0;i < n;i++) cin >> v[i].first;
	for(int i = 0;i < n;i++) cin >> v[i].second;
	sort(v.begin(),v.end());
	int ans = INT_MAX, sum = 0;
	v.push_back({0,0});
	while(!v.empty()){
		sum += v.back().second; v.pop_back();
		ans = min(ans,max(sum,(!v.empty() ? v.back().first : 0)));
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}