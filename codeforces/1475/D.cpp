#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> s;
	int a[n];
	vector<int> v1, v2;
	for(auto &x : a) cin >> x;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		if(tmp==1) v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	sort(v1.begin(),v1.end(),greater<int>());
	sort(v2.begin(),v2.end(),greater<int>());
	int now = 0;
	for(auto x : v1){
		now += x;
		s.push_back(now);
	}
	now = 0;
	int ans = INT_MAX, tmp = lower_bound(s.begin(),s.end(),m)-s.begin();
	if(tmp!=s.size()) ans = (tmp+1);
	for(int i = 0;i < v2.size();i++){
		now += v2[i];
		if(now >= m) ans = min(ans,2*(i+1));
		tmp = lower_bound(s.begin(),s.end(),m-now)-s.begin();
		if(tmp!=s.size()) ans = min(ans,(tmp+1)+2*(i+1));
	}
	cout << (ans==INT_MAX ? -1 : ans) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}