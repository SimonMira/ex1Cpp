
# include <iostream>
# include "Point.h"
# include "PointSet.h"

using namespace std;




/**
 * computes if right or left turn
 * @param p1
 * @param p2
 * @param p3
 * @return
 */
static int computeDir(Point *p1, Point *p2, Point *p3)
{
    long int res =  (p2->getY() - p1->getY()) * (p3->getX() - p2->getX()) -
                    (p2->getX() - p1->getX()) * (p3->getY() - p2->getY());
    if (res == 0) return 0;  // collinear
    return (res > 0)? 1: 2;
}



/**
 * compute dis
 */
static long int computDis(Point p1, Point p2)
{
    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
           (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}

























// --------------------------------------------------------------------------------------
//                                    Class Convex Tools
// --------------------------------------------------------------------------------------



///**
// * computes if right or left turn
// * @param p1
// * @param p2
// * @param p3
// * @return
// */
// int ConvexTools::computeDir(Point *p1, Point *p2, Point *p3)
//{
//    long int res =  (p2->getY() - p1->getY()) * (p3->getX() - p2->getX()) -
//            (p2->getX() - p1->getX()) * (p3->getY() - p2->getY());
//    if (res == 0) return 0;  // collinear
//    return (res > 0)? 1: 2;
//}
//
///**
// *swap 2 points
// */
//int ConvexTools::swap(Point &p1, Point &p2)
//{
//    Point temp = p1;
//    p1 = p2;
//    p2 = temp;
//}
//
///**
// * compute dis
// */
//long int ConvexTools::computDis(Point p1, Point p2)
//{
//    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
//            (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
//}

