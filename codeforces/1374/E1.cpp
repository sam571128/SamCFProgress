#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	//fastio
	vector<ll> v;
	ll n,k;
	cin >> n >> k;
	ll cntA = 0, cntB = 0;
	vector<ll> A,B,both;
	for(ll i = 0;i < n;i++){
		ll t,a,b;
		cin >> t >> a >> b;
		if(a&b&1) both.push_back(t);
		else if(a&1) A.push_back(t);
		else if(b&1) B.push_back(t);
	}
	sort(A.begin(),A.end(),greater<ll>());
	sort(B.begin(),B.end(),greater<ll>());
	sort(both.begin(), both.end(),greater<ll>());
	if(A.size()+both.size()<k||B.size()+both.size()<k){
		cout << -1 << "\n";
		return 0;
	}
	ll ans = 0;
	for(ll i = 0;i < max((ll)0,k-(ll)both.size());i++){
		ans += A.back(), A.pop_back();
		ans += B.back(), B.pop_back();
	}
	k-=max((ll)0,k-(ll)both.size());
	while(k){
		if(A.size()==0||B.size()==0){
			while(k){
				k--;
				ans += both.back();
				both.pop_back();
			}
			break;
		}
		k--;
		if(A.back()+B.back()<=both.back()){
			ans += A.back(); A.pop_back();
			ans += B.back(); B.pop_back();
		}else{
			ans += both.back(); both.pop_back();
		}
	}
	cout << ans << "\n";
}