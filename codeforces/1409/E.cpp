#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> x(n), y(n);
	set<pair<int,int>> s, s2;
	for(auto &t : x) cin >> t;
	for(auto &t : y) cin >> t;
	sort(x.begin(),x.end());
	int ma = 0;
	for(int i = n-1;~i;i--){
		s.insert({x[i],upper_bound(x.begin()+i,x.end(),x[i]+k)-x.begin()-i});
		ma = max(ma,upper_bound(x.begin()+i,x.end(),x[i]+k)-x.begin()-i);
		if(i>0&&x[i-1]!=x[i])s2.insert({x[i],ma});
		else if(i==0) s2.insert({x[i],ma});
		//cout << i << " " << ma << "\n";
	}
	int ans = 0;
	for(auto p : s){
		int cnt = 0;
		auto itr = s2.lower_bound({p.first+k+1,0});
		if(itr!=s2.end()) cnt = (*itr).second;	
		ans = max(ans,cnt+p.second); 
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}