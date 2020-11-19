#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;
signed main(){
	fastio
	int n;
	cin >> n;
	int a = 1,b = 0,c = 0,d = 0;
	int na = 0, nb = 0, nc = 0, nd = 0;
	for(int i = 0;i < n;i++){
		na = (b+c+d)%MOD;
		nb = (a+c+d)%MOD;
		nc = (a+b+d)%MOD;
		nd = (a+b+c)%MOD;
		a = na, b = nb, c = nb, d = nd;
	}
	cout << na << "\n";
}