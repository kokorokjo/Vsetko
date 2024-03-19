#include <bits/stdc++.h>
using namespace std;
const int NMAX = 11234567;
struct Nd
{
    vector<Nd *> e;
    int val;
    int opt, opt_up;
    int calc_up(Nd *from)
    {
        opt = val;
        for (Nd *it : e)
            if (it != from)
            {
                opt += max(0, it->calc_up(this));
            }
        opt_up = opt;
        return opt;
    }
    void calc_down(Nd *from, int from_up)
    {
        opt += max(0, from_up);
        for (Nd *it : e)
            if (it != from)
            {
                it->calc_down(this, opt - max(0, it->opt_up));
            }
    }
} nd[NMAX];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf(" %c", &c);
        nd[i].val = c =='M' ? 1 : -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        nd[x].e.push_back(nd + y);
        nd[y].e.push_back(nd + x);
    }
    nd->calc_up(NULL);
    nd->calc_down(NULL, 0);
    for (int i = 0; i < n; i++)
        printf("%d\n", nd[i].opt);
    return 0;
}
