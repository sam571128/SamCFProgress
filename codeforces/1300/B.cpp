#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	//cout << n << "\n";
	int arr[2*n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+2*n);
	vector<int> a,b;
	for(int i = 0;i < 2*n;i++){
		if(n&1^1) if(i>=2*n-2&&n!=1) {a.push_back(arr[i]);continue;}
		if(i&1^1) a.push_back(arr[i]);
		else b.push_back(arr[i]);
	}
	cout << abs(a[a.size()/2] - b[b.size()/2]) << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}