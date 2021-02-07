#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int l[N], r[N]; //l/r[i] means how many times when a[i] is the left/rightmost and maximum/minimum

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	iota(l,l+N,0);
	iota(r,r+N,0);
	for(int i = 1;i < n;i++){
		int pos = i;
		while(pos && arr[pos-1] <= arr[i]) pos = r[pos-1];
		r[i] = pos;
	}
	for(int i = n-2;~i;i--){
		int pos = i;
		while(pos < n-1 && arr[i] > arr[pos+1]) pos = l[pos+1];
		l[i] = pos;
	}
	int ans = 0;
	for(int i = 0;i < n;i++) ans += (i - r[i] + 1)*(l[i]- i + 1)*arr[i];
	iota(l,l+N,0);
	iota(r,r+N,0);
	for(int i = 1;i < n;i++){
		int pos = i;
		while(pos && arr[pos-1] >= arr[i]) pos = r[pos-1];
		r[i] = pos;
	}
	for(int i = n-2;~i;i--){
		int pos = i;
		while(pos < n-1 && arr[i] < arr[pos+1]) pos = l[pos+1];
		l[i] = pos;
	}
	for(int i = 0;i < n;i++) ans -= (i - r[i] + 1)*(l[i]- i + 1)*arr[i];
	cout << ans << "\n";
}