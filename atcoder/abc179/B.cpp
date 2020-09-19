#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	deque<pair<int,int>> v;
	int n, cnt = 0;
	cin >> n;
	bool ok = false;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.emplace_back(x,y);
		if(x==y) cnt++;
		if(i>=3){
			if(v[0].first==v[0].second) cnt--;
			v.pop_front();
		}
		if(cnt==3){
			ok = true;
		}
	}
	cout << (ok ? "Yes\n" : "No\n");
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}