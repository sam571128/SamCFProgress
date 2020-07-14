#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n,k;
	cin >> n >> k;
	if(k==1){
		cout << n << "\n";
		return 0;
	}else{
		ll ans = 1;
		while(ans < n){
			ans = 2*ans+1;
		}
		cout << ans << "\n";
	}
}