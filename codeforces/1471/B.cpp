#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool ok;
int get(int n, int x){
	if(n%x||!ok){
		return n;
	}
	return n+x*get(n/x,x);
}

void solve(){
	int n,x;
	cin >> n >> x;
	int ans = 0;
	ok = true;
	queue<pair<int,int>> q;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		q.push({tmp,1});
	}
	while(!q.empty()){
		auto [tmp,num] = q.front(); q.pop();
		ans += tmp*num;
		if(tmp%x) break;
		q.push({tmp/x,x*num});
	}
	while(!q.empty()) ans += q.front().first*q.front().second, q.pop();
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}