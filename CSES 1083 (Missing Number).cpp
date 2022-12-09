/**
 *   Author:  Wasi Ur Rahman
 *   FROM RMSTU
**/
#include <bits/stdc++.h>
#define fast            	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll           		long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define dourao       		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define min3(a,b,c)    		min(a,min(b,c))
#define min4(a,b,c,d)  		min(d,min3(a,b,c))
#define max3(a,b,c)    		max(a,max(b,c))
#define max4(a,b,c,d)  		max(d,max3(a,b,c))
#define all(v)         		v.begin(),v.end()
#define revall(v)      		v.rbegin(),v.rend()
#define pb             		push_back
#define eb             		emplace_back
#define setbits(x)     		__builtin_popcountll(x)
#define zrobits(x)     		__builtin_ctzll(x)
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)
#define poro                freopen("input.txt","r",stdin)
#define lekho               freopen("output.txt","w",stdout)
#define println()           cout << endl
#define printi(x)           printf("%d\n")
#define printii(x,y)        printf("%d %d\n")
#define printiii(x,y,z)     printf("%d %d %d\n")
#define printl(x)           printf("%lld\n")
#define printll(x,y)        printf("%lld %lld\n")
#define printlll(x,y,z)     printf("%lld %lld %lld\n")
using namespace __gnu_pbds;
using namespace std;
/*************************************
**          A S S E M B L E         **
**************************************/
bool isPrime(ll n){if(n <= 1)return false;for (ll i = 2; i * i < n; i++)if (n % i == 0)return false;return true;}
ll fact(ll n){ll res = 1;for(ll i = n;i>=1;i--)res *= i;return res;}
ll nCr(ll n,ll r){return (fact(n)/(fact(r)*fact(n-r)));}
ll nPr(ll n,ll r){return fact(n)/fact(n-r);}
ll modpow(ll a, ll n, ll mod){ll res=1;while(n>0){if(n&1) res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
const int mod=998244353;
inline int add(int a,int b){if((a+=b)>=mod)a-=mod;return a;}
inline int dec(int a,int b){if((a-=b)<0)a+=mod;return a;}
inline int mult(int a,int b){long long t=1ll*a*b;if(t>=mod)t%=mod;return t;}
inline int power(int a,int b){int out=1;while(b){if(b&1)out=mult(out,a);a=mult(a,a);b>>=1;}return out;}
/*************************************
**  E N D    G A M E   S T A R T S  **
**************************************/
int main(){
	dourao;
	int cases;
	cin >> cases;
	int ff = cases;
	int fff = cases-1;
	cases--;
	int cnt = 0;
	int pnt = 0;
	vector<int> v;
	while(cases--){
		int p;
		cin >> p;
		if(p == ff)
            cnt++;
        else if(p == fff)
            pnt++;
		v.pb(p);
	}
	if(cnt == 0)
    {
        cout << ff << endl;
        return 0;
    }else if(pnt == 0){
        cout << fff << endl;
        return 0;
    }
	sort(all(v));
	for(int i = 1;i<v.size();++i){
		if(v[i] - v[i - 1] > 1){
			cout << v[i] - 1 << endl;
			return 0;
		}
	}
}
