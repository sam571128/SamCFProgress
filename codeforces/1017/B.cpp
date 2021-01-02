#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a,b,c,d;
signed main(){
	fastio
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for(int i = 0;i < n;i++){
		if(s1[i]=='0'&&s2[i]=='0') a++;
		else if(s1[i]=='1'&&s2[i]=='1') b++;
		else if(s1[i]=='1'&&s2[i]=='0') c++;
		else if(s1[i]=='0'&&s2[i]=='1') d++;
	}
	cout << a*c+a*b+c*d << "\n";
}