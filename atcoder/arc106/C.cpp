#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	if(m < 0){
		cout << -1 << "\n";
		return 0;
	}
	if(n==1&&m==0){
		cout << 1 << " " << (int)1e9 << "\n";
		return 0;
	}
	//5 1 => [1,10^9], [2,10^9-1], [3,10^9-2], [4,5], [6,7]
	if(n < m+2){
		cout << -1 << "\n";
		return 0;
	}
	cout << 1 << " " << (int)1e9 << "\n";
	for(int i = 1;i <= n-(m+2);i++){
		cout << 1+i << " " << (int)1e9-i << "\n";
	}
	for(int i = 0; i <= m;i++){
		cout << n-m+2*i << " " << n-m+2*i+1 << "\n";
	}
}