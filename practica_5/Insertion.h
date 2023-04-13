#ifndef INSERTION_H
#define INSERTION_H

#include "SortMethod.h"

template<class key>
class Insertion : public SortMethod<key>{
  public:
    void Sort(std::vector<key>, unsigned size);
  private:
};


#endif // INSERTION_H