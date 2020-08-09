#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	deque<int> q;
	for(int i = 1;i <= n;i++){
		q.push_back(i);
	}
	vector<int> ans;
	for(int i = 1;i <= n;i++){
		if(i&1) ans.push_back(q[0]), q.pop_front();
		else ans.push_back(q.back()), q.pop_back();
	}
	for(auto x : ans) cout << x <<  " ";
	cout << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}