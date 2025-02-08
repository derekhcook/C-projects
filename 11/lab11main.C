#include <lab11.h>
#include <iomanip>

using namespace std;

int main()
{
  uint e, j, n;
  IntegerSet s, t, c, u, i, d;

  while (cin >> n)
  {
    for (j = 0; j < n; ++j)
    {
      cin >> e;
      s = s + e;
    }
    cout << " s = " << s;
    cout << "s.cardinality() = " << s.cardinality() << endl;

    cin >> n;
    for (j = 0; j < n; ++j)
    {
      cin >> e;
      t = t + e;
    }
    cout << " t = " << t;
    cout << "t.cardinality() = " << t.cardinality() << endl;

    cout << boolalpha << "s == t = " << (s == t) << endl;
    cout << "s <= t = " << (s <= t) << endl;
    cout << "s <  t = " << (s <  t) << endl;

    // clear sets s & t
    for (e = 0; e < N; ++e)
    {
      if (s.isMember(e))
        s = s - e;
      if (t.isMember(e))
        t = t - e;
    }
  }
    
  return 0;
}
