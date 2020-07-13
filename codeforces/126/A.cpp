#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll t1,t2,x1,x2,t0;
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if(t2==t0){
		cout << (t1==t0 ? x1 : 0) << ' ' << x2 << "\n";
		return 0; 
	}
	ll mx = 0, my = x2;
	double mi = t2;
	for(ll x = 1; x <= x1;x++){
		ll dx = x, dy = ((x*(t0-t1))+t2-t0-1)/(t2-t0);
		if(dy > x2) continue;
		double tmp = 1.0 * (dx*t1+dy*t2)/(dx+dy);
		if(tmp < mi - 1e-6 || abs(tmp-mi) < 1e-6 && dx+dy > mx+my){
			mi = tmp;
			mx = dx;
			my = dy;
		} 
	}
	cout << mx << " " << my << "\n";
}