#include <iostream>
#include <string>

#ifndef EX1CPP_POINT_H
#define EX1CPP_POINT_H

using namespace std;


/**
 * This class represents a point on a 2 dimensional space
 */
class Point
{

public:
    long int getX() const;
    long int getY() const;
    Point();
    Point(long int x, long int y);
    ~Point();

    string toString();
    void set(long int x, long int y);
    Point*  getNext() const;
    Point*  getPrev() const;

    void setNext(Point* nxtToSet);
    void setPrev(Point* prvToSet);



private:
    long int _x;
    long int _y;
    Point *next;
    Point *prev;

};

// --------------------------------------------------------------------------------------
//                                    Class Factory
// --------------------------------------------------------------------------------------

/**
 * this class is creation class of points
 */

class PointFactory
{
public:
    PointFactory();
    ~PointFactory();
    Point *createPoint(long int x, long int y);
    /**
     * each point, while created will be compared to curr pivot in order
     * to determine by the end of the input which is the pivot
     * @return
     */


private:


};

#endif //EX1CPP_POINT_H
