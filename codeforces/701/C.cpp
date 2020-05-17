#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio 
	int n;
	string str;
	cin >> n >> str;
	set<char> s;
	for(int i = 0;i < str.size();i++){
		s.insert(str[i]);
	}
	int k = s.size();
	s.clear();
	map<char,int> m;
	int l = 0,r = 0,ans = INT_MAX;
	while(l < n){
		while(r < n&&s.size()<k){
			s.insert(str[r]);
			m[str[r]]++;
			r++;
		}
		if(s.size()==k){
			ans = min(ans,r-l);
		}
		if(m[str[l]]==1) s.erase(str[l]);
		m[str[l]]--;
		l++;
	}
	cout << ans << "\n";
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}