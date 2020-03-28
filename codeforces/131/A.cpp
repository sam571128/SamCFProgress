#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	string a;
	cin >> a;
	for(int i = 1;i < a.size();i++){
		if(a[i]!=toupper(a[i])){
			cout << a;
			return 0;
		}
	}
	for(int i = 0;i < a.size();i++){
		if(a[i]==tolower(a[i]))
			a[i] = toupper(a[i]);		
		else
			a[i] = tolower(a[i]);
	}
	cout << a;
}