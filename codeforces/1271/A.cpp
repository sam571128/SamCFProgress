//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	for(int i = 0;i <= min(a,d);i++){
		int tmp = i*e+min({(d-i),b,c})*f;
		ans = max(ans, tmp);
	}
	cout << ans << "\n";
}