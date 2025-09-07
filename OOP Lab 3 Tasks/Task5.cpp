#include <iostream>
#include <string>
using namespace std;
class LeapYear
{
private:
    int year;

public:
    LeapYear(int y = 0) : year(y) {}
    void setYear(int y)
    {
        year = y;
    }

    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void printFebruaryDates()
    {
        if (year == 0)
        {
            cout << "Please set a valid year first.\n";
            return;
        }
        cout << "Dates of February " << year << ":\n";
        int daysInFebruary = isLeapYear() ? 29 : 28;
        for (int day = 1; day <= daysInFebruary; ++day)
        {
            cout << day << " ";
        }
        cout << endl;
    }

    void displayLeapYearDetails()
    {
        if (isLeapYear())
        {
            cout << year << " is a leap year.\n";
        }
        else
        {
            cout << year << " is not a leap year.\n";
        }
    }
};

int main()
{
    LeapYear myYear;

    int year;
    cout << "Enter a year: ";
    cin >> year;

    myYear.setYear(year);

    myYear.displayLeapYearDetails();
    myYear.printFebruaryDates();

    return 0;
}
