#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,x,t;
	cin >> n >> x >> t;
	cout << (n/x + (n%x ? 1 : 0)) * t << "\n";
}