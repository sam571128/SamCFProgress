#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int cnt[N][1<<6], can[N], num[N];
signed main(){
	fastio
	string s;
	cin >> s;
	int n = s.size();
	for(auto c : s){
		num[c-'a']++;
	}
	string ans(n+1,'a');
	int m;
	cin >> m;
	while(m--){
		int pos;
		string str;
		cin >> pos >> str;
		for(int i = 0;i < str.size();i++) can[pos] |= (1<<(str[i]-'a'));
	}
	for(int i = n;i;i--){
		if(!can[i]) can[i] = (1<<6)-1;
		for(int S = 0; S < (1<<6);S++){
			if((S&can[i])==can[i]) cnt[i][S]++;
			cnt[i][S] += cnt[i+1][S];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 6;j++){
			if(num[j]&&can[i]&(1<<j)){
				num[j]--;
				bool ok = true;
				for(int S = 0; S < (1<<6);S++){
					int tmp = 0;
					for(int k = 0;k < 6;k++) if(S&(1<<k)) tmp+=num[k];
					if(tmp < cnt[i+1][S]) ok = false;
				}
				if(ok){
					ans[i] = char('a'+j);
					goto next;
				}
				num[j]++;
			}
		}
		cout << "Impossible\n";
		return 0;
		next:;
	}
	cout << ans.substr(1) << "\n";
}