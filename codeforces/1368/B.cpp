#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll cnt[10];
const string s = "codeforces";
int main(){
	fastio
	ll n;
	cin >> n;
	ll count = 0;
	bool ok = 0;
	while(!ok){
		for(int i = 0;i < 10;i++){
			cnt[i]++;
			ll mult = 1;
			for(int j = 0;j < 10;j++){
				mult *= cnt[j];
			}
			if(mult >= n){
				ok = 1;
				break;
			}
		}
	}
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < cnt[i];j++) cout << s[i];
	}
}