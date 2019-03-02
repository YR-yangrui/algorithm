#include<bits/stdc++.h>
#define RI register int

using namespace std;

const int N = 50;
int to[N], nxt[N], head[N], cnt, n, m, sum, ans;

inline void add(int u, int v) {
        to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
}

inline int read() {
        RI s = 0, c = getchar();
        while (!isdigit(c)) c = getchar();
        while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
        return s;
}

int main()
{
        freopen("闭合子图计数.in","r",stdin);
        freopen("闭合子图计数.out","w",stdout);
        n = read(), m = read(), sum = 1 << n - 1;
        for (RI i = 1, u, v; i <= m; ++i) u = read(), v = read(), add(u, v);
        for (RI S = 1; S <= sum; ++S) {
                for (RI i = 1; i <= n; ++i)
                        for (RI j = head[i]; j; j = nxt[j])
                                if ((1 << (to[j] - 1) & S) == 0) goto A;
                ++ans;
                A:;
        }
        printf("%d", ans);
}
