#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	map<pair<int,int>,int> mp;
	map<int,int> ma, mb;
	int h,w,m;
	cin >> h >> w >> m;
	
	while(m--){
		int x,y;
		cin >> x >> y;
		ma[x]++;
		mb[y]++;
		mp[{x,y}]++;
	}

	int mr = 0, mc = 0;
	for(auto [a,b] : ma) mr = max(mr,b);
	for(auto [a,b] : mb) mc = max(mc,b);

	vector<int> v1, v2;
	for(auto [a,b] : ma) if(b==mr) v1.push_back(a);
	for(auto [a,b] : mb) if(b==mc) v2.push_back(a);
	int ans = mr + mc -1;
	for(auto a : v1){
		for(auto b : v2){
			if(mp[{a,b}]) continue;
			ans = mr + mc;
			goto stop; 
		}
	}	
	stop:;
	cout << ans << "\n";
}