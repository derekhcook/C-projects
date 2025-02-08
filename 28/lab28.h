#ifndef LAB28_H
#define LAB28_H

template<typename T>
class Frequency
{
 public:
  Frequency(T val) : value(val), frequency(1)
    {}

  void increment()
    { ++frequency; }

  T getValue() const
    { return value; }

  uint getFrequency() const
    { return frequency; }

  bool operator==(const T rhs) const;
  bool operator< (const Frequency<T> rhs) const;
 private:
  T value;
  uint frequency;
};

#endif
