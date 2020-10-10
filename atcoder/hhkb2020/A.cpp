#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s,t;
	cin >> s >> t;
	if(s=="Y") cout << char(toupper(t[0])) << "\n";
	else cout << t << "\n";
}	