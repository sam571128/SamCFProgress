#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	string a;
	cin >> a;
	for(int i = 0;i < a.size();++i){
		if(a[i]=='H'||a[i]=='Q'||a[i]=='9'){
			cout<< "YES";
			return 0;
		}
	}
	cout << "NO";
}