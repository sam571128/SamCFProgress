#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s;
	cin >> s;
	int n = s.size();
	int cnta[n+1] = {}, cntb[n+1] = {};
	for(int i = 0;i < n;i++){
		if(s[i]=='a') cnta[i+1]++;
		else cntb[i+1]++;
		cnta[i+1] += cnta[i], cntb[i+1] += cntb[i];
	}
	int ans = INT_MAX;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			//cout << i << " " << j << " " << (cnta[i]-cnta[0]+cntb[j]-cntb[i]+cnta[n-1]-cnta[j]) << "\n";
			ans = min(ans,n-(cnta[i-1]+cntb[j]-cntb[i-1]+cnta[n]-cnta[j-1]));
		}
	}
	cout << n-ans << "\n";
}