#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int x,y,a,b;
		cin >> x >> y >> a >> b;
		if((-x+y)%(a+b)==0){
			cout << (-x+y)/(a+b) << "\n";
		}else{
			cout << -1 << "\n";
		}
	}
}