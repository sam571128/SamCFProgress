#include <bits/stdc++.h>
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
void solve(){
	int n,k;
	cin >> n >> k;
	set<int> s;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		s.insert(tmp);
	}
	if(k==1){
		if(s.size()==1){
			cout << 1 << "\n";
		}else{
			cout << -1 << "\n";
		}
		return;
	}
	cout << max(1,((int)s.size()-1+k-2)/(k-1)) << "\n";
}
 
signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}