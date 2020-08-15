#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int x,k,d;
	cin >> x >> k >> d;
	x = abs(x);
	if(k<=x/d){
		cout << -k*d+x << "\n";
		return 0;
	}
	int val1 = x-(x/d)*d, val2 = abs(val1-d);
	//cout << val1 << " " << val2 << "\n";
	k-=x/d;
	if(k&1) cout << val2 << "\n";
	else cout << val1 << '\n';
}