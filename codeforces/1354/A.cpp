#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		ll int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a<=b){
			cout << b << "\n";
			continue;
		}
		a -= b;
		ll int ans = 0;
		ans += b;
		if(c<=d){
			cout << -1 << "\n";
			continue;
		}
		ans += ceil(1.0*a/(c-d))*c;
		cout << ans << "\n";
	}
}