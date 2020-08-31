//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n,k;

int cnt(int x){
	int i = 0;
	while(x < n) x = 2*x+1,i++;
	int res = ((int)1<<(i+1))-1;
	res -= min(x-n, (int)1<<i);
	return res;
}

signed main(){
	fastio
	cin >> n >> k;
	int l = 0, r = (n-1)>>1, mid;
	int mxn = -1;
	while(l < r){
		mid = l+r+1>>1;
		if(cnt(2*mid+1)<k)
			r = mid-1;	
		else 
			l = mid;
	}
	mxn = max(mxn,2*l+1);
	l = 0, r = n>>1;
	while(l < r){
		int mid = l+r+1>>1;
		if(cnt(2*mid)+cnt(2*mid+1)<k)
			r = mid-1;	
		else
			l = mid;
	}
	mxn = max(mxn,2*l);
	cout << mxn << "\n";
}