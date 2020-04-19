#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	int p,x,y,i,k;
    while(cin>>x>>y){
        if(x==0&&y==0)
            k=0;
        else{
            p=max(abs(x),abs(y));
            k=(p-1)*4;
            if(x==p&&y>1-p&&y<=p)
                k+=1;
            else if(y==p&&x>=-p&&x<=p)
            k+=2;
            else if(x==-p&&y>=-p&&y<=p)
            k+=3;
            else if(y<0&&x>y&&x<=-y)
            k+=4;
        }
        cout<<k<<endl;
    }
    return 0;
}
