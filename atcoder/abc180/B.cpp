#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	int a,b,c;
	a = b = c = 0;
	for(int i = 0;i < n;i++){
		a += abs(v[i]);
		b += v[i]*v[i];
		c = max(c,abs(v[i])); 
	}
	cout << setprecision(20) << a << "\n" << sqrt(b) << "\n" << c << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}