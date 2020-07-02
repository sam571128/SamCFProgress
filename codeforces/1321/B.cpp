#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	ll ma = 0;
	unordered_map<ll,ll> m;
	for(ll i = 1, tmp;i <= n;i++){
		cin >> tmp;
		ma = max(tmp,ma);
		m[tmp-i] += tmp;
	}
	for(auto itr = m.begin(); itr!=m.end();itr++){
		ma = max(itr->second,ma);
	}
	cout << ma << "\n";
}