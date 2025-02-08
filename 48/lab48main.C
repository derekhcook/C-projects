#include <iostream>
#include <iomanip>
#include <random>
#include <queue>

using namespace std;

template<typename T>
void distribution(const priority_queue<T>& pq, ostream& os);

#include "lab48.cpp"

int main()
{
  priority_queue<int> pq1;
  priority_queue<char> pq2;
  priority_queue<double> pq3;
  default_random_engine ran;
  uniform_int_distribution<> dis1(0, 4), dis2(0,25), dis3(0,7);
  int i;

  cout << "Distribution of PQ1 with size() = " << pq1.size() << endl;
  distribution(pq1, cout);

  for (i = 0; i < 5; ++i)
  {
    pq1.push(dis1(ran));
    cout << endl << "Distribution of PQ1 with size() = " << pq1.size()
         << endl;
    distribution(pq1, cout);
  }

  for (i = 0; i < 10000; ++i)
  {
    pq1.push(dis1(ran));
    pq2.push(static_cast<char>(dis2(ran) + 65));
    pq3.push(dis3(ran) * 0.125);
  }

  cout << endl << "Distribution of PQ1" << endl;
  distribution(pq1, cout);
  cout << endl << "Distribution of PQ2" << endl;
  distribution(pq2, cout);
  cout << fixed << showpoint << setprecision(3);
  cout << endl << "Distribution of PQ3" << endl;
  distribution(pq3, cout);

  return 0;
}
