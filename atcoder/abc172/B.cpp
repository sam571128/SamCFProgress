#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	for(int i = 0;i < s1.size();i++){
		if(s1[i]!=s2[i]) ans++;
	}
	cout << ans << "\n";
}