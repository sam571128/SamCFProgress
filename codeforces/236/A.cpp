#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	set<char> a;
	string b;
	cin >> b;
	for(int i = 0;i < b.size();i++){
		a.insert(b[i]);
	}
	if(a.size()%2==0){
		cout<<"CHAT WITH HER!";
	}else{
		cout <<"IGNORE HIM!";
	}
	return 0;
}