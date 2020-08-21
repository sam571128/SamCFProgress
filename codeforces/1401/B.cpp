#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x,y,z; // 0, 1 , 2
	int a,b,c; // 0 , 1 , 2
	cin >> x >> y >> z >> a >> b >> c;
	c -= min(x,c);
	int tmp = min(z,c);
	z -= tmp, c -= tmp;
	cout << min(c,y)*(-2)+min(b,z)*2 << "\n";

}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}