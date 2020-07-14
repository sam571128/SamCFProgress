#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n,m;
	cin >> n >> m;
	vector<ll> v;
	for(ll i = m;i > 0&&n;i--){
		ll lowbit = i&-i;
		if(n-lowbit<0) continue;
		n -= lowbit;
		v.push_back(i); 
	}
	if(n) cout << -1 << "\n";
	else{
		cout << v.size() << "\n";
		for(ll x : v) cout << x << " ";
	}
}