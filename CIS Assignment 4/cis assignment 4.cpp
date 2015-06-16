//
//  main.cpp
//  CIS Assignment 4
//
//  Created by Su Yuqing on 3/19/14.
//  Copyright (c) 2014 Su Yuqing. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
# include <string>

using namespace std;

int length_of_a_month( int year, int month)
{
    int num_of_days = 0;
    
    if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        
        num_of_days = 31;
    }
    else if ( month == 4 || month == 6 || month == 9 || month == 11)
    {
        num_of_days = 30;
    }

    else
    {
        
        if ((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0)
         {

            num_of_days = 29;
         }
        else
        {
            num_of_days = 28;
        }
    }

    return num_of_days;
    
}

int day_of_the_year (int year, int month, int day)
{
    int day_num = 0;
    
    int day_of_month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    
    if ( (year % 4 == 0 && year % 100 != 0)|| year % 400 == 0)
    {
        
        for ( int i = 0; i < month-1; i++)
        {
            day_num += day_of_month[i];
        }
    
    }
    else
    {
        day_of_month[1] = 28;
        
        for ( int i = 0; i < month-1; i++)
        {
            day_num += day_of_month[i];
        }
        
    }
    
    day_num += day;
    
    return day_num;

}

int day_of_the_century (int year, int month, int day)
{
   int day_of_century = 0;
   
   int days_in_year =0;
   
   
   for ( int i = 2000; i < year; i++)
   {
      if ((i % 4 == 0 && i % 100 != 0)|| i % 400 == 0)
      {
         days_in_year += 366;
      }
      else
      {
         days_in_year += 365;
      }
      
   }
   
   
   day_of_century = days_in_year + day_of_the_year(year, month, day);

   
    return day_of_century;
}


int day_of_forever(int year, int month, int day)
{
   int day_of_forever = 0;
   
   for (int i = 0; i < year; i++)
   {
      if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0  )
      {
         
         day_of_forever += 366;
      }
      else
      {
         
         day_of_forever += 365;
      }
   
   }
   
   day_of_forever += day_of_the_year(year, month, day);
   
   return day_of_forever;
   
}

int day_of_the_week (int year, int month, int day)
{
    int day_of_week = 0;
    
    if (year < 0)
        return 0;
    else
    {
        if (month < 3)
        {
            month += 12;
            year  -= 1;
        }
    }
    
    day_of_week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 + 1) % 7;
    
    
    day_of_week = (day_of_week + 6) % 7;

    
    return day_of_week;
}


int main()
{
    
    int y, m;
    
    int num_of_day_in_a_month = 0;
    
    int weekday = 0;

    
    cout << "Enter the year and month in numbers separated by a space: ";
    
    cin >> y >> m;
   
    cout << endl;
   
   cout << setw(14) << y << "\t" << m << endl;

    num_of_day_in_a_month = length_of_a_month(y, m);
    
    
    cout<<" Mo Tu We Th Fr Sa Su\n";
   
   int const day1 = 1;
   
   int first_day_of_month = 0;
   
   first_day_of_month = day_of_the_week(y, m, day1);
   
   switch (first_day_of_month)
   {
      case 0:
         break;
      case 1:
         cout << setw(3) <<" ";
         break;
      case 2:
         cout << setw(6) <<" ";
         break;
      case 3:
         cout << setw(9) <<" ";
         break;
      case 4:
         cout << setw(12) <<" ";
         break;
      case 5:
         cout << setw(15) <<" ";
         break;
      case 6:
         cout << setw(18) <<" ";
         break;
         
   }
        for (int d = 1; d <=num_of_day_in_a_month; d++)
        {
           weekday = day_of_the_week(y, m, d);
         
           if(weekday == 0 || weekday == 1 || weekday == 2 || weekday == 3|| weekday == 4 || weekday == 5)
              
              cout << setw(3) << d;
           
           else
                 
              cout  << setw(3) << d << endl;
            
        }
   
   
      cout << endl;
    
    
    return 0;
}
