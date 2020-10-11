#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	deque<int> v;
	s = '#' + s + '#';
	for(int i = 1;i <= n;i++){
		if(s[i]!=s[i-1]) v.push_back(1);
		else v.back()++;
	}
	int ans = 0, idx = 0;
	while(!v.empty()&&idx<(int)v.size()){
		idx = max(0,idx);
		if(v[idx]==1) idx++;
		else if(v[idx]>=1){
			v[idx--]--;
			ans++;
			v.pop_front();
		}
	}
	cout << ans + (v.size()+1)/2 << "\n";
}
/*
1
10
0110001010
*/

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}