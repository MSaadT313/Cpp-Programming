#include <iostream>
#include<math.h>
using namespace std;
class Point{
   int x;
   int y;
   int res;
   public:
   Point(int a,int b){
       x = a;
       y = b;
    }
    int distance(Point , Point);
         
};

int Point :: distance(Point a, Point b){
    int ress = ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
    ress = sqrt(ress);
    return ress;
}
int main()
{
    Point a(4,2);
    Point b(5,2);
    Point c();
    int res = c.distance(a,b);

return 0;
}