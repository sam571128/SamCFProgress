#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int ans = INT_MAX;
		for(int i = 0;i <= s.size();i++){
			int count_1 = 0;
			int count_2 = 0;
			for(int j = 0;j < i;j++){
				if(s[j]=='1'){
					count_1++;
				}
				if(s[j]=='0'){
					count_2++;
				}
			}
			for(int j = i;j < s.size();j++){
				if(s[j]=='0'){
					count_1++;
				}
				if(s[j]=='1'){
					count_2++;
				}
			}
			ans = min({ans,count_1,count_2});
		}
		cout << ans << "\n";
	}
}