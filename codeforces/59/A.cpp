#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	string a;
	cin >> a;
	int upper = 0;
	int lower = 0;
	for(int i = 0;i < a.size();i++){
		if(a[i] == toupper(a[i])){
			upper++;
		}else{
			lower++;
		}
	}
	for(int i = 0;i < a.size();i++){
		if(upper>lower){
			a[i] = toupper(a[i]);
		}else{
			a[i] = tolower(a[i]);
		}
	}
	cout << a;
}