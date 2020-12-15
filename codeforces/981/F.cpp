#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n, L;
	cin >> n >> L;
	int a[n], b[3*n];
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++){
		cin >> b[i];
		b[n+i] = b[i]+L;
		b[2*n+i] = b[i]-L;
	}
	sort(a,a+n);
	sort(b,b+3*n);

	auto check = [&](int val){
		int l = 0, r = 3*n-1;
		for(int i = 0;i < n;i++){
			while(a[i]-b[l] > val) l++;
			while(b[r]-a[i] > val) r--;
			l++,r++;
		}
		return (l<=r);
	};

	int l = 0, r = L;
	while(l < r){
		int mid = l+r>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << "\n";
}