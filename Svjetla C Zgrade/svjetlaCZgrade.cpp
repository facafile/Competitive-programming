#include <iostream>
#include <vector>
#include <string>

using namespace std;

void construct_segment_tree(vector<pair<int, string>> &segtree,
                            vector<pair<int, string>> &a, int n)
{
   for (int i = 0; i < n; i++)
      segtree[n + i] = a[i];

   for (int i = n - 1; i >= 1; i--)
      segtree[i] = max(segtree[2 * i],
                       segtree[2 * i + 1]);
}

void update(vector<pair<int, string>> &segtree, int pos, pair<int, string> value,
            int n)
{
   pos += n;

   segtree[pos] = value;

   while (pos > 1)
   {
      pos >>= 1;

      segtree[pos] = max(segtree[2 * pos],
                         segtree[2 * pos + 1]);
   }
}

pair<int, string> range_query(vector<pair<int, string>> &segtree, int left, int right,
                              int n)
{
   pair<int, string> pom;
   string pom2;
   left += n;
   right += n;

   int ma = INT_MIN;

   while (left < right)
   {
      if (left & 1)
      {
         if (segtree[left].first > ma)
         {
            ma = segtree[left].first;
            pom2 = segtree[left].second;
         }
         left++;
      }

      if (right & 1)
      {
         right--;
         if (segtree[right].first > ma)
         {
            ma = segtree[right].first;
            pom2 = segtree[right].second;
         }
      }

      left /= 2;
      right /= 2;
   }
   pom.first = ma;
   pom.second = pom2;
   return pom;
}

int main()
{
   int n, q;
   string naziv;
   int br;
   cin >> n;
   vector<pair<int, string>> kol;
   vector<int> xx;
   pair<int, string> x;
   for (int i = 0; i < n; i++)
   {
      cin >> x.first >> x.second;
      kol.push_back(x);
      xx.push_back(x.first);
   }
   vector<pair<int, string>> segtree(2 * n);
   construct_segment_tree(segtree, kol, n);
   cin >> q;
   for (int i = 0; i < q; i++)
   {
      pair<int, string> par;
      string slovo;
      int l, r;
      cin >> slovo >> l >> r;
      if (slovo == "q")
      {
         par = range_query(segtree, l - 1, r, n);
         cout << par.second << endl;
      }
      else
      {
         int value = kol[l - 1].first + r;
         pair<int, string> pp;
         pp.first = value;
         pp.second = kol[l - 1].second;
         kol[l - 1] = pp;
         update(segtree, l - 1, pp, n);
      }
   }
}

// https://www.geeksforgeeks.org/iterative-segment-tree-range-maximum-query-with-node-update/