#include <bits/stdc++.h>
 
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int x = 0, y = 0;
	for(int i = 0;i < n;i++){
		if(i%2!=arr[i]%2){
			if(arr[i]%2==0) x++;
			else y++;
		}
	}
	if(x!=y) cout << -1 << "\n";
	else cout << x << "\n";
}
 
int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}