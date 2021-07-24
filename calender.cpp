#include <iostream>
using namespace std;

struct calender
{
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octobar", "November", "December"};
    string day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    string theMonth;
    bool leapCheck;

    int inputDate(string givenMonth, int dayCheck)
    {
        if (givenMonth == "January" || givenMonth == "March" || givenMonth == "May" || givenMonth == "July" || givenMonth == "August" || givenMonth == "Octobar" || givenMonth == "December")
        {
            int date1[31];
            for (int i = 0; i < 31; ++i)
            {
                date1[i] = i + 1;
            }
            for (int i = 0; i < 31; ++i)
            {
                if (date1[i] <= 9)
                {
                    cout << " " << date1[i] << "  ";
                }
                else if (date1[i] > 9)
                {
                    cout << date1[i] << "  ";
                }
                ++dayCheck;
                if (dayCheck == 7)
                {
                    dayCheck = 0;
                    cout << endl;
                }
            }
        }
        else if (givenMonth == "April" || givenMonth == "June" || givenMonth == "September" || givenMonth == "November")
        {

            int date2[30];
            for (int i = 0; i < 30; ++i)
            {
                date2[i] = i + 1;
            }
            for (int i = 0; i < 30; ++i)
            {
                if (date2[i] <= 9)
                {
                    cout << " " << date2[i] << "  ";
                }
                else if (date2[i] > 9)
                {
                    cout << date2[i] << "  ";
                }
                ++dayCheck;
                if (dayCheck == 7)
                {
                    dayCheck = 0;
                    cout << endl;
                }
            }
        }
        else
        {
            if (leapCheck == true)
            {
                int date3[29];
                for (int i = 0; i < 29; ++i)
                {
                    date3[i] = i + 1;
                }
                for (int i = 0; i < 29; ++i)
                {
                    if (date3[i] <= 9)
                    {
                        cout << " " << date3[i] << "  ";
                    }
                    else if (date3[i] > 9)
                    {
                        cout << date3[i] << "  ";
                    }
                    ++dayCheck;
                    if (dayCheck == 7)
                    {
                        dayCheck = 0;
                        cout << endl;
                    }
                }
            }
            else
            {
                int date4[28];
                for (int i = 0; i < 28; ++i)
                {
                    date4[i] = i + 1;
                }
                for (int i = 0; i < 28; ++i)
                {
                    if (date4[i] <= 9)
                    {
                        cout << " " << date4[i] << "  ";
                    }
                    else if (date4[i] > 9)
                    {
                        cout << date4[i] << "  ";
                    }
                    ++dayCheck;
                    if (dayCheck == 7)
                    {
                        dayCheck = 0;
                        cout << endl;
                    }
                }
            }
        }
        cout << endl;
        return dayCheck;
    }
};

string toShort(string firstDay)
{
    string temp = firstDay;
    firstDay = "";
    for (int a = 0; a < 3; ++a)
    {
        firstDay = firstDay + temp[a];
    }
    return firstDay;
}

void toCheckLeap(calender *&toProduce, int year)
{
    if (year % 4 == 0 && year % 100 != 0)
    {
        toProduce[1].leapCheck = true;
    }
    else if (year % 4 == 0 && year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            toProduce[1].leapCheck = true;
        }
        else
        {
            toProduce[1].leapCheck = false;
        }
    }
    else
    {
        toProduce[1].leapCheck = false;
    }
}

string nextMonth(int newMonthDate)
{
    if (newMonthDate == 0)
    {
        return "Sun";
    }
    else if (newMonthDate == 1)
    {
        return "Mon";
    }
    else if (newMonthDate == 2)
    {
        return "Tue";
    }
    else if (newMonthDate == 3)
    {
        return "Wed";
    }
    else if (newMonthDate == 4)
    {
        return "Thu";
    }
    else if (newMonthDate == 5)
    {
        return "Fri";
    }
    else
    {
        return "Sat";
    }
}

void miniDigitalCalender(calender *&toProduce, string firstDay)
{
    string lastDay;
    int dayCheck;

    for (int x = 0; x < 12; ++x)
    {
        cout << "-----------" << toProduce[x].month[x] << "-----------" << endl;
        for (int y = 0; y < 7; ++y)
        {
            cout << toProduce[x].day[y] << " ";
        }
        cout << endl;
        for (int z = 0; z < 7; ++z)
        {
            if (toProduce[x].day[z] == firstDay)
            {
                dayCheck = z;
                break;
            }
            cout << "    ";
        }
        int newMonthDay = toProduce[x].inputDate(toProduce[x].month[x], dayCheck);
        firstDay = nextMonth(newMonthDay);
    }
}

int main()
{
    calender *toProduce = new calender[12];
    int year;
    string firstDay;

    cout << "Year: ";
    cin >> year;
    cout << "Starting day of the year: ";
    cin >> firstDay;
    cout << endl;

    firstDay = toShort(firstDay);
    toCheckLeap(toProduce, year);
    miniDigitalCalender(toProduce, firstDay);

    delete[] toProduce;

    return 0;
}
