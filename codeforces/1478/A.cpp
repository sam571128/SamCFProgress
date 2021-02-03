#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int cnt[n+1] = {};
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		cnt[tmp]++;
	} 
	cout << *max_element(cnt,cnt+n+1) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}