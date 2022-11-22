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

ifstream input("input.txt");
ofstream output("output.txt");

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


const ll cs = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

int a[2];
int b[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> a[1] >> b[1] >> a[2] >> b[2];
    auto powmod = [](ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) {
                res *= a;
            }
            b >>= 1;
            a *= a;
        }
        return res;
    };
    ll left1 = powmod(a[1], b[1] - 1);
    ll right1 = left1 * b[1] - 1;

    ll left2 = powmod(a[2], b[2] - 1);
    ll right2 = left2 * b[2] - 1;

    ll lr = max(left1,left2);
    ll rr = min(right1,right2);
    if (lr > rr) output << 0;
    else output << rr - lr + 1;
    return 0;
}
