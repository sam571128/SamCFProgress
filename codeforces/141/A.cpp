#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	string a,b,c;
	cin >> a >> b >> c;
	string d = a+b;
	sort(d.begin(),d.end());
	sort(c.begin(),c.end());
	if(d==c){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}