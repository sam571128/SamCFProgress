#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> v, v2;

void finddiv(int n){
	for(int i = 1;i*i <= n;i++){
		if(n%i==0) v.push_back(i);
		if(n%i==0&&i*i!=n) v2.push_back(n/i);
	}
}

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	finddiv(n);
	for(int i = v2.size()-1;~i;i--) v.push_back(v2[i]);
	if(v.size() < k) cout << -1 << '\n';
	else cout << v[k-1] << "\n";
}