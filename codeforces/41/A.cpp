#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	string a,b;
	cin >> a >> b;
	reverse(a.begin(),a.end());
	if (a==b){
		cout <<"YES";
	}else{
		cout <<"NO";
	}
}