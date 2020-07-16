#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll arr[26], arr2[26][26];
int main(){
	fastio
	string s;
	cin >> s;
	ll ans = 0;
	for(int i = 0;i < s.size();i++){
		for(int j = 0;j < 26;j++){
			arr2[j][s[i]-'a'] += arr[j];
		}
		arr[s[i]-'a']++;
	}
	for(int i = 0;i < 26;i++){
		ans = max(ans, arr[i]);
		for(int j = 0;j < 26;j++) ans = max(ans,arr2[i][j]);
	}	
	cout << ans << "\n";
}