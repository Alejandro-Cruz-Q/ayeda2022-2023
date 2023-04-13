#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "SortMethod.h"

template<class key>
class ShellSort : public SortMethod<key>{
  public:
    void Sort(std::vector<key>, unsigned size);
  private:
};


#endif // SHELLSORT_H