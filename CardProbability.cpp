#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib> //for rand and srand
#include <cstdio>
#include <vector>
#include <time.h>
using namespace std;


void die1(int N)
{
    int arr[N];
    int num_occ;
    cout << N << " times" << endl;
    for (int i = 0; i < N; i++)
    {
        arr[i]=(1 + rand() / (RAND_MAX /6 +1));
    }
    
    
#define MAX_VALUE 6
    
    int counts[N];
    for(int i = 0; i < N; i++)
        counts[i] = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= MAX_VALUE) {
            counts[arr[i]]++; // increment the counter for the current value
        }
    }
    for (int j = 1; j <= MAX_VALUE; j++) {
        cout << j << " : " << float(counts[j])/float(N) << endl;
    }
}
void q1(){
    cout << "Question 1:" << endl;
    die1(100);
    die1(1000);
    die1(100000);
}
void q2(){
    
    cout << "Question 2:" << endl;
    int c_lowNum;
    int c_highNum;
    int even=0;
    for (int i = 0; i < 10000; i++){
        c_highNum=0;
        c_lowNum=0;
        
        for (int i = 0; i < 100; i++)
        {
            int side=(1 + rand() / (RAND_MAX /6 +1));
            if (side==1 || side==2 || side==3){
                c_lowNum++;
            }
            else if (side==4|| side==5|| side==6){
                c_highNum++;
            }
            else{}
        }
        if (c_lowNum==c_highNum){
            even++;
        }}
    
    cout <<float(even)/float(10000)<< endl;
    
}
void q3(){
    int N=100000;
    int arr[N];
    cout << "Question 3:" << endl;
    for(int i=0; i< 100000; i++){
        arr[i]=((1 + rand() / (RAND_MAX /6 +1))+(1 + rand() / (RAND_MAX /6 +1)));
    }
#define MAX_VALUE 12
    
    int counts[N];
    for(int i = 0; i < N; i++)
        counts[i] = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= MAX_VALUE) {
            counts[arr[i]]++; // increment the counter for the current value
        }
    }
    for (int j = 2; j <= MAX_VALUE; j++) {
        cout << j << " : " << (float(counts[j])/float(N))<< endl;
    }
    
}

/*int deckSize = 52;
int facevalue[52] = {2,3,4,5,6,7,8,9,10,10,10,10,11,
    2,3,4,5,6,7,8,9,10,10,10,10,11,
    2,3,4,5,6,7,8,9,10,10,10,10,11,
    2,3,4,5,6,7,8,9,10,10,10,10,11};

void shuffle(int* facevalue){
    int i,j,value = 0;
    deckSize = 52;
    for (i = deckSize - 1; i > 0; i--) { // for loop to shuffle
        j = rand()/(RAND_MAX/(i+1) + 1);
        value = facevalue[j];
        facevalue[j] = facevalue[i];
        facevalue[i] = value;
    }
}

void checkEmpty(int* facevalue){
    if(deckSize <=0){
        deckSize = 52;
        shuffle(facevalue);
    }
}
int deal(int facevalue[]){
    int value = facevalue[deckSize - 1];
    deckSize--;
    checkEmpty(facevalue);
    return value;
}

void q4(){
    shuffle(facevalue);
    int threshold;
    float bust = 0;
    int counttycardcfacevaluef = 0;
    int totalSumOfCards = 0;
    int hand = 10000;
    int countty=0;
    std::cout<<"Question 4:\n"<<std::endl;
    for(threshold = 10; threshold<=21; threshold++){
        while(hand>0){
            checkEmpty(facevalue);
            totalSumOfCards = deal(facevalue);
            if(countty>21){
                hand--;
                countty = 0;
                bust++;
            }else if(countty>=threshold){
                hand--;
                countty = 0;
            }else{
                if(totalSumOfCards == 11){
                    if(countty + 11 > 21){
                        countty++;
                    }else{
                        countty+=11;
                    }
                }else{
                    countty+=totalSumOfCards;
                }
            }
        }
        hand = 10000;
        std::cout<<threshold<< ":"<<(float)bust/float(10000)<<std::endl;
        bust = 0;
        totalSumOfCards = 0;
        countty = 0;
        shuffle(facevalue);
    }
}
*/


int main(void){
    srand((unsigned int)time(NULL));
    q1();
    q2();
    q3();
    return 0;
}
