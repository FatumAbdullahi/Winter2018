//
//  main.cpp
//  Assignment1Q1
//
//  Created by Fatum Abdullahi on 2018-05-05.
//  Copyright © 2018 Fatum Abdullahi. All rights reserved.
//

using namespace std;
#include <iostream>
#include <string>
#include <fstream>

int main(){
    string text = "";
    ifstream openfile("test.txt");
    int ctr = 0;
    if (openfile.is_open())
    {
        while (!openfile.eof()){
            string tempString;
            openfile >> tempString;
            text+= tempString;
            ctr++;
        }
    }
    else
    {
        cout<<"NOT WORKING";
    }
    cout<<"The number of whitespace seperated words is: ";
    cout<<ctr - 1 <<endl;
    return 0;
}


