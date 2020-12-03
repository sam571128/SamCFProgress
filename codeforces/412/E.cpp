#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(s[i]=='@'){
			int cnt1 = 0, cnt2 = 0;
			for(int j = i-1;~j;j--){
				if(s[j]=='@'||s[j]=='.')
					break;
				if(s[j]>='a'&&s[j]<='z')
					cnt1++;
			} 
			for(int j = i+1;j < n;j++){
				if(s[j]=='@'||s[j]=='_')
					break;
				if(s[j]=='.'){
					if(j==i+1) break;
					int k = j+1;
					for(;k < n;k++){
						if(!(s[k]>='a'&&s[k]<='z'))
							break;
						cnt2++;
					}
					i = k-1;
					break;
				} 
			}
			ans += cnt1*cnt2;
		}
	}
	cout << ans << "\n";
}