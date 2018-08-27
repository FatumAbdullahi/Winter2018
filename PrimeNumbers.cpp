//
//  main.cpp
//  Assignment1Q3
//
//  Created by Fatum Abdullahi on 2018-05-05.
//  Copyright © 2018 Fatum Abdullahi. All rights reserved.
//

#include <iostream>
using namespace std;
int main ()
{
    for (int i=2; i<10000; i++)
    {
        bool prime=true;
        for (int j=2; j<i; j++)
        {
            if (i % j == 0 )
            {
                prime=false;
                break;
            }
        }
        if(prime) cout << i << " ";
    }
    return 0;
}
