#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct comp{
	bool operator()(pair<int,int> a, pair<int,int> b){
		return abs(a.first) > abs(b.first);
	}
};
void solve(){
	int n,k,x;
	cin >> n >> k >> x;
	priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
	int cnt = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		cnt += (tmp < 0);
		pq.push({tmp,i});
	}
	while(k--){
		auto p = pq.top(); pq.pop();
		int val = p.first, idx = p.second;
		if(val==0){
			if(cnt&1) val+=x;
			else val-=x, cnt++;
			pq.push({val,idx});
		}else if(val < 0){
			if(cnt&1) val -= x;
			else val += x, cnt -= (val >= 0);
			pq.push({val,idx});
		}else{
			if(cnt&1) val += x;
			else val -= x, cnt += (val < 0);
			pq.push({val,idx});
		}
	}
	vector<int> ans(n);
	while(!pq.empty()) ans[pq.top().second] = pq.top().first, pq.pop();
	for(auto x : ans) cout << x << " ";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}