#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	string s;
	cin >> s;
	int a[s.size()] = {};
	int b[s.size()] = {};
	for(int i = 0;i < s.size();i++){
		if(i!=0)a[i] = a[i-1],b[i] = b[i-1];
		if(s[i] == 'a') a[i]++;
		if(s[i] == 'b') b[i]++;
	}
	int ans = INT_MIN;
	for(int i = 0;i < s.size();i++){
		for(int j = i;j < s.size();j++){
			ans = max(ans,(i==0?0:a[i-1])+b[j]-(i==0?0:b[i-1])+a[s.size()-1]-(j==0?0:a[j-1]));
		}
	}
	cout << ans << "\n";
}