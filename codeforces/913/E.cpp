#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 256;
string e[N], t[N], f[N];


bool ok = true;
void get(string &a, string b){
	if(a==""||(a.size() == b.size() ? a > b : a.size() > b.size())){
		a = b;
		ok = true;
	}
}

int to(string s){
	int res = 0;
	reverse(s.begin(),s.end());
	for(auto c : s){
		res = res*2 + c-'0';
	}
	return res;
}

signed main(){
	fastio
	f[240] = "x"; //x = '11110000' = 240
	f[204] = "y"; //y = '11001100' = 204
	f[170] = "z"; //z = '10101010' = 170
	
	while(ok){
		ok = false;
		for(int i = 0;i < N;i++) if(e[i]!="") get(f[i],"(" + e[i] + ")");
		for(int i = 0;i < N;i++) if(f[i]!="") get(f[i^255],"!"+f[i]);
		for(int i = 0;i < N;i++) if(f[i]!="") get(t[i], f[i]);
		for(int i = 0;i < N;i++)
			if(t[i]!="")
			for(int j = 0;j < N;j++)
				if(t[j]!="")
					get(t[i&j],t[i] + "&" + t[j]);
		for(int i = 0;i < N;i++) if(t[i]!="") get(e[i], t[i]);
		for(int i = 0;i < N;i++)
			if(e[i]!="")
			for(int j = 0;j < N;j++)
				if(e[j]!="")
				get(e[i|j],e[i] + "|" + e[j]);
	}

	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		cout << e[to(s)] << "\n";
	}
}