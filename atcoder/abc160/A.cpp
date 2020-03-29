#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	string a;
	cin >> a;
	if(a[2]==a[3]&&a[4]==a[5]){
		cout << "Yes";
	}else{
		cout << "No";
	}
}