#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		ll int a,b;
		cin >> a >> b;
		if(b>a) swap(b,a);
		ll int x;
		if(a%b==0){
			x = a/b;
		}else{
			cout << "-1" << "\n";
			continue;
		}
		if((x != 0) && ((x & (x - 1)) == 0)){
			ll int tmp = log2(x);
			cout << tmp/3 + (tmp%3==0 ? 0 : 1) << "\n";
		}else{
			cout << "-1" << "\n";
		}
	}
}