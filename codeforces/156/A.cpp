#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	string s,u;
	cin >> s >> u;
	int ans = 0;
	for(int i = 0;i < s.size();i++){
		int tmp = 0;
		for(int j = 0;j < u.size() && j < s.size()-i;j++){
			if(s[i+j]==u[j]) tmp++;
		}
		ans = max(ans,tmp);
	}
	for(int i = 0;i < u.size();i++){
		int tmp = 0;
		for(int j = 0;j < s.size() && j < u.size()-i;j++){
			if(u[i+j]==s[j]) tmp++;
		}
		ans = max(ans,tmp);
	}
	cout << (u.size()-ans) << "\n";
}