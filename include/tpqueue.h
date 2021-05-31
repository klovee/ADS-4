// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
  // Сюда помещается описание структуры "Очередь с приоритетами"
   private:
    T* arr;
    int size;
    int begin, end;
    int count;
 public:
explicit TPQueue(int = 100);
~TPQueue();
void push(const T &);
    T pop();
    T get() const;
    bool isFull() const;
    bool isEmpty() const;
};

// функция добавления элемента в очередь
template<typename T>
void TQueue<T>::push(const T & item)
{
    assert( count < size );
 
    arr[end++] = item;
    count++;


    if (end > size)
        end -= size + 1; // возвращаем end на начало очереди
}

template<typename T>
T TPQueue<T>::pop() {
        assert(count > 0);
        T item = arr[begin++];
        count--;
        if (begin > size)
                begin -= size + 1;
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
