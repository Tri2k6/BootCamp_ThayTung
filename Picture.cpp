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

int n,m;
int a[maxN][maxN];

int dx1[] = {0,0,1,-1};
int dy1[] = {1,-1,0,0};

int dx2[] = {0,1,1,-1,-1};
int dy2[] = {0,-1,1,-1,1};

bool isMaTran(int i,int j) {
    if (i <= 0 || i > n || j <= 0|| j > m) {
        return false;
    }
    return true;
}

bool check1(int i,int j) {
    for (int k = 0;k<4;k++) {
        int x = i + dx1[k];
        int y = j + dy1[k];
        if (isMaTran(x,y) && a[x][y] == 0) return false;
    }
    return true;
}

bool check2(int i,int j) {
    for (int k = 0;k<5;k++) {
        int x = i + dx2[k];
        int y = j + dy2[k];
        if (isMaTran(x,y) && a[x][y] == 0) return false;
    }
    return true;
}

void ToMau1(int i,int j) {
    for (int k = 0;k<4;k++) {
        int x = i + dx1[k];
        int y = j + dy1[k];
        if (isMaTran(x,y) && a[x][y] == 1) {
            a[x][y] = 2;
        }
    }  
}

void ToMau2(int i,int j) {
    for (int k = 0;k<5;k++) {
        int x = i + dx2[k];
        int y = j + dy2[k];
        if (isMaTran(x,y) && a[x][y] == 1) a[x][y] = 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> n >> m;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            char x;
            input >> x;
            if (x == '.') {
                a[i][j] = 0;
            } else {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            if (a[i][j] == 0) {
                if (check1(i,j)) {
                    ToMau1(i,j);
                }
            } else {
                if (check2(i,j)) ToMau2(i,j);
                if (check1(i,j)) ToMau1(i,j);
            }
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            if (a[i][j] == 1) return output << "NO",0;
        }
    }
    output << "YES";
    return 0;
}
