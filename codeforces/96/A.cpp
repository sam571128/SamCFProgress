#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	string a;
	cin >> a;
	int count = 1;
	for(int i = 1;i < a.size();i++ ){
		if(count >= 7){
			cout<< "YES";
			return 0;
		}
		if(a[i]==a[i-1]){
			count++;
		}else{
			count = 1;
		}
	}
	if(count >= 7){
			cout<< "YES";
			return 0;
	}
	cout<<"NO";
	return 0;
}