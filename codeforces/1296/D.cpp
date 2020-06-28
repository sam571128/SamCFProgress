#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,a,b,k;
	cin >> n >> a >> b >> k;
	int h[n];
	for(int i = 0;i < n;i++){
		cin >> h[i];
		h[i]%=(a+b);
		if(h[i]==0) h[i] += a+b;
		h[i] = ((h[i]+a-1)/a) - 1;
	}
	sort(h,h+n);
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(k >= h[i]){
			ans++;
			k-=h[i];
		}
	}
	cout << ans << "\n";
}