#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	if(n==1){
		cout << "1 1\n";
		cout << 0 << "\n";
		cout << "1 1\n";
		cout << 0 << "\n";
		cout << "1 1\n";
		cout << -a[0] << "\n";
		return; 
	}else if(n==2){
		cout << "1 1" << "\n";
		cout << -a[0] << "\n";
		cout << "2 2" << "\n";
		cout << -a[1] << "\n";
		cout << "1 2" << "\n";
		cout << 0 << " " << 0 << "\n";
		return; 
	}
	cout << "1 " << n-1 << "\n";
	for(int i = 0;i < n-1;i++){
		
		cout << a[i]*(n-1) << " ";
		a[i] = a[i]*n;
	}
	cout << "\n";
	cout << "2 " << n << "\n";
	for(int i = 0;i < n-2;i++) cout << 0 << " ";
	cout << a[n-1]*(n-1) << "\n";
	a[n-1] *= n;
	cout << 1 << " " << n << "\n";
	for(int i = 0;i < n;i++){
		cout << -a[i] << " ";
	}	
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}