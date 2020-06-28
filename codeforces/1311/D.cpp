#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int ans = INT_MAX;
	int x,y,z;
	for(int i = 1;i <= 15000;i++){
		for(int j = i;j <= 15000;j+=i){
			for(int k = j;k <= 15000;k += j){
				int tmp = abs(i-a)+abs(j-b)+abs(k-c);
				if(ans > tmp){
					ans = tmp;
					x = i, y = j,z = k;
				} 
			}
		}
	}
	cout << ans << "\n";
	cout << x << " " << y << " " << z << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}