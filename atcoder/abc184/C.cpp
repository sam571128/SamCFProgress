#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c&&b==d){
		cout << 0 << "\n";
	}else if(a+b==c+d||a-b==c-d||abs(a-c)+abs(b-d)<=3){
		cout << 1 << "\n";
	}else if((a+b&1)==(c+d&1)||abs((a-b)-(c-d))<=3||abs(a+b-c-d) <= 3){
		cout << 2 << "\n";
	}else{
		cout << 3 << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}