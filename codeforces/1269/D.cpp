#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int cnt[2];
void solve(){
	int n;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(i&1^1){
			cnt[0] += tmp/2+tmp%2;
			cnt[1] += tmp/2;
		}else{
			cnt[0] += tmp/2;
			cnt[1] += tmp/2+tmp%2;
		}
	}
	cout << min(cnt[0],cnt[1]) << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}