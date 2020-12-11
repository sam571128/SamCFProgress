#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int cntz(int num){
	return __builtin_ffsll(num)-1;
}

signed main(){
	fastio
	int n, q;
	cin >> n >> q;
	n = n+1>>1;
	while(q--){
		int m;
		string s;
		cin >> m >> s;
		for(int i = 0;i < s.size();i++){
			int cnt = cntz(m);
			if(s[i]=='U'){
				if(m==n) continue;
				if(cntz(m+(1LL<<cnt))==cnt+1)
					m += (1LL<<cnt);
				else 
					m -= (1LL<<cnt);
			}else if(s[i]=='L'){
				if(cnt==0) continue;
				m -= (1LL<<cnt-1);
			}else if(s[i]=='R'){
				if(cnt==0) continue;
				m += (1LL<<cnt-1);
			}
		}
		cout << m << "\n";
	}
}