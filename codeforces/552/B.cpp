#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	ll power = 0;
	ll ans = 0;
	while(n >= pow(10,power)){
		if(n <= pow(10,power+1)-1) ans += (n-pow(10,power)+1)*(power+1);
		else ans += (pow(10,power+1)-pow(10,power))*(power+1);
		power++;
	}
	cout << ans << "\n";
}