

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
int i;
string arr[100];
ifstream file("test.txt");

while((i < 100) && getline(file, arr[i]))
{
  if (file.eof())//if it is the end of the file
   {
    file.clear();
    file.seekg(0, ios::beg);
    }
}

for(int j = 0; j<i; j++)
{
cout <<"line " << j+1 << ": "<< arr[j] << endl;
}
cin.get();
}