#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll h,c,t;
	cin >> h >> c >> t;
	if(h==t){
		cout << 1 << "\n";
		return;
	}
	if(t <= (h+c)/2){
		cout << 2 << "\n";
		return;
	}
	ll k = (h-t)/(2*t-h-c);
	//cout << fabs((1.0*k*(h+c)+h)/(2*k+1)) << " " << fabs((1.0*(k+1)*(h+c)+h)/(2*k+3)) << "\n";
	if(abs(k*(h+c)+h-t*(2*k+1))*(2*k+3) <= abs((k+1)*(h+c)+h-t*(2*k+3))*(2*k+1)) {
		cout << 2*k+1 << "\n";
	}else{
		cout << 2*k+3 << "\n";
	}
	
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}