#include <iostream>
#include <cstdlib>
#include <string>
#include <lab25.h>

using namespace std;

int main()
{
  Accumulator<int> intAcc(5), sum;
  Accumulator<string> words;
  Accumulator<char> letter('A');
  string vowels("aeiou");

  cout << "intAcc = " << intAcc.getTotal() << endl;
  cout << "sum = " << sum.getTotal() << endl;
  cout << "words = " << words.getTotal() << endl;
  cout << "letter = " << letter.getTotal() << endl << endl;

  while (intAcc.getTotal() > 0)
  {
    sum.addValue(intAcc.getTotal());
    intAcc.addValue(-1);
    words.addValue("b" + vowels.substr(intAcc.getTotal(), 1) + "t");
    letter.addValue(1);
    cout << "intAcc = " << intAcc << endl;
    cout << "sum = " << sum << endl;
    cout << "words = " << words << endl;
    cout << "letter = " << letter << endl << endl;
  }

  return EXIT_SUCCESS;
}
