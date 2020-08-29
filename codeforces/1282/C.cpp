#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,T,a,b;
	cin >> n >> T >> a >> b;
	vector<pair<int,int>> v(n);
	int totalA = 0, totalB = 0;
	for(int i = 0;i < n;i++){
		cin >> v[i].second;
		if(v[i].second) totalB++;
		else totalA++;
	}
	for(int i = 0;i < n;i++) cin >> v[i].first;
	sort(v.begin(), v.end());
	int cntA = 0, cntB = 0, ans = 0;
	for(int i = 0;i < n;i++){
		int tt = v[i].first-1;
		int tmp = 0;
		if(tt >= 0 && tt >= cntA*a + cntB*b){
			tmp = cntA+cntB;
			//cout << a+b << "\n";
			tt-=cntA*a+cntB*b;
			tmp += min(tt/a,totalA-cntA);
			tt -= min(tt/a,totalA-cntA)*a;
			tmp += min(tt/b,totalB - cntB);
			ans = max(ans,tmp);
		}
		if(v[i].second) cntB++;
		else cntA++;
	}
	int tt = T;
	if(tt >= 0 && tt >= cntA*a + cntB*b){
			int tmp = cntA+cntB;
			//cout << a+b << "\n";
			tt-=cntA*a+cntB*b;
			tmp += min(tt/a,totalA-cntA);
			tt -= min(tt/a,totalA-cntA)*a;
			tmp += min(tt/b,totalB - cntB);
			ans = max(ans,tmp);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}