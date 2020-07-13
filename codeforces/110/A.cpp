#include <bits/stdc++.h>
#include <string>
 
#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
int main(){
	fastio
	string a;
	cin >> a;
	ll int b = 0;
	for(ll int i = 0;i < a.size();i++){
		if(a[i]=='4'||a[i]=='7'){
			b++;
		}
	}
	string c = to_string(b);
	for(int i = 0;i < c.size();i++){
		if(!(c[i]=='4'||c[i]=='7')){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}