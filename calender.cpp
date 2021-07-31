#include <iostream>
#include <list>
#include <iterator>
using namespace std;

struct options
{
    string remTitle;
    string remDescrip;
    int theDate;
    string theMonth;
};

struct calender
{
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octobar", "November", "December"};
    string day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    bool leapCheck;

    int inputDate(string givenMonth, int dayCheck)
    {
        int date[31];
        for (int i = 0; i < 31; ++i)
        {
            date[i] = i + 1;
        }
        if (givenMonth == "January" || givenMonth == "March" || givenMonth == "May" || givenMonth == "July" || givenMonth == "August" || givenMonth == "Octobar" || givenMonth == "December")
        {

            for (int i = 0; i < 31; ++i)
            {
                if (date[i] <= 9)
                {
                    cout << " " << date[i] << "  ";
                }
                else if (date[i] > 9)
                {
                    cout << date[i] << "  ";
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
            for (int i = 0; i < 30; ++i)
            {
                if (date[i] <= 9)
                {
                    cout << " " << date[i] << "  ";
                }
                else if (date[i] > 9)
                {
                    cout << date[i] << "  ";
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

                for (int i = 0; i < 29; ++i)
                {
                    if (date[i] <= 9)
                    {
                        cout << " " << date[i] << "  ";
                    }
                    else if (date[i] > 9)
                    {
                        cout << date[i] << "  ";
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
                for (int i = 0; i < 28; ++i)
                {
                    if (date[i] <= 9)
                    {
                        cout << " " << date[i] << "  ";
                    }
                    else if (date[i] > 9)
                    {
                        cout << date[i] << "  ";
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

void toCheckLeap(calender **toProduce, int year)
{
    if (year % 4 == 0 && year % 100 != 0)
    {
        toProduce[1][0].leapCheck = true;
    }
    else if (year % 4 == 0 && year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            toProduce[1][0].leapCheck = true;
        }
        else
        {
            toProduce[1][0].leapCheck = false;
        }
    }
    else
    {
        toProduce[1][0].leapCheck = false;
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

void miniDigitalCalender(calender **toProduce, string firstDay)
{
    string lastDay;
    int dayCheck;

    for (int x = 0; x < 12; ++x)
    {
        cout << "-----------" << toProduce[x][0].month[x] << "-----------" << endl;
        for (int y = 0; y < 7; ++y)
        {
            cout << toProduce[x][0].day[y] << " ";
        }
        cout << endl;
        for (int z = 0; z < 7; ++z)
        {
            if (toProduce[x][0].day[z] == firstDay)
            {
                dayCheck = z;
                break;
            }
            cout << "    ";
        }
        int newMonthDay = toProduce[x][0].inputDate(toProduce[x][0].month[x], dayCheck);
        firstDay = nextMonth(newMonthDay);
    }
}

void addRem(list<options> task, options changes)
{
}

void updRem(list<options> task, options changes)
{
    if (task.size() == 0)
    {
        cout << "Please add a reminder first!" << endl;
        return;
    }
}

void delRem(list<options> task, options changes)
{
    if (task.size() == 0)
    {
        cout << "No reminder to be deleted" << endl;
        return;
    }
}

void viewRem()
{
    
}

void updatedCalender()
{

}

void otherOptions(calender **toProduce)
{
    options changes;
    list<options> task;
    int choose;

    cout << "Press 1 - To add reminder" << endl;
    cout << "Press 2 - To update reminder" << endl;
    cout << "Press 3 - To delete any specific reminder" << endl;
    cout << "Press 4 - To view all the reminders of a specific month" << endl;
    cout << "Press 5 - To exit from the calender" << endl;

    cout << endl;
    for (;;)
    {
        cout << "Choose any of the following options: ";
        cin >> choose;
        if (choose == 5)
        {
            updatedCalender();
            break;
        }
        else if (choose == 1)
        {
            addRem(task, changes);
        }
        else if (choose == 2)
        {
            updRem(task, changes);
        }
        else if (choose == 3)
        {
            delRem(task, changes);
        }
        // else
        // {
        //     viewRem();
        // }
    }

    task.clear();
}

void freeUpMemory(calender **toProduce)
{
    for (int m = 0; m < 12; ++m)
    {
        delete[] toProduce[m];
    }
    delete[] toProduce;
    toProduce = nullptr;
}

int main()
{
    options *changes = new options;
    calender **toProduce = new calender *[12];
    int year;
    string firstDay;

    for (int m = 0; m < 12; ++m)
    {
        toProduce[m] = new calender[1];
    }

    cout << "Year: ";
    cin >> year;
    cout << "Starting day of the year: ";
    cin >> firstDay;
    cout << endl;

    firstDay = toShort(firstDay);
    toCheckLeap(toProduce, year);
    miniDigitalCalender(toProduce, firstDay);
    otherOptions(toProduce);

    freeUpMemory(toProduce);

    return 0;
}
