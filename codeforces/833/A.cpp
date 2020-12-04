#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	if(fabs(pow(a*b,(double)1/3)-round(pow(a*b,(double)1/3))) > 1e-4){
		cout << "NO\n";
	}else{
		int val = round(pow(a*b,(double)1/3));
		if(a%val!=0||b%val!=0){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}
