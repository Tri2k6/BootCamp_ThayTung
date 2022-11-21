#include <bits/stdc++.h>
using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

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

#define ll __int128
#define pii pair<ll,ll>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<ll>

ll n,m;
ll res = 0;

ll TinhTong(ll k) {
    return k * (k + 1) / 2;
}

ll TinhTong2(ll k) {
    return k * (k + 1) * (2 *k + 1) / 6;
}

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> t;
    while (t--) {
        input >> n >> m;
        ll k = min(n,m);
        res = (k + 1) * n * m - TinhTong(k) * (n + m) + TinhTong2(k);
        // res =  k * (k + 1) * (3 * m - n + 1) / 6;
        output << res << endl;
    }

    return 0;
}
