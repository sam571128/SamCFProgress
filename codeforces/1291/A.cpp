#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio 
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int odd = 0;
		for(int i = 0;i < n;i++){
			if((s[i]-'0')%2==1) odd++;
		}
		if(odd<2){
			cout << -1 << "\n";
		}
		else{
			int count = 0;
			for(int i = 0;i < n;i++){
				if(count==2) break;
				if((s[i]-'0')%2==1) {cout << s[i]; count++;}
			}
			cout << "\n";
		}
	}
}