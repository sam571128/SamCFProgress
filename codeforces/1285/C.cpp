//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int ans = n;
	for(int i = 2;i*i <= n;i++){
		if(n%i==0){
			if(lcm(n/i,i)==n) ans = min(n/i,ans);
		}
	}
	cout << n/ans << " " << ans << "\n";
}