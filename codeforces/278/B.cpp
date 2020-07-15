#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int main(){
	fastio
	int n;
	cin >> n;
	string s[n];
	for(auto &x : s) cin >> x;
	
	for(int i = 0;i <= 26;i++){
		char c1 = 'a' + i-1;
		for(int j = 0;j < 26;j++){
			char c;
			c = 'a' + j;
			string tmp = "";
			if(c1!='a'-1) tmp+=c1;
			tmp+=c;
			bool ok = true;
			for(int k = 0;k < n;k++){
				if(s[k].find(tmp)!=string::npos){
					ok = false;
					break;
				}
			}
			if(ok){
				cout << tmp << "\n";
				return 0;
			}
		}
	}
	
}