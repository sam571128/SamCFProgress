#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
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
	sort(all(v));
	int now = v.back(); v.pop_back();
	cout << now << " ";
	while(!v.empty()){
		sort(all(v),[&](int a, int b){
			return gcd(a,now) < gcd(b,now);
		});
		cout << v.back() << " ";
		now = gcd(now,v.back()); v.pop_back();
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}