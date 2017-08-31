#include <string>
#include "Point.h"

#ifndef EX1CPP_POINTSET_H
#define EX1CPP_POINTSET_H



using namespace std;

class PointSet {
public:
    PointSet();
    PointSet(const PointSet& set);
    ~PointSet();


    bool add(long int x, long int y);
    bool remove(Point &toRemove);
    string toString();

    Point **arrOfPtr;
    void convertLListToArr();

    size_t size();
    Point* getHead();
    Point* getTail();
    Point* getPivot();
    int compare(const void *vp1, const void *vp2);
    void sortArr();

    void updatePivot(Point* toCheck);

private:
    Point* _head;
    Point* _tail;
    size_t _numOfElem;
    Point* _pivot;

};

/**
 *
 */
class Stack {
public:
    int top;
    size_t capacity;
    Point **storage;

    void push(Point* pointToPush);
    void pop();
    bool isEmpty();

    Stack(size_t capacity);
    ~Stack();
};


#endif //EX1CPP_POINTSET_H
