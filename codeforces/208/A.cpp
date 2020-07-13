#include <bits/stdc++.h>
#include <string>
 
#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;
 
int main(){
	fastio
	string a;
	cin >> a;
	int count = 1;
	for(int i=0;i<a.size();i++){
	    if(a[i]=='W'&& a[i+1]=='U' && a[i+2]=='B'){
	        i+=2;
	        if(!count){
	            cout<<" ";
	        }
	        continue;
	    }else {
	        count=0;
	        cout<<a[i];
	    }
	}
	return 0;
}