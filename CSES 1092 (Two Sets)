// Author: Wasi Ur Rahman
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
int main(){
    ll n;
    cin >> n;
    vector<ll> v;
    for(ll i = 0;i<n;i++)
        v.pb(i+1);
    reverse(all(v));
    set<ll> s;
    ll in = 0;
    ll sum = 0;
    ll need = (n*(n+1))/4;
    for(ll i = 0;i<v.size();i++)
    {
        sum += v[i];
        s.insert(v[i]);
        if(sum >= need){
            s.erase(v[i]);
            sum = sum - v[i];
            in = i;
            break;
        }
    }
    ll k = abs(sum - need);
    s.insert(k);
    set<ll> p;
    ll kk = 0;
    for(ll i = in;i<v.size();i++)
    {
        if(v[i] == k)
            continue;
        p.insert(v[i]);
        kk += v[i];
    }
    if(kk == need)
    {
        cout << "YES" << endl;
        cout << s.size() << endl;
        for(auto it:s)
            cout << it << " ";
        cout << endl;
        cout << p.size() << endl;
        for(auto it:p)
            cout << it << " ";
        cout << endl;
    }else cout << "NO" << endl;
    return 0;
}
