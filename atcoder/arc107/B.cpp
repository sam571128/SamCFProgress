#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	auto f = [&](int a, int b){
		return min(b-1,2*a+1-b);
	};
	int ans = 0;
	for(int i = 2;i <= 2*n;i++){
		if(i-k < 2 || i-k > 2*n) continue;	
		ans += f(n,i)*f(n,i-k);
	}
	cout << ans << "\n";
}