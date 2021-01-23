#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int cnt[n] = {}, cnt2[m] = {};
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			int tmp;
			cin >> tmp;
			if(tmp) cnt[i]++, cnt2[j]++;
		}
	}
	for(int i = 0;i < n;i++){
		ans += (1LL<<cnt[i])-1;
		ans += (1LL<<m-cnt[i])-1;
	}
	for(int i = 0;i < m;i++){
		ans += (1LL<<cnt2[i])-1-cnt2[i];
		ans += (1LL<<n-cnt2[i])-1-(n-cnt2[i]);
	}
	cout << ans << "\n";
}