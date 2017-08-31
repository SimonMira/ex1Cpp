

#include "Point.h"


#include <iostream>
#include <string>


#define DELIMITER ","
#define REPPERLEFT "("
#define REPPERRIGHT ")"


using namespace std;



/**
 * default ctor
 */
Point::Point()
{
    this->_x = 0;
    this->_y = 0;
    this->next = nullptr;
    this->prev = nullptr;
}

/**
 * @param x - x coordinate
 * @param y - y coordinate
 * ctor with parameters
 */
Point::Point(long int x, long int y)
{
    this->_x = x;
    this->_y = y;
    this->next = nullptr;
    this->prev = nullptr;

}

/**
 * TODO
 */
Point::~Point()
{

}

/**
 *
 * @return x val
 */
long int Point::getX() const
{
    return this->_x;
}

/**
 *
 * @return y val
 */
long int Point::getY() const
{
    return this->_y;
}


/**
 *
 * @return to string representation
 */
string Point::toString()
{
    return REPPERLEFT + to_string(this->_x) + DELIMITER + to_string(this->_y) + REPPERRIGHT;
}

/**
 * set point val
 * @param x
 * @param y
 */
void Point::set(long int x, long int y)
{
    this->_x = x;
    this->_y = y;
}

/**
 *
 * @return
 */
Point* Point::getNext() const
{
    return this->next;
}


/**
 *
 * @return
 */
Point* Point::getPrev() const
{
    return this->prev;
}

/**
 *
 * @param nxtToSet
 */
void Point::setNext(Point *nxtToSet)
{
    this->next = nxtToSet;
}

/**
 *
 * @param nxtToSet
 */
void Point::setPrev(Point *prvToSet)
{
    this->prev = prvToSet;
}


// --------------------------------------------------------------------------------------
//                                    Class Factory
// --------------------------------------------------------------------------------------

/**
 * ctor of factory
 * @return
 */
PointFactory::PointFactory()
{

}

/**
 * dtor of factory
 */
PointFactory::~PointFactory()
{

}

/**
 * create point and compare to pivot
 * @param x
 * @param y
 * @return
 */
Point* PointFactory::createPoint(long int x, long int y)
{
    Point *createdPtr = new Point(x,y);



    return createdPtr;
}


