

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib> //for rand and srand
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
        count=0;
    }}
    
int deal(int facevalue[]){
    int value = facevalue[deckSize - 1];
    deckSize--;
    checkEmpty(facevalue);
    return value;
}





int main(){
    int player1[2];
    int player2 [2];
    int player3 [2];
    int dealer[10] ={0,0,0,0,0,0,0,0,0,0};
    int deckSize = 52;
    int limit = 17;
    int curHand=0;
    int bet;
    srand((unsigned int)time(NULL));
    shuffle(facevalue);
    int hand = 10000;
    int bust =0;
    int count=0;
    int decision=0;
    int mycards[10]={0,0,0,0,0,0,0,0,0,0};
    int mytotal=0;
    int x=0;
    int j=0;
    int z=0;
    int isWon=0;
    
    while(hand>0){
        curHand=hand;
        for (int i=0;i<2; i++){
            checkEmpty(facevalue); // checking when deck is empty
            player1[i]=deal(facevalue);
            player2[i]=deal(facevalue);
            player3[i]=deal(facevalue);
            mycards[i]=deal(facevalue);
        }
        checkEmpty(facevalue); // checking when deck is empty
        dealer[0] = deal(facevalue);
        std::cout<<"COUNT is "<<count<<std::endl;
        if (count<(-2)){bet=-1;}
            else if (count >2) {bet=1;}
            else if ((-2)<count <2) {bet=0;}
        std::cout<<"BET IS "<<bet<<std::endl;
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
                else if (mycards[i]==10){ count--;}}// TODO need to reset Count whenever the deck is done
            
            
            int i=0;
            if  ((dealer[i]==2)||(dealer[i]==3)||(dealer[i]==4)||(dealer[i]==5)||(dealer[i]==6)){
                count++;
            }
            else if (dealer[i]==10){ count--;}
            
            for (int i=0; i<2; i++){ // counting my total cards from the two initially given
                mytotal=mytotal+mycards[i];
            }
            //  std::cout<<"mytotal: "<<mytotal<<std::endl;
            
            
            for (int x=2;x<20;x++){ // FOR MY CARDS***
                if (mytotal<limit){
                    checkEmpty(facevalue); // checking when deck is empty
                    mycards[x]=deal(facevalue);
                    if(mycards[x] == 11){  // considering the ACE value
                        if(mytotal + 11 > 21){
                            mytotal++;}
                        else{
                            mytotal+=11;}}}
                
                else {mytotal=mytotal+mycards[x];}
                
                if(mytotal>21){
                    hand--;
                    if (bet==-1){decision++;}
                    z++; // no need to go to the dealer cause u already lost
                    break;
                    
                }
              /*  else if(mytotal==21){
                    z++;
                    isWon++;
                    break;
                }*/}
            
            
            int dealerTotal=dealer[0];
            
            if ((curHand == hand) && (z==0)){ // FOR DEALER****
                for (int j=1; j<20;j++){
                    if (dealerTotal<17){
                        checkEmpty(facevalue); // checking when deck is empty
                        dealer[j]=deal(facevalue);
                        if(dealer[j] == 11){  // considering the ACE value
                            if(dealerTotal + 11 > 21){
                                dealerTotal++;}
                            else{
                                dealerTotal+=11;}}
                        
                        else {dealerTotal=dealerTotal+mycards[x];}}
                    
                    if(dealerTotal>21||dealerTotal<mytotal ||mytotal==21){
                        isWon++;
                        hand--;
                        if (bet==1){decision++;}
                        break;
                    }
                    else if(dealer>=mycards){
                        hand--;
                        break;}
                }}
        std::cout<<"IsWon "<<isWon<<std::endl;
            int dealer[10] ={0,0,0,0,0,0,0,0,0,0};
            mytotal=0;
            int mycards[10]={0,0,0,0,0,0,0,0,0,0};
            dealerTotal=0;
            z=0;
        isWon=0;
            }
           // std::cout<<(float(decision)/10000)*100<<std::endl;
            return 0;
            }
