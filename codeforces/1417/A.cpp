#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int cnt = 0;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		pq.push(tmp);
	}
	while(pq.top()<=k){
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		if(a+b <= k){
			cnt++;
		}else{
			break;
		}
		pq.push(a+b);
		pq.push(a);
	}
	cout << cnt << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}