#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	int x;
	cin >> s >> x;
	int n = s.size();
	int arr[n];
	memset(arr,0,sizeof arr);
	for(int i = 0;i < n;i++){
		if(s[i]=='1'){
			if(i-x>=0&&arr[i-x]) continue;
			if(i-2*x >= 0&&s[i-2*x]=='1') arr[i-x] = 1;
			else if(i+2*x < n&&s[i+2*x]=='1') arr[i+x] = 1;
			else if(i-2*x < 0 && i-x >= 0) arr[i-x] = 1;
			else if(i+2*x >= n && i+x < n) arr[i+x] = 1;
			else{
				cout << -1 << "\n";
				return;
			} 
		}else{
			if(i-x>=0&&arr[i-x]==1){
				cout << -1 << "\n";
				return;
			}
		}
	}
	for(auto x : arr) cout << x;
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}