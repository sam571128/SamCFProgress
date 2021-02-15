#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> v;
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0;i < n;i++){
		string tmp;
		cin >> tmp;
		v.push_back(tmp.size()/2);
		for(auto c : tmp){
			if(c=='0') cnt0++;
			else cnt1++;
		}
	}
	int has = cnt0/2 + cnt1/2;
	int ans = 0;
	sort(v.begin(), v.end());
	for(auto x : v){
		if(has-x>=0) ans++, has-=x;
		else break;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}