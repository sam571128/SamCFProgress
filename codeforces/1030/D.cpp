#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	if((2*n*m)%k){
		cout << "NO\n";
		return 0;
	}else{
		bool check = k%2;
		if(!check) k/=2;
		int tmp = gcd(n,k);
		int x = n/tmp, y = m/(k/tmp);
		if(check){
			if(x < n) x *= 2;
			else y *= 2;
		}
		cout << "YES\n";
		cout << 0 << " " << 0 << "\n";
		cout << x << " " << 0 << "\n";
		cout << 0 << " " << y << "\n";
	}
}