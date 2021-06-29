// Written by Mayank Kumar

#include <bits/stdc++.h>
using namespace std;

struct event
{
    string name;
    int date, month, year;
};

event addEvent()
{
    struct event temp;
    cout << "\n";

    string name;

    cout << "Enter the name of the hackathon:" << endl;
    cin.ignore();
    getline(cin, name);
    temp.name = name;

    cout << "Enter the date (DD in integers), month (MM in integers) and year (YYYY in integers) of the hackathon" << endl;
    cout << "Date: ";
    cin >> temp.date;
    cout << "Month: ";
    cin >> temp.month;
    cout << "Year: ";
    cin >> temp.year;

    printf("\nCongratulations! You have successfully added your hackathon ;) \n");
    cout << "\n";
    return temp;
}

void display(event events[], int numberOfEvents)
{
    cout << "\n";
    cout << "Sl.No.                        NAME                                    DATE" << endl;
    for (int i = 0; i < numberOfEvents; i++)
    {
        event temp = events[i];
        cout << i + 1 << "                             " << temp.name << "                             " << temp.date << "-" << temp.month << "-" << temp.year << endl;
    }
    cout << "\n";
}

void deleteEvent(event events[], int index, int numberOfEvents)
{
    for (int i = index - 1; i < numberOfEvents - 1; i++)
    {
        events[i].name = events[i + 1].name;
        events[i].date = events[i + 1].date;
        events[i].month = events[i + 1].month;
        events[i].year = events[i + 1].year;
    }
    printf("Hackathon Deleted Successfully!\n");
}

bool compareDates(const event &d1, const event &d2)
{
    if (d1.year < d2.year)
        return true;
    if (d1.year == d2.year && d1.month < d2.month)
        return true;
    if (d1.year == d2.year && d1.month == d2.month &&
        d1.date < d2.date)
        return true;

    return false;
}

void sortDates(event arr[], int n)
{
    sort(arr, arr + n, compareDates);
}

bool compareNames(const event &d1, const event &d2)
{
    return d1.name < d2.name;
}

void sortNames(event arr[], int n)
{
    sort(arr, arr + n, compareNames);
}

void menu()
{
    cout << "\nChoose an option:" << endl
         << "1.Add a Hackathon" << endl
         << "2.Delete a Hackathon" << endl
         << "3.Sort Hackathons alphabetically" << endl
         << "4.Sort Hackathons according to date" << endl
         << "5. View menu again" << endl
         << "0.Display the Hackathons" << endl
         << "-1.Exit" << endl;
}

int main()
{
    event events[1000];

    int command, numberOfEvents = 0;

    cout << "\n********WELCOME TO THE HACKATHON LIST !!!********\n"
         << endl
         << "\nCurrently there are no hackathons to display\n"
         << endl;

    menu();

    while (1)
    {
        printf("\nEnter your choice...\n");
        scanf("%d", &command);

        switch (command)
        {
        case -1:
            printf("Byeee!!!");
            return 0;

        case 0:
            display(events, numberOfEvents);
            break;

        case 1:
            events[numberOfEvents++] = addEvent();
            break;

        case 2:
            if (numberOfEvents)
            {
                printf("Enter the Sl.No. of the hackathon you want to delete: ");
                int index = 0;
                cin >> index;
                deleteEvent(events, index, numberOfEvents);
                numberOfEvents--;
            }
            else
            {
                printf("No hackathon to delete. Please add hackathons first.\n");
            }
            break;

        case 3:
            sortNames(events, numberOfEvents);
            printf("Sorted Successfully!\n");
            break;

        case 4:
            sortDates(events, numberOfEvents);
            printf("Sorted Successfully!\n");
            break;

        case 5:
            menu();
            break;

        default:
            printf("Invalid function. Please choose a valid command.\n");
            break;
        }
    }
}