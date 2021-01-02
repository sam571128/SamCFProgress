#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	map<string,int> m;
	string ans = "satisfiable";
	for(int i = 0;i < n;i++){
		string tmp;
		cin >> tmp;
		if(tmp[0]=='!'){
			if(m[tmp.substr(1)]){
				ans = tmp.substr(1);
			}else{
				m[tmp]++;
			}
		}else{
			if(m["!"+tmp]){
				ans = tmp;
			}else{
				m[tmp]++;
			}
		}
	}
	cout << ans << "\n";
}