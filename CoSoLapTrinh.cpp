#include <bits/stdc++.h>
using namespace std;

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

const ll cs = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

ll powmod(ll a,int b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int cntdigit(ll n) {
    int cnt = 0;
    if (n == 0) return 1;
    while (n) {
        cnt++;
        n/= 10;
    }
    return cnt;
}

ll Prefix[cs];

void Build() {
    Prefix[0] = 0;
    Prefix[1] = 1;
    for (int i = 2;i<=19;i++) {
        Prefix[i] = Prefix[i - 1] * 10 + 1;
    }
}

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> n;
    int res = 0;
    Build();
    while (n > 0) {
        int tmp = cntdigit(n);
        if (n > Prefix[tmp]) {
            n -= Prefix[tmp];
            res++;
        } else if (n > Prefix[tmp - 1] && tmp - 1) {
            n -= Prefix[tmp - 1];
            res++;
        } else break;
    }
    output << res;
    return 0;
}
