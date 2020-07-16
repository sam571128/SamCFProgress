#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int vis[26][26];

int main(){
	fastio
	int n, hem = 0;
	string s,t;
	cin >> n >> s >> t;
	for(int i = 0;i < n;i++){
		if(s[i]!=t[i]) vis[s[i]-'a'][t[i]-'a'] = i+1, hem++;
	}
	for(int i = 0;i < 26;i++){
		for(int j = 0;j < 26;j++){
			if(vis[i][j]&&vis[j][i]){
				cout << hem-2 << '\n' << vis[i][j] << ' ' << vis[j][i] << "\n";
				return 0;
			}
		}
	}
	for(int i = 0;i < n;i++){
		if(s[i]==t[i]) continue;
		for(int j = 0;j < 26;j++){
			if(vis[j][s[i]-'a']){
				cout << hem - 1 << "\n" << i+1 << " " << vis[j][s[i]-'a'] << "\n";
				return 0;
			}
		}
	}
	cout << hem << "\n" << -1 << " " << -1 << "\n";
}