#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<pair<int, int>> useky;

auto spoj_intervaly(pair<int, int> prvy, pair<int, int> druhy)
{
    pair<int, int> spojeny = {min(prvy.first, druhy.first), max(prvy.second, druhy.second)};
    useky.erase(prvy);
    useky.erase(druhy);
    useky.insert(spojeny);
    return useky.find(spojeny);
}

int main()
{
    //using auto x = set.find() and 
    // x->first and
    //*x /= {a, b}
    int n, q;
    scanf(" %d %d", &n, &q);
    useky.insert({-2, -2});
    useky.insert({n + 2, n + 2});
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf(" %d %d", &a, &b);
        useky.insert({a, b + 1});
        auto novy = useky.find({a, b + 1});
        while (true)
        {
            auto dalsi = next(novy);
            if (dalsi->first <= novy->second)
            {
                novy = spoj_intervaly(*novy, *dalsi);
            }
            else
                break;
        }
        while (true)
        {
            auto pred = prev(novy);
            if (novy->first <= pred->second)
            {
                novy = spoj_intervaly(*novy, *pred);
            }
            else
                break;
        }
        printf("%ld\n", useky.size() - 2);
    }
}
