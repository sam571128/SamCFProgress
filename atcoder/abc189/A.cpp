#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s;
	cin >> s;
	cout << (s[0]==s[1]&&s[1]==s[2] ? "Won\n" : "Lost\n");
}