#ifndef SEQUENCE_H
#define SEQUENCE_H

template<class Key>
class Sequence{
  public:
    bool search(const Key& k) const;
    bool insert(const Key& k);
    bool isFull() const;
};

#endif  // SEQUENCE_H