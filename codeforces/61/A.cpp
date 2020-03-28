#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	string a,b;
	cin >> a >> b;
	for(int i = 0;i < a.size();i++){
		if(a[i]!=b[i]){
			cout << "1";
		}else{
			cout << "0";
		}
	}
}