#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


signed main(){
	fastio
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			if(abs(v[i].first-v[j].first) >= abs(v[i].second-v[j].second)) ans++;
		}
	}
	cout << ans << "\n";
}


