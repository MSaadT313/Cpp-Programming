#include <iostream>
#include <exception>
using namespace std;

int main()
{
    int a;
    cin >> a;
    try
    {
        if (a == 0)
            throw "Wrong integer inputted;";
        if(a<0)
        throw invalid_argument("Cannot input negative value");
        throw runtime_error("Something went wrong");

        int *arr = new int[1000000000000];
    }
    catch (const char *str)
    {
        cout << "Exception caught" << str << endl;
    }
    catch (const exception &e)
    {
        cout << "Caught! " << e.what() << endl;
    }
    catch (bad_alloc &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (out_of_range &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (bad_cast &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}
