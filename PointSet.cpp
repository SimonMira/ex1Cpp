
#include "ConvexHull.h"
#include "PointSet.h"
#include "Point.h"

#include <iostream>
#include <string>
#include <array>

const string NEW_LINE = "\n";

using namespace std;

// ---------------------------------------------------------------------------------------
//                                    Constructors
// --------------------------------------------------------------------------------------

/**
 *
 */
PointSet::PointSet()
{
    this->_head = nullptr;
    this->_numOfElem = 0;
    this->_pivot = new Point(3,2);
}

/**
 * copy constructor
 */
PointSet::PointSet(const PointSet& set)
 {
 *this = set;
 }

/**
 * dtor
 */
PointSet::~PointSet()
{

}

// --------------------------------------------------------------------------------------
//                                    Methods
// --------------------------------------------------------------------------------------
/**
 * add a point to end of set
 * @param toAdd
 * @return
 */



bool PointSet::add(long int x, long int y)
{
    {
        PointFactory pointFactory; //creation design pattern
        Point *toAdd = pointFactory.createPoint(x,y);
        Point *curr = this->_head;

        if (curr)
        {
            while (curr != nullptr)
            {
                if (curr->getX() == x)
                {
                    if(curr->getY() == y)
                    {
                        delete(toAdd);
                        return false; // the point is already exist
                    }
                }
                curr = curr->getNext();
            }

            this->_tail->setNext(toAdd);
            toAdd->setPrev(this->_tail);
        }
        else
        {
            this->_head = toAdd;
        }
        this->_tail = toAdd;
        this->_numOfElem++;
        PointSet::updatePivot(toAdd);

        return true;
    }

}

/**
 * updates the curr pivot
 * @param toCheck
 */
void PointSet::updatePivot(Point *toCheck)
{

    if(this->_pivot->getY() > toCheck->getY())//assume no duplicated points, first find min y
    {

        this->_pivot = toCheck;
    }

    if(this->_pivot->getY() == toCheck->getY())
    {
        if(this->_pivot->getX() > toCheck->getX())//if y val is equal, compare x
        {
            this->_pivot = toCheck;
        }

    }
}


/**
 *
 * @param toRemove
 * @return
 */
bool PointSet::remove(Point &toRemove)
{
    Point* curr = this->_head;
    while(curr != nullptr)
    {
        if(curr->getX() == toRemove.getX() &&  curr->getY() == toRemove.getY())
        {
            if(toRemove.getPrev() == nullptr)//case its _head
            {
                this->_head = toRemove.getNext();
            }
            else if(toRemove.getNext() == nullptr)//case its _tail
            {
                toRemove.getPrev()->setNext(nullptr);
            }
            else // its in between
            {
                toRemove.getPrev()->setNext(toRemove.getNext());
                toRemove.getNext()->setPrev(toRemove.getPrev());
            }
            delete(&toRemove);
            this->_numOfElem--;
            return true;
        }

        curr = curr->getNext();
    }
    return false;
}

/**
 *
 * @return
 */
string PointSet::toString()
{
    string stringBack = ""; //not const cuz it changes
    Point *curPoint = this->_head;
    while (curPoint != nullptr)
    {
        stringBack += curPoint->toString();
        stringBack += NEW_LINE;
        curPoint = curPoint->getNext();
    }
    return stringBack;
}



/**
 *converts the linked list to ordinary list in order to sort
 */
void PointSet::convertLListToArr()
{
    size_t currSize = this->size();
    this->arrOfPtr = new Point*[currSize];
    int i = 0;
    Point* curr = this->getHead();

    while (curr != nullptr)
    {
        this->arrOfPtr[i] = curr;
        curr = curr->getNext();
        i++;
    }

}


/**
 *
 * @param vp1
 * @param vp2
 * @return
 */
int PointSet::compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    Point* pivot = this->getPivot();

    // Find orientation
    int order = ConvexHull::computeDir(pivot, p1, p2);
    if (order == 0)
    {
        return (ConvexTools::computDis(*pivot, *p2) >= ConvexTools::computDis(*pivot, *p1)) ? -1 : 1;
    }
    return (order == 2)? -1: 1;
}

/**
 *
 */

//void PointSet::sortArr()
//{
//    this->arrOfPtr[0] = this->getPivot();
//    size_t sizeToSort = this->size() - 1;
//    qsort(&this->arrOfPtr[1], sizeToSort, sizeof(Point), &PointSet::compare);
//}



// ---------------------------------------------------------------------------------------
//                                    Getters & Setters
// --------------------------------------------------------------------------------------


/**
 *
 * @return
 */
Point* PointSet::getPivot()
{
    return this->_pivot;
}


/**
 *
 * @return head point
 */

Point* PointSet::getHead()
{
    return this->_head;
}

/**
 *
 * @return tail point
 */

Point* PointSet::getTail()
{
    return this->_tail;
}

/**
 *
 * @return
 */
size_t PointSet::size()
{
    return _numOfElem;
}


// --------------------------------------------------------------------------------------
//                                    Class Stack
// --------------------------------------------------------------------------------------


/**
 *
 * @param capacity
 */
Stack::Stack(size_t capacity)
{
    if (capacity <= 0)
        throw string("Stack's capacity must be positive");
    this->storage = new Point*[capacity];
    this->capacity = capacity;
    top = -1;
}
/**
 *
 * @param value
 */
void Stack::push(Point* pointToPush)
    {
        if (top == capacity)
            throw string("Stack's underlying storage is overflow");
        top++;
        storage[top] = pointToPush;
    }



/**
 *
 */
void Stack::pop()
    {
        if (top == -1)
            throw string("Stack is empty");
        top--;
    }

/**
 *
 * @return
 */
    bool  Stack::isEmpty()
    {
        return (top == -1);
    }

/**
 *
 */

 Stack::~Stack()
{
        delete[] storage;
}





// ---------------------------------------------------------------------------------------
 //                                    Operators
 // --------------------------------------------------------------------------------------