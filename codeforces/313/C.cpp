#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	vector<ll> v;
	v.resize(n);
	cin >> v[0];
	for(int i = 1;i < n;i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end(),greater<int>());
	ll pref[n+1] = {};
	pref[0] = v[0];
	for(int i = 1;i <= n;i++){
		pref[i] = pref[i-1]+v[i];
	}
	int p = 0;
	ll ans = 0;
	while(pow(4,p)<=n){
		ans += pref[(int)pow(4,p)-1];
		p++;
	}
	cout << ans << "\n";
}