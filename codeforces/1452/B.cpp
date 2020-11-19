#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int ma = INT_MIN, mi = INT_MAX, sum = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		ma = max(tmp,ma);
		mi = min(tmp,mi);
		sum += tmp;
	}
	cout << (ma*(n-1)-sum >= 0 ? ma*(n-1)-sum : (sum/(n-1)+(sum%(n-1)>0))*(n-1)-sum) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}
/*
1
4
3 3 2 2
=> 
*/