#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int d,k;
	cin >> d >> k;
	int n = d/sqrt(2)/k;
	if((n*k)*(n*k)+k*k*(n+1)*(n+1) <= d*d){
		cout << "Ashish" << "\n";
	}else{
		cout << "Utkarsh" << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}