#include <bits/stdc++.h>
 
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
signed main(){
	fastio
	int n;
	string str;
	cin >> n >> str;
	int m = str.size()-1, ans = 0, tmp = 1;
	while(m>=0){
		for(int i = 0;i <= m;i++){
			if(str[i]=='0'&&i!=m) continue;
			int sum = 0;
			for(int j = i;j <= m;j++){
				sum = sum*10 + (str[j]-'0');
				if(sum >= n) goto next;
			}
			ans += sum*tmp;
			tmp = tmp*n;
			m = i-1;
			next:;		
		}
	}
	cout << ans << "\n";
}
