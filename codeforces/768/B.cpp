#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll l,r;
ll cnt(ll n,ll low,ll high){
	if(high < l || low > r) return 0;
	if(n == 1) return 1;
	ll ans = 0;
	ll mid = low+(high-low)/2;
	if(n%2&&mid<=r&&mid>=l) ans++;
	return ans + cnt(n>>1,low,mid-1) + cnt(n>>1,mid+1,high);
}
int main(){
	fastio
	ll n,len = 1;
	cin >> n >> l >> r;
	ll x = n;
	while(x > 1){
		len = len*2+1;
		x>>=1;
	}
	cout << cnt(n,1,len);
}