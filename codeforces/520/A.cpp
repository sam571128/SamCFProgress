#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	string b;
	cin >> b;
	set<char> s; 
	for(int i = 0;i < a;i++){
		s.insert(tolower(b[i]));
	} 
	if(s.size()>=26){
		cout << "YES";
	}else{
		cout << "NO";
	}
}