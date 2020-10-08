#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cout << ((i+1)%((n-k)/2+1) ? 1 : 0); 
	}
}