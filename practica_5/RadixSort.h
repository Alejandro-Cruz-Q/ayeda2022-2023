#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "SortMethod.h"

template<class key>
class RadixSort : public SortMethod<key>{
  public:
    void Sort(std::vector<key>, unsigned size);
  private:
};


#endif // RADIXSORT_H