#include <lab06.h>
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
      s.insertElement(e);
    }
    cout << " s = ";
    s.print(cout);
    cout << "s.cardinality() = " << s.cardinality() << endl;

    cin >> n;
    for (j = 0; j < n; ++j)
    {
      cin >> e;
      t.insertElement(e);
    }
    cout << " t = ";
    t.print(cout);
    cout << "t.cardinality() = " << t.cardinality() << endl;

    // Use the copy constructor to initialize u with the union of s & t
    IntegerSet u(s.Union(t));
    cout << " u = ";
    u.print(cout);

    // Use the copy constructor to initialize i with the intersection of s & t
    IntegerSet i(s.intersection(t));
    cout << " i = ";
    i.print(cout);

    // Use the copy constructor to initialize d with the difference of s & t
    IntegerSet d(s.difference(t));
    cout << " d = ";
    d.print(cout);

    // Use the copy constructor to initialize sd with the symmetric
    // difference of s & t
    IntegerSet sd(s.symmetricDifference(t));
    cout << "sd = ";
    sd.print(cout);
    cout << endl;

    // clear sets s & t
    for (e = 0; e < N; ++e)
    {
      if (s.isMember(e))
        s.deleteElement(e);
      if (t.isMember(e))
        t.deleteElement(e);
    }
  }
    
  return 0;
}
