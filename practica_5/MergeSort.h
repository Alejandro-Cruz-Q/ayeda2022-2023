#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortMethod.h"

template<class key>
class MergeSort : public SortMethod<key>{
  public:
    void Sort(std::vector<key>, unsigned size);
  private:
};


#endif // MERGESORT_H