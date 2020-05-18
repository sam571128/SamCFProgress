#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6;
int pref[N];
int checkSubstr(string s1,string s2){
	int ret = 0;
	for(int i = 0;i < s1.size();i++){
		if(i+s2.size()>s1.size()) break;
		bool check = true;
		for(int j = 0;j < s2.size();j++){
			if(s1[i+j]!=s2[j]) check = false;
		}
		if(check) ret++;
	}
	return ret;
}
int main(){
	fastio
	int n,m,q;
	cin >> n >> m >> q;
	string s1,s2;
	cin >> s1 >> s2;
	
	for(int i = 0; i < s1.size();i++){
		pref[i] = checkSubstr(s1.substr(i),s2);
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		--l,r-=m-1;
		cout << (r>=l&&r>=0&&l>=0 ? pref[l]-pref[r] : 0) << "\n";
	}
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}