#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 25; i >= 0;i--){
		for(int j = 0;j < s.size();j++){
			if(j!=0 && s[j]== i + 'a' && s[j-1] + 1 == s[j]){
				s.erase(j,1);
				ans++;
				j--;
				continue;
			}
		}
		for(int j = s.size()-1;j >= 0;j--){
			if(j!=s.size()-1 && s[j]== i + 'a' && s[j+1] + 1 == s[j]){
				s.erase(j,1);
				ans++;
				j++;
				continue;
			}
		}
	}
	cout << ans << "\n";
}