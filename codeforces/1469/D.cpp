#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	int now = n;
	for(int i = n-1;i >= 2;i--){
		while(i*i <= now||(i==2&&now!=2)) v.push_back({n,i}), now = (now+i-1)/i;
		v.push_back({i,n});
	}
	cout << v.size() << "\n";
	for(auto x : v) cout << x.first << " " << x.second << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}