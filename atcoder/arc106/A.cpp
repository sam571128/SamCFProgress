#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int tmp1 = 1;
	for(int i = 1;i < 100;i++){
		if(LLONG_MAX/tmp1 < 3) break;
		tmp1 *= 3;
		if(tmp1 > n) break;
		int tmp2 = 1;
		for(int j = 1;j < 100;j++){
			if(LLONG_MAX/tmp2 < 5) break;
			tmp2 *= 5;
			if(tmp2 > n) break;
			if(LLONG_MAX-tmp1 > 0){
				if(tmp1 + tmp2 == n){
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
	}
	cout << -1 << "\n";
}