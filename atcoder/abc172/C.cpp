#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 2e5;
ll a[N+1], b[N+1];
int main(){
	fastio
	ll n,m,k;
	cin >> n >> m >> k;
	
	for(int i = 0;i < n;i++){
		cin >> a[i+1];
		a[i+1] += a[i];
	}
	for(int i = 0;i < m;i++){
		cin >> b[i+1];
		b[i+1] += b[i];
	}
	ll ans = 0;
	for(ll i = 0, j = m;i <= n;i++){
		if(a[i] > k) break;
		while(a[i] + b[j] > k) j--;
		ans = max(i+j,ans);
	}
	cout << ans << "\n";
}	