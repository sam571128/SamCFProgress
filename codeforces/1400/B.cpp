#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int p,f,cnts,cntw,s,w;
	cin >> p >> f >> cnts >> cntw >> s >> w;
	if(s > w){
		swap(cnts,cntw);
		swap(s,w);
	}
	int ans = 0;
	for(int i = 0;i <= cnts;i++){
		if(i*s>p) break;
		//cout << i << " " << min(cntw,(p-i*s)/w) << " " << min(f/s,cnts-i) << " " << min(cntw-min(cntw,(p-i*s)/w),(f-min(f/s,cnts-i)*s)/w) << "\n";
		ans = max(ans,i+min(cntw,(p-i*s)/w)+min(f/s,cnts-i)+min(cntw-min(cntw,(p-i*s)/w),(f-min(f/s,cnts-i)*s)/w));
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}