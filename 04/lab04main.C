#include <lab04.h>
#include <iomanip>
#include <climits>

using namespace std;

int main()
{
  uint e, j, n;
  IntegerSet s;

  while (cin >> n)
  {
    for (j = 0; j < n; ++j)
    {
      cin >> e;
      s.insertElement(e);
    }
    cout << "s = ";
    s.print(cout);
    cout << "s.cardinality() = " << s.cardinality() << endl << endl;

    // Use the copy constructor to make a copy of s
    IntegerSet sCopy(s);
    cout << "sCopy = ";
    sCopy.print(cout);
    cout << "sCopy.cardinality() = " << sCopy.cardinality() << endl << endl;

    // Use the copy constructor to initialize t with the complement of s
    IntegerSet t(s.complement());
    cout << "t = ";
    t.print(cout);
    cout << "t.cardinality() = " << t.cardinality() << endl << endl;

    // clear set s
    for (e = 0; e < N; ++e)
    {
      if (s.isMember(e))
        s.deleteElement(e);
    }
    cout << "s.cardinality() = " << s.cardinality() << endl << endl;
  }
    
  return 0;
}

uint IntegerSet::word(uint n) const
{
  return n / (CHAR_BIT * sizeof(uint));
}

uint IntegerSet::bit(uint n) const
{
  return n % (CHAR_BIT * sizeof(uint));
}

void IntegerSet::allocateStorage()
{
  uint numElements = word(N - 1) + 1;

  // dynamically allocate memory for the bitVector
  try
  {
    bitVector = new uint[numElements];
  }
  catch (bad_alloc memoryAllocationException)
  {
    cerr << "Unable to allocate memory. Exiting." << endl;
    cerr << memoryAllocationException.what() << endl;
    exit(EXIT_FAILURE);
  }
}
