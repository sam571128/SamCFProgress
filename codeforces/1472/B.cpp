#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int x = 0, y = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(tmp==1) x++;
		else y++;
	}
	y%=2;
	x-=y*2;
	if(x < 0||x%2==1){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}