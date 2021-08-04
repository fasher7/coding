#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
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
    string month;
    string day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int date[31];
    bool leapCheck;

    int inputDate(string givenMonth, int dayCheck)
    {
        int date[31];
        for (int i = 0; i < 31; ++i)
        {
            date[i] = i + 1;
        }
        if (givenMonth == "January" || givenMonth == "March" || givenMonth == "May" || givenMonth == "July" || givenMonth == "August" || givenMonth == "October" || givenMonth == "December")
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

int updatedMarkedCalender(string monthDates, int dayCheck, calender **toProduce, list<options> &task)
{
    bool isThere = toProduce[1][0].leapCheck;
    bool monthFind = false;
    int date2[31];
    int anotherREM[31];
    int arrSize;
    int count = 0;
    int countcounter = 0;

    for (int i = 0; i < 31; ++i)
    {
        date2[i] = i + 1;
    }

    if (monthDates == "January" || monthDates == "March" || monthDates == "May" || monthDates == "July" || monthDates == "August" || monthDates == "October" || monthDates == "December")
    {
        for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
        {
            if (it->theMonth == monthDates)
            {
                monthFind = true;
                anotherREM[count] = it->theDate;
                ++count;
            }
        }
        int accuray[count];
        for (int x = 0; x < count; ++x)
        {
            accuray[x] = anotherREM[x];
        }
        arrSize = sizeof(accuray) / sizeof(accuray[0]);
        sort(accuray, accuray + arrSize);
        for (int i = 0; i < 31; ++i)
        {
            if (accuray[countcounter] == date2[i] && monthFind == true)
            {
                ++countcounter;
                if (date2[i] <= 9)
                {
                    cout << "*" << date2[i] << "  ";
                }
                else if (date2[i] > 9)
                {
                    cout << "*" << date2[i] << "  ";
                }
                ++dayCheck;
                if (dayCheck == 7)
                {
                    dayCheck = 0;
                    cout << endl;
                }
            }
            else
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
    }

    else if (monthDates == "April" || monthDates == "June" || monthDates == "September" || monthDates == "November")
    {
        for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
        {
            if (it->theMonth == monthDates)
            {
                monthFind = true;
                anotherREM[count] = it->theDate;
                ++count;
            }
        }
        int accuray[count];
        for (int x = 0; x < count; ++x)
        {
            accuray[x] = anotherREM[x];
        }
        arrSize = sizeof(accuray) / sizeof(accuray[0]);
        sort(accuray, accuray + arrSize);
        for (int i = 0; i < 30; ++i)
        {
            if (accuray[countcounter] == date2[i] && monthFind == true)
            {
                ++countcounter;
                if (date2[i] <= 9)
                {
                    cout << "*" << date2[i] << "  ";
                }
                else if (date2[i] > 9)
                {
                    cout << "*" << date2[i] << "  ";
                }
                ++dayCheck;
                if (dayCheck == 7)
                {
                    dayCheck = 0;
                    cout << endl;
                }
            }
            else
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
    }

    else if (monthDates == "February")
    {
        if (isThere == true)
        {
            for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
            {
                if (it->theMonth == monthDates)
                {
                    monthFind = true;
                    anotherREM[count] = it->theDate;
                    ++count;
                }
            }
            int accuray[count];
            for (int x = 0; x < count; ++x)
            {
                accuray[x] = anotherREM[x];
            }
            arrSize = sizeof(accuray) / sizeof(accuray[0]);
            sort(accuray, accuray + arrSize);
            for (int i = 0; i < 29; ++i)
            {
                if (accuray[countcounter] == date2[i] && monthFind == true)
                {
                    ++countcounter;
                    if (date2[i] <= 9)
                    {
                        cout << "*" << date2[i] << "  ";
                    }
                    else if (date2[i] > 9)
                    {
                        cout << "*" << date2[i] << "  ";
                    }
                    ++dayCheck;
                    if (dayCheck == 7)
                    {
                        dayCheck = 0;
                        cout << endl;
                    }
                }
                else
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
        }
        else
        {
            for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
            {
                if (it->theMonth == monthDates)
                {
                    monthFind = true;
                    anotherREM[count] = it->theDate;
                    ++count;
                }
            }
            int accuray[count];
            for (int x = 0; x < count; ++x)
            {
                accuray[x] = anotherREM[x];
            }
            arrSize = sizeof(accuray) / sizeof(accuray[0]);
            sort(accuray, accuray + arrSize);
            for (int i = 0; i < 28; ++i)
            {
                if (accuray[countcounter] == date2[i] && monthFind == true)
                {
                    ++countcounter;
                    if (date2[i] <= 9)
                    {
                        cout << "*" << date2[i] << "  ";
                    }
                    else if (date2[i] > 9)
                    {
                        cout << "*" << date2[i] << "  ";
                    }
                    ++dayCheck;
                    if (dayCheck == 7)
                    {
                        dayCheck = 0;
                        cout << endl;
                    }
                }
                else
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
        }
    }

    cout << endl;
    return dayCheck;
}

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

void toInputMonth(calender **toProduce)
{
    toProduce[0][0].month = "January";
    toProduce[1][0].month = "February";
    toProduce[2][0].month = "March";
    toProduce[3][0].month = "April";
    toProduce[4][0].month = "May";
    toProduce[5][0].month = "June";
    toProduce[6][0].month = "July";
    toProduce[7][0].month = "August";
    toProduce[8][0].month = "September";
    toProduce[9][0].month = "October";
    toProduce[10][0].month = "November";
    toProduce[11][0].month = "December";
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
        cout << "-----------" << toProduce[x][0].month << "-----------" << endl;
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
        int newMonthDay = toProduce[x][0].inputDate(toProduce[x][0].month, dayCheck);
        firstDay = nextMonth(newMonthDay);
    }
}

void addRem(list<options> &task, options changes)
{
    cout << "Reminder Title: ";
    getline(cin, changes.remTitle);
    cout << "Reminder Description: ";
    getline(cin, changes.remDescrip);
    cout << "Date: ";
    cin >> changes.theDate;
    cout << "Month: ";
    cin >> changes.theMonth;

    task.push_back(changes);
    cout << "***REMINDER ADDED SUCCESSFULLY***" << endl;
}

void updRem(list<options> &task, options changes)
{
    if (task.size() == 0)
    {
        cout << "Please add a reminder first!" << endl;
        return;
    }

    string titleCheck;
    int dateCheck;
    string monthCheck;
    int countUpd = 0;

    cout << "Provide the suitable informations to find the reminder." << endl;
    cout << "Reminder Title: ";
    getline(cin, titleCheck);
    cout << "Date: ";
    cin >> dateCheck;
    cout << "Month: ";
    cin >> monthCheck;
    cout << endl;

    cin.ignore();
    for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
    {
        if (it->remTitle == titleCheck && it->theDate == dateCheck && it->theMonth == monthCheck)
        {
            cout << "Provide informations to update it." << endl;
            cout << "Reminder Title: ";
            getline(cin, changes.remTitle);
            it->remTitle = changes.remTitle;
            cout << "Reminder Description: ";
            getline(cin, changes.remDescrip);
            it->remDescrip = changes.remDescrip;
            cout << "Date: ";
            cin >> changes.theDate;
            it->theDate = changes.theDate;
            cout << "Month: ";
            cin >> changes.theMonth;
            it->theMonth = changes.theMonth;
            ++countUpd;
            cout << "***REMINDER UPDATED***" << endl;
            break;
        }
    }

    if (countUpd == 0)
    {
        cout << "***REMINDER WAS NOT FOUND***" << endl;
    }
}

void delRem(list<options> &task)
{
    if (task.size() == 0)
    {
        cout << "No reminder to be deleted." << endl;
        return;
    }

    string titleDel;
    int dateDel;
    string monthDel;
    int countDel = 0;

    cout << "Provide the suitable informations to delete the reminder." << endl;
    cout << "Reminder Title: ";
    getline(cin, titleDel);
    cout << "Date: ";
    cin >> dateDel;
    cout << "Month: ";
    cin >> monthDel;
    cout << endl;

    cin.ignore();
    for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
    {
        if (it->remTitle == titleDel && it->theDate == dateDel && it->theMonth == monthDel)
        {
            task.erase(it);
            ++countDel;
            cout << "***REMINDER DELETED***" << endl;
            break;
        }
    }

    if (countDel == 0)
    {
        cout << "***REMINDER WAS NOT FOUND***" << endl;
    }
}

void viewRem(list<options> task)
{
    if (task.size() == 0)
    {
        cout << "Please add a reminder first!" << endl;
        return;
    }

    string remMonth;
    cout << "Which month's reminder? ";
    cin >> remMonth;
    int countReminder = 1;
    cout << endl;

    cin.ignore();
    for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
    {
        if (it->theMonth == remMonth)
        {
            cout << "Reminder #" << countReminder << endl;
            cout << "Reminder Title: " << it->remTitle << endl;
            cout << "Reminder Description: " << it->remDescrip << endl;
            cout << "Reminder Date: " << it->theDate << endl;
            cout << "Reminder Month: " << it->theMonth << endl;
            ++countReminder;
        }
    }

    if (countReminder == 1)
    {
        cout << "No reminder found in " << remMonth << "." << endl;
    }
}

void firstWordChecker(list<options> &task)
{
    string checkLower;
    string temp2;
    char changeUpper;

    for (list<options>::iterator it = task.begin(); it != task.end(); ++it)
    {
        checkLower = it->theMonth;
        changeUpper = checkLower[0];

        if (changeUpper >= 'a' && changeUpper <= 'z')
        {
            changeUpper = changeUpper - 32;
            temp2 = temp2 + changeUpper;
            for (int a = 1; a < checkLower.size(); ++a)
            {
                temp2 = temp2 + checkLower[a];
            }
            it->theMonth = temp2;
            temp2 = "";
        }
    }
}

void updatedCalender(calender **toProduce, list<options> &task, string firstDay)
{
    firstWordChecker(task);
    string lastDay;
    int dayCheck;

    for (int x = 0; x < 12; ++x)
    {
        cout << "-----------" << toProduce[x][0].month << "-----------" << endl;
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
        int newMonthDay = updatedMarkedCalender(toProduce[x][0].month, dayCheck, toProduce, task);
        firstDay = nextMonth(newMonthDay);
    }
}

void otherOptions(calender **toProduce, list<options> &task, string firstDay)
{
    options changes;
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
        cin.ignore();
        if (choose == 5)
        {
            updatedCalender(toProduce, task, firstDay);
            break;
        }
        else if (choose == 1)
        {
            addRem(task, changes);
            cout << endl;
        }
        else if (choose == 2)
        {
            updRem(task, changes);
            cout << endl;
        }
        else if (choose == 3)
        {
            delRem(task);
            cout << endl;
        }
        else
        {
            viewRem(task);
            cout << endl;
        }
    }
}

void freeUpMemory(calender **toProduce, options *&changes)
{
    for (int m = 0; m < 12; ++m)
    {
        delete[] toProduce[m];
    }
    delete[] toProduce;
    toProduce = nullptr;
    delete[] changes;
    changes = nullptr;
}

int main()
{
    list<options> task;
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
    toInputMonth(toProduce);
    toCheckLeap(toProduce, year);
    miniDigitalCalender(toProduce, firstDay);
    otherOptions(toProduce, task, firstDay);

    freeUpMemory(toProduce, changes);
    task.clear();

    return 0;
}
