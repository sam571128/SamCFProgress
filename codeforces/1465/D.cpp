#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int pref[2][N], suff[2][N];
signed main(){
	fastio
	string s;
	cin >> s;
	int n = s.size();
	s = '$' + s;
	int x,y;
	cin >> x >> y;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		pref[0][i] = pref[0][i-1], pref[1][i] = pref[1][i-1];
		if(s[i]=='0') pref[0][i]++;
		else pref[1][i]++;
	}
	for(int i = n;i;i--){
		suff[0][i] = suff[0][i+1], suff[1][i] = suff[1][i+1];
		if(s[i]=='0') suff[0][i]++;
		else suff[1][i]++;
	}
	for(int i = 1;i <= n;i++){
		if(s[i]=='0'){
			ans += x*suff[1][i+1]; //01
		}else{
			ans += y*suff[0][i+1]; //10
		}
	}
	if(x > y){
		int arr[2] = {};
		int now = ans;
		for(int i = n;i;i--){
			if(s[i]!='?') continue;
			suff[0][i+1] += arr[0], suff[1][i+1] += arr[1];
			now += x * (suff[1][i+1]-pref[0][i-1]);
			now += y * (pref[1][i-1]-suff[0][i+1]);
			arr[1]--,arr[0]++;
			ans = min(now,ans);
		}		
	}else{
		int arr[2] = {};
		int now = ans;
		for(int i = 1;i <= n;i++){
			if(s[i]!='?') continue;
			pref[0][i-1] += arr[0], pref[1][i-1] += arr[1];
			now += x * (suff[1][i+1]-pref[0][i-1]);
			now += y * (pref[1][i-1]-suff[0][i+1]);
			arr[1]--,arr[0]++;
			ans = min(now,ans);
		}	
	}
	cout << ans << "\n";
}