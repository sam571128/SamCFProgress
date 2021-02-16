#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 105;

int arr[N], ans[N];

void div(int l, int r, int num){
	if(l==r){
		ans[l] = num;
		return;
	}
	int mx = 0, idx = -1;
	for(int i = l;i <= r;i++){
		if(arr[i] > mx) idx = i, mx = arr[i];
	}
	ans[idx] = num;
	if(l!=idx) div(l,idx-1,num+1);
	if(r!=idx) div(idx+1,r,num+1);
};

void solve(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> arr[i];
	div(0,n-1,1);
	for(int i = 0;i < n;i++) cout << ans[i]-1 << " ";
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}