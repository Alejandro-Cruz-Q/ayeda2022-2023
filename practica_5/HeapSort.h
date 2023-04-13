#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "SortMethod.h"

template<class key>
class HeapSort : public SortMethod<key>{
  public:
    void Sort(std::vector<key>, unsigned size);
  private:
};


#endif // HEAPSORT_H