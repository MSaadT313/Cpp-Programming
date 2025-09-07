#include <iostream>
using namespace std;
//
// void counter() {
//     static int count = 0; // Static variable what if then 
//     count++;
//     cout << "Count: " << count << endl;
// }

// int main() {
//     counter();
//     counter();
//     counter();
//     return 0;
// }
// Example two

class Test {
   static int count; // Static member variable     100
public:
   Test() {
      count = 10;
       cout << "Object Count: " << count << endl;
   }
};

int Test::count = 100; // Initialization outside class intial set to zero

int main() {
   Test obj1, obj2, obj3;
   return 0;
}



//A non - static (instance)function can access both static and non - static members of a class.
//A static function can only access static members and cannot access non - static members
//class Demo {
//private:
//    static int data;
//    
//public:
//    //static void show() { // Static function
//    //    cout << "Static Data: " <<data << endl;
//    //}
//    // possible case//
//     static void show() { // Non Static function can handle the static data
//         int data = 20;
//        cout << "Static Data: " << data << endl;
//    }
//    // 
//     void show1() { // Static function can't handle the non static data
//        cout << "Static Data: " << data << endl;
//    }
//};
//
//int Demo::data = 100; // Initializing static variable
//
//int main() {
//    Demo d;
//    d.show();
//    d.show1();
//
//    // Demo::show(); // Calling static function without object
//    return 0;
//}


// static function and non static function with argument 


//class Test {
//    static int staticVar;  // Static variable
//    int nonStaticVar;      // Non-static variable
//
//public:
//     void modifyStatic(int val) {  // Static function
//        staticVar = val;  // Allowed: Modifying static member
//    }
//
//    static void displayStatic() {
//        cout << "Static Variable: " << staticVar << endl;
//    }
//};
//
//// Define static member outside the class
//int Test::staticVar = 0;
//
//int main() {
//    Test t;
//    t.modifyStatic(10);  // Calling static function
//    Test::displayStatic();   // Output: Static Variable: 10
//
//    return 0;
//}


//class Test {
//    int nonStaticVar;  // Non-static member
//
//public:
//    static void modifyNonStatic(int val) {
//        nonStaticVar = val;  //ERROR: Cannot access non-static member
//    }
//};


// Passing an Object to a Static Function




//class Test {
//    int nonStaticVar;
//
//public:
//    Test(int val) { nonStaticVar = val; }
//
//     static void showNonStatic(Test obj) {
//        cout << "Non-Static Variable: " << obj.nonStaticVar << endl;
//    }
//};
//
//int main() {
//    Test obj1(42);
//    obj1.showNonStatic(obj1);  // Pass object to static function
//
//    return 0;
//}




//class Test {
//    int nonStaticVar;
//
//public:
//    Test(int val) { nonStaticVar = val; }
//
//    static void showNonStatic(Test &obj) {  // Passed by value (creates a copy)
//        obj.nonStaticVar = 100;  //  Modifies only the copy
//        cout << "Inside static function: " << obj.nonStaticVar << endl;
//    }
//
//    void show() { cout << "Outside static function: " << nonStaticVar << endl; }
//};
//
//int main() {
//    Test obj1(42);
//    Test::showNonStatic(obj1);  // Passing by value
//
//    obj1.show();  // Original object is unchanged
//
//    return 0;
//}


 
//class Test {
//public:
//    Test() { std::cout << "Constructor is executed\n"; }
//    ~Test() { std::cout << "Destructor is executed\n"; }
//};
//
//void myfunc()
//{
//    // local static object declaration 
//    static Test obj;
//}
//
//int main()
//{
//    std::cout << "main() starts\n";
//    myfunc(); // calling function with static object 
//    std::cout << "main() terminates\n";
//    return 0;
//}