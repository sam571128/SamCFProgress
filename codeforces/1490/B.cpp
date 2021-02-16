#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int cnt[3] = {};
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		cnt[tmp%3]++;
	}
	int ans = 0;
	while(true){
		for(int i = 0;i < 3;i++){
			if(cnt[i] > cnt[(i+1)%3]){
				ans++, cnt[i]--, cnt[(i+1)%3]++;
			}
		}
		bool ok = true;
		for(int i = 0;i < 2;i++){
			if(cnt[i]!=cnt[i+1]) ok = false;
		}
		if(ok) break;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}