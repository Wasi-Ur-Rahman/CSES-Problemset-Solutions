/**
 *   Author:  Wasi Ur Rahman
 *   FROM RMSTU
**/
#include <bits/stdc++.h>
#define ll                      long long
#define boost                   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ticktock                cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n"
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(d,min3(a,b,c))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(d,max3(a,b,c))
#define all(v)                  v.begin(),v.end()
#define revall(v)               v.rbegin(),v.rend()
#define pb                      push_back
#define eb                      emplace_back
#define setbits(x)              __builtin_popcountll(x)
#define zrobits(x)              __builtin_ctzll(x)
#define si(x)                   scanf("%d", &x)
#define sii(x, y)               scanf("%d %d", &x, &y)
#define siii(x, y, z)           scanf("%d %d %d", &x, &y, &z)
#define siiii(p,x, y, z)        scanf("%d %d %d %d",&p, &x, &y, &z)
#define sl(x)                   scanf("%lld", &x)
#define sll(x, y)               scanf("%lld %lld", &x, &y)
#define slll(x, y, z)           scanf("%lld %lld %lld", &x, &y, &z)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define println()               cout << endl
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define printi(x)               printf("%d\n")
#define printii(x,y)            printf("%d %d\n")
#define printiii(x,y,z)         printf("%d %d %d\n")
#define printl(x)               printf("%lld\n")
#define printll(x,y)            printf("%lld %lld\n")
#define printlll(x,y,z)         printf("%lld %lld %lld\n")
#define chkbit(x,p)             ((x&(1LL<<p))?1:0)
#define setbit(x,p)             x|=(1LL<<p)
#define clrbit(x,p)             x=x&(~(1LL<<p))
#define revbit(x,p)             (chkbit(x,p)?clrbit(x,p):setbit(x,p))
using namespace std;
/*************************************
*          A S S E M B L E         *
**************************************/
vector<string>vec_spltr(string s){s+=',';vector<string>res;while(!s.empty())
res.push_back(s.substr(0, s.find(','))),s=s.substr(s.find(',')+1);return res;}
void dbg_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,
__attribute__((unused))int LINE_NUM){cerr<<endl;}template<typename Head,typename... Tail>
void dbg_out ( vector <string> args, int idx, int LINE_NUM, Head H, Tail... T)
{if(idx>0)cerr<<", ";else cerr << "Line(" << LINE_NUM << ") ";stringstream ss;ss<<H;
cerr<<args[idx]<<" = "<<ss.str();dbg_out(args,idx+1,LINE_NUM, T...);}
#define debug(...) dbg_out(vec_spltr(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
bool isPrime(ll n){if(n <= 1)return false;for (ll i = 2; i * i < n; i++)if (n % i == 0)return false;return true;}
ll fact(ll n){ll res = 1;for(ll i = n;i>=1;i--)res *= i;return res;}
ll nCr(ll n,ll r){return (fact(n)/(fact(r)*fact(n-r)));}
ll nPr(ll n,ll r){return fact(n)/fact(n-r);}
ll modpow(ll a, ll n, ll mod){ll res=1;while(n>0){if(n&1) res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
vector<ll> DivStore(vector<ll>& v,ll n){for (ll i=1; i<=sqrt(n); i++){if(n%i == 0){if (n/i == i)v.pb(i);else{v.pb(i);v.pb(n/i);}}}return v;}
#define mod 100000009
inline int add(int a,int b){if((a+=b)>=mod)a-=mod;return a;}
inline int dec(int a,int b){if((a-=b)<0)a+=mod;return a;}
inline int mult(int a,int b){long long t=1ll*a*b;if(t>=mod)t%=mod;return t;}
inline int power(int a,int b){int out=1;while(b){if(b&1)out=mult(out,a);a=mult(a,a);b>>=1;}return out;}
vector<ll> primes;
bool prime[mod];
void sieve(){
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(ll i = 4;i<=mod;i+=2)
        prime[i] = false;
    for(ll i = 3;i*i<=mod;i+=2){
        if(prime[i] == true){
            for(ll j = i*2;j<=mod;j+=i)
                prime[j] = false;
        }
    }
}
bool check(ll arr[],ll n){
    for(ll i = 1;i<=n-1;i++){
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}
ll arr[mod];
ll dp[mod];
ll k = 1e9+7;
/*************************************
*  E N D    G A M E   S T A R T S    *
**************************************/
int main(){
    boost;
    ll cases;
    cin >> cases;
    while(cases--){
        ll y,x;
        cin >> y >> x;
        ll m = max(y,x);
        ll k = min(y,x);
        ll a = m * m;
        if(m == y){
            if(m % 2 == 1){
                ll in = a - m;
                in+=1;
                //cout << in << endl;
                cout << in - abs(m-k) << endl;
            }else{
                ll in = a - m;
                in+=1;
                //cout << in << endl;
                cout << in + abs(m-k) << endl;
            }
        }else{
            if(m % 2 == 1){
                ll in = a - m;
                in+=1;
                //cout << in << endl;
                cout << in + abs(m-k) << endl;
            }else{
                ll in = a - m;
                in+=1;
                //cout << in << endl;
                cout << in - abs(m-k) << endl;
            }
        }
    }
    return 0;
}
