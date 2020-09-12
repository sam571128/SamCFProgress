#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,int> m;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		m[tmp]++;
	}
	int ans = 0, cnt = 0;
	for(int i = 0;i <= 100;i++){
		if(m[i]>=2) continue;
		if(cnt==0&&m[i]==1) ans += i, cnt++;
		if(m[i]==0){
			if(cnt) ans+=i;
			else ans+=2*i;
			break;
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