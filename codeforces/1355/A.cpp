#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll findnext(ll n){
	string s = to_string(n);
	ll maxDigit= 0; ll minDigit = 9;
	for(ll int i = 0;i <= 4;i++){
		if(count(s.begin(),s.end(),i+'0')){
			maxDigit = max(maxDigit,i);
			minDigit = min(minDigit,i);
		}
		if(count(s.begin(),s.end(),(9-i)+'0')){
			maxDigit = max(maxDigit,9-i);
			minDigit = min(minDigit,9-i);
		}
	}
	return n + maxDigit*minDigit;
}
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		ll a,k;
		cin >> a >> k;
		--k;
		while(k-->0){
			ll next = findnext(a);
			if(next==a){
				break;
			}
			a = next;
		}
		cout << a << "\n";
	}
}