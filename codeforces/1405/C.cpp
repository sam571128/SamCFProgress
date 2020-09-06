#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i = 0;i < k;i++){
		int j = i;
		int tmp = -1;
		while(j < n){
			if(s[j]=='1'){
				if(tmp==0){
					cout << "NO\n";
					return;
				}else{
					tmp = 1;
				}
			}
			if(s[j]=='0'){
				if(tmp==1){
					cout << "NO\n";
					return;
				}else{
					tmp = 0;
				}
			}
			j+=k;
		}
		j = i;
		if(tmp == -1) continue;
		while(j < n){
			s[j] = tmp+'0';
			j+=k;
		}
	}
	int cnta = 0, cntb = 0;
	for(int i = 0;i < k;i++){
		if(s[i]=='1') cnta++;
		else if(s[i]=='0') cntb++;
		if(cnta > k/2 || cntb > k/2){
			cout << "NO\n";
			return;
		}
		if(i-k>=0){
			if(s[i-k]=='1') cnta--;
			else if(s[i-k]=='0') cntb--;
		}
	}
	cout << "YES\n";
	return;
	
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}