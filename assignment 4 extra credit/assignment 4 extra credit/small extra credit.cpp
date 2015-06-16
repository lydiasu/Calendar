//
//  main.cpp
//  assignment 4 extra credit
//
//  Created by Su Yuqing on 3/22/14.
//  Copyright (c) 2014 Su Yuqing. All rights reserved.
//

#include <iostream>

using namespace std;


int num_of_sundays (int year)
{
    
    int day_of_the_week = 0;
    
    int i = 0;
    
    int k = 0;
    
    
  
    for( int month = 1; month <= 12; month++)
    {
        if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            k = 31;
        }
        else if ( month == 4 || month == 6 || month == 9 || month == 11)
        {
            k = 30;
        }
        else
        {
            
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                k = 29;
            }
            else
            {
                k = 28;
            }
            
        }
            
            for (int day = 1; day <= k; day++)
            {
            
        
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
        
                day_of_the_week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 + 1) % 7;
    
                day_of_the_week = (day_of_the_week + 6) % 7;
                
                if (day_of_the_week == 6)
                 
                    i++;
                
                if ( month == 13 || month == 14)
                {
                    month -= 12;
                    year += 1;
                }
                    
            }
    }


    
    return i;
}

int main()
{
    cout << num_of_sundays(2000);
}
