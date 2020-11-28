#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,p;
	cin >> n >> p;
	int pref[n+1] = {};
	for(int i = 1;i <= n;i++){
		int tmp;
		cin >> tmp;
		pref[i] = pref[i-1]+tmp;
	}
	int ans = 0;
	for(int i = 1;i < n;i++){
		ans = max((pref[i]-pref[0])%p+(pref[n]-pref[i])%p,ans);
	}
	cout << ans << "\n";
}