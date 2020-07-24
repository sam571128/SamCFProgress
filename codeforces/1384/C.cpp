#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int n;
	string a,b;
	cin >> n >> a >> b;
	for(int i = 0;i < n;i++){
		if(a[i]<b[i]) pq.push(make_pair((int)a[i],(int)b[i]));
		else if(a[i] > b[i]){
			cout << -1 << "\n";
			return;
		}
	}
	unordered_map<int,int> m;
	for(int i = 0;i < 26;i++) m['a'+i] = 'a'+i;
	int ans = 0;
	while(!pq.empty()){
		auto tmp = pq.top(); pq.pop();
		if(tmp.first==tmp.second) continue;
		if(m[tmp.first]!=tmp.first){
			tmp.first = m[tmp.first], pq.push(tmp);
			continue;
		}
		ans++;
		m[tmp.first] = tmp.second;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}