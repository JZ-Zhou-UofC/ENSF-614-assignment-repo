// LookupTable.h
// ENSF 614 - Lab 3, Ex C (Templated Version)

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <cassert>
#include <iostream>
using namespace std;


template <typename Key, typename Datum>
struct Pair {
  Pair(Key keyA, Datum datumA) : key(keyA), datum(datumA) {}
  Key key;
  Datum datum;
};

// Forward declaration
template <typename Key, typename Datum>
class LookupTable;

// Node template
template <typename Key, typename Datum>
class LT_Node {
  friend class LookupTable<Key, Datum>;

 private:
  Pair<Key, Datum> pairM;
  LT_Node* nextM;

LT_Node(const Pair<Key, Datum>& pairA, LT_Node* nextA)
    : pairM(pairA), nextM(nextA) {}
};

// LookupTable template
template <typename Key, typename Datum>
class LookupTable {
 public:
  // Nested Iterator
  class Iterator {
    friend class LookupTable<Key, Datum>;
    LookupTable<Key, Datum>* LT;

   public:
    Iterator() : LT(0) {}
    Iterator(LookupTable<Key, Datum>& x) : LT(&x) {}
    const Datum& operator*();
    const Datum& operator++();
    const Datum& operator++(int);
    int operator!();
    void step_fwd() {
      assert(LT->cursor_ok());
      LT->step_fwd();
    }
  };

  LookupTable();
  LookupTable(const LookupTable& source);
  LookupTable& operator=(const LookupTable& rhs);
  ~LookupTable();

  LookupTable& begin();

  int size() const;
  int cursor_ok() const;

  const Key& cursor_key() const;
  const Datum& cursor_datum() const;

  void insert(const Pair<Key, Datum>& pariA);
  void remove(const Key& keyA);
  void find(const Key& keyA);
  void go_to_first();
  void step_fwd();
  void make_empty();

  friend ostream& operator<<(ostream& os, const LookupTable<Key, Datum>& lt) {
    if (lt.cursor_ok())
      os << lt.cursor_key() << "  " << lt.cursor_datum();
    else
      os << "Not Found.";
    return os;
  }

 private:
  int sizeM;
  LT_Node<Key, Datum>* headM;
  LT_Node<Key, Datum>* cursorM;

  void destroy();
  void copy(const LookupTable& source);
};

//  implementation
template <typename Key, typename Datum>
LookupTable<Key, Datum>& LookupTable<Key, Datum>::begin() {
  cursorM = headM;
  return *this;
}

template <typename Key, typename Datum>
LookupTable<Key, Datum>::LookupTable() : sizeM(0), headM(0), cursorM(0) {}

template <typename Key, typename Datum>
LookupTable<Key, Datum>::LookupTable(const LookupTable& source) {
  copy(source);
}

template <typename Key, typename Datum>
LookupTable<Key, Datum>& LookupTable<Key, Datum>::operator=(
    const LookupTable& rhs) {
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <typename Key, typename Datum>
LookupTable<Key, Datum>::~LookupTable() {
  destroy();
}

template <typename Key, typename Datum>
int LookupTable<Key, Datum>::size() const {
  return sizeM;
}

template <typename Key, typename Datum>
int LookupTable<Key, Datum>::cursor_ok() const {
  return cursorM != 0;
}

template <typename Key, typename Datum>
const Key& LookupTable<Key, Datum>::cursor_key() const {
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <typename Key, typename Datum>
const Datum& LookupTable<Key, Datum>::cursor_datum() const {
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::insert(const Pair<Key, Datum>& pairA) {
  if (headM == 0 || pairA.key < headM->pairM.key) {
    headM = new LT_Node<Key, Datum>(pairA, headM);
    sizeM++;
  } else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;
  else {
    LT_Node<Key, Datum>* before = headM;
    LT_Node<Key, Datum>* after = headM->nextM;

    while (after != NULL && (pairA.key > after->pairM.key)) {
      before = after;
      after = after->nextM;
    }
    if (after != NULL && pairA.key == after->pairM.key) {
      after->pairM.datum = pairA.datum;
    } else {
      before->nextM = new LT_Node<Key, Datum>(pairA, before->nextM);
      sizeM++;
    }
  }
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::remove(const Key& keyA) {
  if (headM == 0 || keyA < headM->pairM.key) return;

  LT_Node<Key, Datum>* doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  } else {
    LT_Node<Key, Datum>* before = headM;
    LT_Node<Key, Datum>* maybe_doomed = headM->nextM;
    while (maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }
    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }
  }
  delete doomed_node;
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::find(const Key& keyA) {
  LT_Node<Key, Datum>* ptr = headM;
  while (ptr != NULL && ptr->pairM.key != keyA) {
    ptr = ptr->nextM;
  }
  cursorM = ptr;
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::go_to_first() {
  cursorM = headM;
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::step_fwd() {
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::make_empty() {
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::destroy() {
  LT_Node<Key, Datum>* ptr = headM;
  while (ptr != NULL) {
    headM = headM->nextM;
    delete ptr;
    ptr = headM;
  }
  cursorM = NULL;
  sizeM = 0;
}

template <typename Key, typename Datum>
void LookupTable<Key, Datum>::copy(const LookupTable& source) {
  headM = 0;
  cursorM = 0;
  if (source.headM == 0) return;

  for (LT_Node<Key, Datum>* p = source.headM; p != 0; p = p->nextM) {
    insert(Pair<Key, Datum>(p->pairM.key, p->pairM.datum));
    if (source.cursorM == p) find(p->pairM.key);
  }
}

// ------------ Iterator Implementation ---------------

template <typename Key, typename Datum>
const Datum& LookupTable<Key, Datum>::Iterator::operator*() {
  assert(LT->cursor_ok());
  return LT->cursor_datum();
}

template <typename Key, typename Datum>
const Datum& LookupTable<Key, Datum>::Iterator::operator++() {
  assert(LT->cursor_ok());
  const Datum& x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

template <typename Key, typename Datum>
const Datum& LookupTable<Key, Datum>::Iterator::operator++(int) {
  assert(LT->cursor_ok());
  LT->step_fwd();
  return LT->cursor_datum();
}

template <typename Key, typename Datum>
int LookupTable<Key, Datum>::Iterator::operator!() {
  return (LT->cursor_ok());
}

#endif
