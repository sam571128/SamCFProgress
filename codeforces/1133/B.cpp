#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	map<int,int> m;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		m[tmp%k]++;
	}
	int ans = m[0]/2;
	if(k%2==0) ans += m[k/2]/2;
	for(int i = 1;i < (k+1)/2;i++){
		ans += min(m[i],m[k-i]);
	}
	cout << ans*2 << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}