#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,w;
	cin >> n >> w;
	int arr[n];
	for(auto &x : arr) cin >> x;
	vector<pair<int,int>> v;
	for(int i = 0, tmp;i < n;i++){
		tmp = arr[i];
		if(tmp > w) continue;
		if(tmp >= w/2 + w%2&&tmp <= w){
			cout << 1 << "\n";
			cout << i+1 << "\n";
			return;
		}
		v.push_back({tmp,i});
	}
	sort(v.begin(),v.end());
	int cnt = 0;
	vector<int> ans;
	for(auto x : v){
		cnt += x.first; ans.push_back(x.second+1);
		if(cnt >= w/2 + w%2&&cnt <= w){
			cout << ans.size() << "\n";
			for(auto y : ans) cout << y << " ";
			cout << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}	
/*
1
10
239
630 847 687 270 118 906 818 512 848 685 
*/