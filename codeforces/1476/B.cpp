#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int sum;
	cin >> sum;
	int ans = 0;
	for(int i = 1;i < n;i++){
		int num;
		cin >> num;
		int tmp = 0;
		if(100*num > k * sum){
			tmp = max((int)0,(100*num-sum*k)/k + ((100*num-sum*k)%k ? 1 : 0));
		}
		ans += tmp;
		sum += num + tmp;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}