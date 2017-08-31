#include "Point.h"
#include "ConvexHull.h"
#include "PointSet.h"


#include <iostream>
#include <string>


using namespace std;

int main()
{
    PointSet ps1;
    ps1.add(7,3);
    ps1.add(32,0);
    ps1.add(81,88);



//    cout<<ps1.getHead()->getNext()->getNext()->toString();
    ps1.convertLListToArr();
    int i;
    for(i = 0;i<3;i++)
    {
        cout<<ps1.arrOfPtr[i]->toString();
    }

//    cout<<ps1.arrOfPtr[2]->toString();



//
//    cout<<ps1.getHead()->toString()<<endl;
//    cout<<ps1.getHead()->getNext()->toString()<<endl;
//    ps1.remove(*ps1.getTail());
//    cout<<ps1.getHead()->getNext()->getNext()->toString()<<endl;
//
//    cout<<ps1.getPivot()->toString()<<endl;




//    ps1.add(7,8);
//
//
//
//
//
//    Point *next1 = ps1.getHead();
//    Point *next2 = next1->getNext();
//    Point *next3 = next2->getNext();
//
//    ps1.remove(*next2);
//
//    Point *next4 = ps1.getHead();
//    Point *next5 = next4->getNext();
//    Point *next6 = next5->getNext();
//
//    cout<<next4->toString()<<endl;
//    cout<<next5->toString()<<endl;


//    cout<<next6->toString()<<endl;

//    cout<<ps1.getTail()->toString()<<endl;









//    Point *p1 = new Point(7,6);
//    cout<<p1->toString()<<endl;
//    PointFactory pf1;
//    Point* point1 = pf1.createPoint(7,6);
//    Point* point2 = pf1.createPoint(12,3);
//    Point* point3 = pf1.createPoint(87,19);

//    point1->setNext(point2);
//    point2->setPrev(point3);

//    cout<<point1->getNext()->toString()<<endl;
//    cout<<point2->getPrev()->toString()<<endl;

//    cout<<pf1.getPivot()->toString()<<endl;
//    cout<<ConvexTools::computeDir(point1,point2,point3)<<endl;

    //swap p1 and p2
//    cout<<point1->toString()<<endl;
//    ConvexTools::swap(*point1,*point2);
//    cout<<point1->toString()<<endl;
//    cout<<ConvexTools::computDis(*point1,*point2)<<endl;



}