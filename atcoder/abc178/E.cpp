#include <bits/stdc++.h>

#define int long long
#define x first
#define y second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
		return (a.x-a.y) < (b.x-b.y);
	});
	int ans = abs(v[0].x-v.back().x)+abs(v[0].y-v.back().y);
	sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
		return (a.x+a.y) < (b.x+b.y);
	});
	ans = max(ans,abs(v[0].x-v.back().x)+abs(v[0].y-v.back().y));
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}