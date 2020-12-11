#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
bool check[N];
signed main(){
	fastio
	int k,l,r,t,x,y;
	cin >> k >> l >> r >> t >> x >> y;
	if(k < l || k > r){
		cout << "NO\n";
		return 0;
	}
	if(y<x){
		if(k+y > r) k-=x, t--;
		if(k < l){
			cout << "NO\n";
			return 0;
		}
		int tmp = (k-l)/(x-y);
		if(tmp >= t){
			cout << "YES\n";
			return 0;
		}else{
			cout << "NO\n";
			return 0;
		}
	}
	while(t){	
		if(check[k%x]){
			cout << "YES\n";
			return 0;
		}
		check[k%x] = 1;

		int tmp = min((k-l)/x,t);
		k -= x*tmp;
		t -= tmp;

		if(t==0){
			cout << "YES\n";
			return 0;
		}
		t--;
		if(k+y<=r) k += y;
		k-=x;
		if(k < l || k > r){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}