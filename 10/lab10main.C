#include <lab10.h>
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

    c = -t;
    cout << " c = " << c;

    u = s + t;
    cout << " u = " << u;

    i = s * t;
    cout << " i = " << i;

    d = s - t;
    cout << " d = " << d;

    IntegerSet sd(s / t);
    cout << "sd = " << sd;

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
