#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9;
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		set<char> s;
		int l = 0, r = 0, ans = INF;
		map <int , int >  cnt;
		 
		while ( l < str.size() ) {
		    while ( r < str.size() && s.size() < 3 ) {
		       s.insert(str[r]);
		       cnt[str[r]]++;
		       r++;
		    }
		    if (s.size() >= 3) {
				ans = min(ans, r-l);
			}
		    if ( cnt[str[l]] == 1 ) s.erase(str[l]); 
		    cnt[str[l]]--; 
		    l++;
		}
		if ( ans == INF ) ans = 0;
		 
		cout << ans << endl;
	}
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}