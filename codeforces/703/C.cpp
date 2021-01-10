#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	double n,w,v,u;
	cin >> n >> w >> v >> u;
	bool ok1 = true, ok2 = true;
	double ans = 0;
	for(int i = 0;i < n;i++){
		double x, y;
		cin >> x >> y;
		if(x/v < y/u){
			ok1 = false;
		}
		if(x/v > y/u){
			ok2 = false;
		}
		ans = max(ans,x/v+(w-y)/u);
	}
	cout << setprecision(10) << fixed;
	if(ok1||ok2) cout << w/u << "\n";
	else cout << ans << "\n";
}