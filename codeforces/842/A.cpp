#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int l,r,x,y,k;
	cin >> l >> r >> x >> y >> k;
	for(int i = x;i <= y;i++){
		if(l <= k*i&&r >= k*i){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}