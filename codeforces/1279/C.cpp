//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long 
#define eb emplace_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	deque<int> a;
	set<int> s;
	for(int i = 0,tt;i < n;i++){
		cin >> tt;
		a.eb(tt);
	}
	int ans = 0;
	while(m--){
		int tt;
		cin >> tt;
		if(s.find(tt)==s.end()){
			while(a.front()!=tt){
				s.insert(a.front());
				a.pop_front();
			}
			a.pop_front();
			ans+=2*s.size()+1;
		}else{
			ans++;
			s.erase(tt);
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}