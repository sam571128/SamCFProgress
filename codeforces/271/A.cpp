#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int hasdistinct(int b){
	string a = to_string(b);
	set<int> s;
	for(int i = 0;i < a.size();i++){
		s.insert(a[i]);
	}
	if(s.size()!=a.size()){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	fastio
	int a;
	cin >> a;
	a++;
	while(!hasdistinct(a)){
		a++;
	}
	cout<< a;
}