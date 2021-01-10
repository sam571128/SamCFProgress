#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int tmp = n%(2*k+1);
	cout << n/(2*k+1)+(tmp!=0) << "\n";
	if(tmp==0||tmp>k) tmp = k+1;
	while(tmp <= n){
		cout << tmp << " ";
		tmp += 2*k+1;
	}	
}