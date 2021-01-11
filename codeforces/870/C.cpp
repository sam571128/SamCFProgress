#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	//The smallest composite is 4
	//1 2 3 5 7 11 can not be split into composite
	if(n==1||n==2||n==3||n==5||n==7||n==11){
		cout << -1 << "\n";
		return;
	}
	if((n%4)&1^1){
		//4, 6
		cout << n/4 << "\n";
	}else if((n%4)&1){
		//5+4=9
		//4+4+4+3=15 => 6,9 => 2
		cout << n/4-1 << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}