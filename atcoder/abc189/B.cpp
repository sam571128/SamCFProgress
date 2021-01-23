#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,x;
	cin >> n >> x;
	x *= 100;
	int num = 0;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		num += a*b;
		if(num > x){
			cout << i+1 << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}