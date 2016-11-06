//
// This program calculates the days passed in a year till a given date
// It also calculates days between two dates given another date
#include <iostream>
#include <iomanip>

using namespace std;
const int monthDays_leapYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};   // Leap Year
const int monthDays_comYear[12] ={31,28,31,30,31,30,31,31,30,31,30,31};    // Common Year

int main()
{
    int year1, monthDays[12];
    bool isLeapYear1 = 0;
    cout << "This program calculates days passed in the year till date.\n";
    cout << "DATE-1: Enter the year: "; cin >> year1;
    // Check if this year is a leap year or not
    if (year1%4 == 0){
        // This could be a leap year
        if (year1%100 != 0 || year1%400 == 0){
            // The year is not a century, it is a leap year
            // The year is a century but divisible by 400, then also it is a leap year
            isLeapYear1 = 1;
        }
    }
    if (isLeapYear1){
        cout << "\tThe year entered is a leap year\n";
        for (int i = 0; i < 12; i++) monthDays[i] = monthDays_leapYear[i];
    }
    else{
        cout << "\tThe year entered is not a leap year\n";
        for (int i = 0; i < 12; i++) monthDays[i] = monthDays_comYear[i];
    }

    int month1, total_days_1=0;
    cout << "DATE-1: Enter the month (1-12): "; cin >> month1;
    // Check whether the month entered is within range
    while (month1 < 1 || month1 > 12){
        // Either the month is less than 1 or greater than 12
        cout << "\tError!! Entered month is incorrect " << endl;
        cout << "DATE-1: Enter month in the range, 1-12: "; cin >> month1;
    }

    cout << "DATE-1: Enter the date (1-"<< monthDays[month1-1] << "): "; cin >> total_days_1;
    // Check whether the date entered is within range
    while (total_days_1 < 1 || total_days_1 > monthDays[month1-1]){
        // Either the date is less than 1 or greater than number of days in that month
        cout << "\tError!! Entered date is incorrect" << endl;
        cout << "DATE-1: Enter date in the range: 1-" << monthDays[month1-1] << ": "; cin >> total_days_1;
    }

    // Calculate the number of days passed
    for (int i = 0; i < month1-1; i++)
        total_days_1 += monthDays[i];
    // Display the number of days passed
    cout << " \tNumber of days passed = " << total_days_1 << "\n";


    int year2;
    bool isLeapYear2 = 0;
    cout << "\nFor the second date:" << endl;
    cout << "DATE-2: Enter the year: "; cin >> year2;
    // Check if this year is a leap year or not
    if (year2%4 == 0){
        // This could be a leap year
        if (year2%100 != 0 || year2%400 == 0){
            // The year is not a century, it is a leap year
            // The year is a century but divisible by 400, then also it is a leap year
            isLeapYear2 = 1;
        }
    }

    if (isLeapYear2){
        // array to hold days in a month for leap year
        cout << "\tThe year entered is a leap year\n";
        for (int i = 0; i < 12; i++) monthDays[i] = monthDays_leapYear[i];
    }
    else{
        // array to hold days in a month for common year
        cout << "\tThe year entered is not a leap year\n";
        for (int i = 0; i < 12; i++) monthDays[i] = monthDays_comYear[i];
    }

    int month2, total_days_2=0;
    cout << "DATE-2: Enter the month (1-12): "; cin >> month2;
    // Check whether the month entered is within range
    while (month2 < 1 || month2 > 12){
        // Either the month is less than 1 or greater than 12
        cout << "\tError!! Entered month is incorrect" << endl;
        cout << "DATE-2: Enter month in the range, 1-12: "; cin >> month2;
    }

    cout << "DATE-2: Enter the date (1-"<< monthDays[month2-1] << "): "; cin >> total_days_2;
    // Check whether the date entered is within range
    while (total_days_2 < 1 || total_days_2 > monthDays[month2-1]){
        // Either the date is less than 1 or greater than number of days in that month
        cout << "\tError!! Entered date is incorrect" << endl;
        cout << "DATE-2: Enter date in the range: 1-" << monthDays[month2-1] << ": "; cin >> total_days_2;
    }
    // Calculate the number of days passed
    for (int i = 0; i < month2-1; i++)
        total_days_2 += monthDays[i];
    // Display the number of days passed
    cout << " \tNumber of days passed = " << total_days_2 << "\n";

    // Now to calculate number of days between the two dates
    cout << "\nNow we calculate the number of days between two dates: " << endl;
    // Find the first year
    int temp;
    if (year1 > year2){
        // Swap the years and days
        temp = total_days_1; total_days_1 = total_days_2; total_days_2 = temp;
        temp = year1; year1 = year2; year2 = temp;
        if (isLeapYear1 != isLeapYear2){
            bool temp;
            temp = isLeapYear1; isLeapYear1 = isLeapYear2; isLeapYear2 = temp;
        }
    }
    // Now we have earlier date in y1 and total days passed in that year in total_days
    // Add the days of each interweening years
    if (year1 == year2){
        // Both dates are in same year
        if (total_days_1 < total_days_2)
            cout << "\tTotal number of days between the dates: " << (total_days_2 - total_days_1) << endl;
        else if (total_days_1 > total_days_2)
            cout << "\tTotal number of days between the dates: " << (total_days_1 - total_days_2) << endl;
        else
            cout << "\tBoth the entered dates are same\n";
    }
    else{
        if (isLeapYear1){ // year1 is a leap year
            total_days_1 = 366 - (total_days_1+1); // Remaining days after the date
            cout << "[" << year1 << "] : " << setw(10) << total_days_1 << " ("<< isLeapYear1 << ")" << endl;
        }
        else{ // year 1 is not a leap year
            total_days_1 = 365 - (total_days_1+1); // Remaining days after the date
            cout << "[" << year1 << "] : " << setw(10) << total_days_1 << " ("<< isLeapYear1 << ")" << endl;
        }
        // Add to this the days in interweening years
        bool isLeapYear;
        for (int i = year1+1; i < year2; i++){
            isLeapYear = 0;
            // Check if this year is a leap year
            if (i%4 == 0){
                // This could be a leap year
                if (i%100 != 0 || i%400 == 0){
                    // The year is not a century, it is a leap year
                    // The year is a century but divisible by 400, then also it is a leap year
                    isLeapYear = 1;
                }
            }
            if (isLeapYear){
                total_days_1 += 366;
                cout << "[" << i << "] : " << setw(10) << total_days_1 << " ("<< isLeapYear << ")" << endl;
            }
            else{
                total_days_1 += 365;
                cout << "[" << i << "] : " << setw(10) << total_days_1 << " ("<< isLeapYear << ")" << endl;
            }
        }
        // Add to this the total_days_2 for the last year
        total_days_1 += total_days_2;
        cout << "[" << year2 << "] : " << setw(10) << total_days_1 << " ("<< isLeapYear2 << ")" << endl;
        cout << "------------------------------------------------------------------------\n";
        cout << "\tTotal number of days between the dates: " << setw(10) << total_days_1 << endl;
    }

    return 0;
}
