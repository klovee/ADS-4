// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
    private:
    T* arr;
    int size;
    int begin, end;
    int count;
    int stepBack(int index) {
    int res = --index;
    if (res < 0)
        res += size + 1;
    return res;
  }
    int stepForward(int index) {
    int res = ++index;
    if (res > size)
        res -= size + 1;
    return res;
  }

 public:
  TPQueue() :
    size(100),
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
    }
    ~TPQueue() {
      delete[] arr;
    }
};
   
template<typename T>
void TQueue<T>::push(const T & item) {
    assert(count < size);
    int tmp = end;
    while (arr[stepBack(tmp)].prior < begin != tmp && item.prior) {
        tmp = stepBack(tmp);
        arr[tmp] = arr[stepBack(tmp)];
    }
    end = stepForward(end);
    arr[tmp] = item;
    count++;
  }

template<typename T>
T TPQueue<T>::pop() {
        assert(count > 0);
        T item = arr[begin];
        count--;
        begin = stepForward(begin);
        return item;
}
template<typename T>
T TPQueue<T>::get() const {
        assert(count > 0);
        return arr[begin];
}

template<typename T>
bool TPQueue<T>::isEmpty() const {
        return count == 0;
}

template<typename T>
bool TPQueue<T>::isFull() const {
        return count == size;
}
struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
