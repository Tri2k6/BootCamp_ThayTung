#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>

template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'}; 
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i; 
    return sign ? -x : x; }
 
template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do 
        s += digit_to_char(x%base), x /= base;
    while (x > 0); 
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }
 
template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }
 
template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
 
using  lll =   signed __int128; 
using ulll = unsigned __int128;
 
inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }

#define input cin
#define output cout
#define ll long long 
#define pii pair<ll,ll>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<ll>
#define int128 __int128

const ll cs = 1e6 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

ll n,k;
ll a[cs];
ll Tree[4 * cs];

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void BuildTree(int id,int left,int right) {
    if (left == right) {
        Tree[id] = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    BuildTree(id * 2,left,mid);
    BuildTree(id * 2 + 1,mid + 1,right);
    Tree[id] = gcd(Tree[id * 2], Tree[id * 2 + 1]);
}

ll GetGcd(int id,int left,int right,int u,int v) {
    if (left > v || right < u) return 0;
    if (u <= left && right <= v) return Tree[id];
    int mid = (left + right) >> 1;
    ll m1 = GetGcd(id * 2,left,mid,u,v);
    ll m2 = GetGcd(id * 2 + 1,mid + 1,right,u,v);
    return gcd(m1,m2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> n >> k;
    for (int i = 1;i<=n;i++) {
        input >> a[i];
    }
    BuildTree(1,1,n);
    ll res = GetGcd(1,1,n,1,k);
    for (int i = k + 1;i<=n;i++) {
        res = max(res, GetGcd(1,1,n,i - k + 1,i));
    }
    output << res;
    return 0;
}
