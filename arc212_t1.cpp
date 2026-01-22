// IN THE NAME OF ALLAH

/* ---------------------------- */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dd;
typedef long double ldd;
#define tst int T;cin>>T;for(int t=1;t<=T;t++)
#define nl cout<<"\n";
#define rep(i,l,r) for (int i=l;i<r;i++)
#define per(i,r,l) for (int i=r;i>l;i--)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define vi vector<int>
#define vll vector<ll>
#define PI 3.14159265
#define fi first
#define se second
const ll MOD1=1e9+7;
const ll MOD2=998244353;
ll mod=MOD1;
ll po(ll x,ll y,ll _prime=mod) {if(y<0)return 0;y%=(_prime-1);ll res=1;while(y>0){if(y&1)res=(res*x)%_prime;x=(x*x)%_prime;y>>=1;}return (res%_prime);}
ll gcd(ll a, ll b){if(a<b) swap(a,b);if(b==0) return a;return gcd(a%b,b);}
ll ans,k;

#define int long long

void solve(){    
    cin>>k;
    for(int i=2;i<k-i*2;i++){
        int b=k-i*2;
        ans+=(3*(i-1)*(i-1)*(b-1)%MOD2*(i+i)%MOD2);
        ans%=MOD2;
    }

    if(!(k%3)){
        int a=k/3;
        ans+=(a-1)*(a-1)*(a-1)%MOD2*(a+a)%MOD2;
        ans%=MOD2;
    }

    for(int i=2;;i++){
        if((k-i)%2) continue;
        int b=(k-i)/2;
        
        if(b<=i) break;
        ans+=(3*(i-1)*(b-1)*(b-1)%MOD2*(i+b)%MOD2);
        ans%=MOD2;
    }

    for(int i=2;3*i<=k;i++){
        for(int b=i+1;b<k-i-b;b++){
            int c=k-i-b;
            ans+=(6*(i-1)*(b-1)*(c-1)%MOD2*(i+b)%MOD2);
            ans%=MOD2;
        }
    }cout<<ans;
}

signed main(){
    // ++(int)0; // crash
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    // tst
    // {
        solve();
    // }
}
/*
*/