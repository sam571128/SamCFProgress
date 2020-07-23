#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int d[n+1];
	d[0] = d[1] = 0;
	for(int i = 2;i <= n;i++){
		d[i] = i*d[i-1] + 1 * (i%2==0?1:-1);
	}
	int sum = 0, tmp1 = 1, tmp2 = 1;
	for(int i = 1;i <= k;i++){
		tmp1*=(n-i+1);
		tmp2*=i;
		sum += d[i]*(tmp1/tmp2);
	}
	cout << sum+1 << "\n";
}