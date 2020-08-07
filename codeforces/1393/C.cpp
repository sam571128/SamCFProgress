//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	unordered_map<int,int> m;
	while(n--){
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	int mx = 0;
	int cnt = 0;
	for(auto [a,b] : m){
		mx = max(mx,b);
	}
	for(auto [a,b] : m){
		cnt += min(mx-1,b);
	}
	cnt-=mx-1;
	cout << cnt/(mx-1) << "\n";

}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}