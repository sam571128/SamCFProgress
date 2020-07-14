#include <bits/stdc++.h>
 
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int main(){
	fastio
	ll n,k,s;
	cin >> n >> k >> s;
	if(k>s||k*(n-1)<s){
		cout << "NO\n";
		return 0;
	}
	ll now = 1;
	cout << "YES\n";
	while(k){
		ll d = min(n-1,s-(k-1));
		now = (now-d>0 ? now-d : now+d);
		cout << now << " ";
		s-=d;
		k--;
	}
}