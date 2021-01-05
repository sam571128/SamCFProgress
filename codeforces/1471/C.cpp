#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int k[n], c[m];
	queue<int> q;
	for(auto &x : k) cin >> x;
	for(int i = 0;i < m;i++){
		int tmp;
		cin >> tmp;
		c[i] = tmp;
		q.push(tmp);
	}
	sort(k,k+n,greater<int>());
	int ans = 0;
	for(int i = 0;i < n;i++){
		k[i]--;
		if(!q.empty()&&q.front() < c[k[i]]){
			ans += q.front(), q.pop();
		}else{
			ans += c[k[i]];
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}