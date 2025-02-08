#include <lab08.h>
#include <iomanip>

using namespace std;

int main()
{
  uint e, j, n;
  IntegerSet s, t;

  while (cin >> n)
  {
    for (j = 0; j < n; ++j)
    {
      cin >> e;
      s = s + e;
    }
    cout << "s = ";
    cout << s;
    cout << "s.cardinality() = " << s.cardinality() << endl << endl;

    // Use operators - and = to initialize t with the complement of s
    t = -s;
    cout << "t = ";
    cout << t;
    cout << "t.cardinality() = " << t.cardinality() << endl << endl;

    // clear set s
    for (e = 0; e < N; ++e)
    {
      if (s.isMember(e))
        s = s - e;
    }
    cout << "s.cardinality() = " << s.cardinality() << endl << endl;
  }
    
  return 0;
}
