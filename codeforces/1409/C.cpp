#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x,y;
	cin >> n >> x >> y;
	int ma = INT_MAX, ansa = 0, ansd = 0;
	for(int i = 1;i <= 50;i++){
		for(int j = 1;j <= 50;j++){
			bool hasx = false, hasy = false;
			for(int k = 0;k < n;k++){
				if(j+i*k==x) hasx = true;
				if(j+i*k==y) hasy = true;
			}
			if(hasx&&hasy){
				ansa = j, ansd = i;
				goto print;
			}
		}
	}
	print:;
	for(int k = 0;k < n;k++){
		cout << ansa+ansd*k << " ";
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}