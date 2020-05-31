#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		int odd = 0, even = 0;
		for(int i = 0,tmp;i < n;i++){
			cin >> tmp;
			if(tmp&1)odd++;
			else even++;
		}
		int ans = false;
		for(int i = 1;i <= odd && i <= x;i+=2){
			if(x-i<=even){
				ans = true;
			}
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
}