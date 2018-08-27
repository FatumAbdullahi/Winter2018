#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <cstdio>
#include <vector>
#include <time.h>
int count=0;

int deckSize = 52;
int facevalue[52] = {2,3,4,5,6,7,8,9,10,10,10,10,11,
    2,3,4,5,6,7,8,9,10,10,10,10,11,
    2,3,4,5,6,7,8,9,10,10,10,10,11,
    2,3,4,5,6,7,8,9,10,10,10,10,11};


void shuffle(int* facevalue){
    int i,j,value = 0;
    deckSize = 52;
    for (i = deckSize - 1; i > 0; i--) { 
        j = rand()/(RAND_MAX/(i+1) + 1);
        value = facevalue[j];
        facevalue[j] = facevalue[i];
        facevalue[i] = value;
        count=0;
    }
}
void checkEmpty(int* facevalue){
    if(deckSize <=0){
        deckSize = 52;
        shuffle(facevalue);
    }}

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


int q5(){
    int player1[2];
    int player2 [2];
    int player3 [2];
    int dealer[10] ={0,0,0,0,0,0,0,0,0,0};
    int limit = 17;
    int curHand=0;
    int bet;
    srand((unsigned int)time(NULL));
    shuffle(facevalue);
    int hand = 10000;
    int decision=0;
    int mycards[10]={0,0,0,0,0,0,0,0,0,0};
    int mytotal=0;
    int x=0;
    int z=0;
    int isWon=0;
    std::cout<<std::endl<<"Question 5: ";
    while(hand>0){
        curHand=hand;
        for (int i=0;i<2; i++){
            checkEmpty(facevalue); 
            player1[i]=deal(facevalue);
            checkEmpty(facevalue);
            player2[i]=deal(facevalue);
            checkEmpty(facevalue);
            player3[i]=deal(facevalue);
            checkEmpty(facevalue);
            mycards[i]=deal(facevalue);
        }
        checkEmpty(facevalue); 
        dealer[0] = deal(facevalue);
       
        if (count<(-2)){bet=-1;}
        else if (count >2) {bet=1;}
        else if (((-2)<count) && (count<2)) {bet=0;}

        for (int i=0; i<2;i++){
            if  ((player1[i]==2)||(player1[i]==3)||(player1[i]==4)||(player1[i]==5)||(player1[i]==6)){
                count++;
            }
            else if (player1[i]==10){ count--;}
            
            if  ((player2[i]==2)||(player2[i]==3)||(player2[i]==4)||(player2[i]==5)||(player2[i]==6)){
                count++;
            }
            else if (player2[i]==10){ count--;}
            
            if  ((player3[i]==2)||(player3[i]==3)||(player3[i]==4)||(player3[i]==5)||(player3[i]==6)){
                count++;
            }
            else if (player3[i]==10){ count--;}
            
            if  ((mycards[i]==2)||(mycards[i]==3)||(mycards[i]==4)||(mycards[i]==5)||(mycards[i]==6)){
                count++;
            }
            else if (mycards[i]==10){ count--;}}
        
        
        int i=0;
        if  ((dealer[i]==2)||(dealer[i]==3)||(dealer[i]==4)||(dealer[i]==5)||(dealer[i]==6)){
            count++;
        }
        else if (dealer[i]==10){ count--;}
        
        for (int i=0; i<2; i++){ 
            mytotal=mytotal+mycards[i];
        }
        
        
        for (int x=2;x<20;x++){ 
            if (mytotal<limit){
                checkEmpty(facevalue); 
                mycards[x]=deal(facevalue);
                if(mycards[x] == 11){  
                    if(mytotal + 11 > 21){
                        mytotal++;}
                    else{
                        mytotal+=11;}}}
            
            else {mytotal=mytotal+mycards[x];}
            
            if(mytotal>21){
                hand--;
                if (bet==-1){decision++;}
                z++; 
                break;
                
            }
             else if(mytotal==21){
             z++;
             if (bet==1){decision++;}
             isWon++;
             break;
             }}
        
        
        int dealerTotal=dealer[0];
        
        if ((curHand == hand) && (z==0)){ 
            for (int j=1; j<20;j++){
                if (dealerTotal<17){
                    checkEmpty(facevalue); 
                    dealer[j]=deal(facevalue);
                    if(dealer[j] == 11){  
                        if(dealerTotal + 11 > 21){
                            dealerTotal++;}
                        else{dealerTotal+=11;}}
                    
                    else {dealerTotal=dealerTotal+mycards[x];}}
                
                if(dealerTotal>21||dealerTotal<mytotal ||mytotal==21){
                    isWon++;
                    hand--;
                    if (bet==1){decision++;}
                    break;
                }
                else if((dealerTotal>mytotal)&& (dealerTotal<=21)){
                    if (bet==-1 || bet==0){decision++;}
                    hand--;
                    break;}
                else if (dealerTotal==mytotal){
                    hand--;
                    break;}
            }}
 
        int dealer[10] ={0,0,0,0,0,0,0,0,0,0};
        mytotal=0;
        int mycards[10]={0,0,0,0,0,0,0,0,0,0};
        dealerTotal=0;
        z=0;
        
    }
    std::cout<<((float(decision)/10000)*100)<<std::endl;
    return 0;
    }

int main(void){
    srand((unsigned int)time(NULL));
    q4();
    q5();
    return 0;
}

