

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

int q4 () {
    int totalSumOfCards=0;
    int success=0;
    int bust=0;
    int x=10000;
   
    while (x>0){
        srand((unsigned int)time(NULL));
        shuffle(facevalue);
        
        for (int i=0; i<52;i++){
            if (facevalue[i]==11){
                if (totalSumOfCards<11){
                    facevalue[i]=11;
                }
                else{facevalue[i]==1;}}
            totalSumOfCards+=facevalue[i];
            if (facevalue[i]==1){facevalue[i]=11;}
            if (totalSumOfCards>21){
                bust++;
                totalSumOfCards=0;
                x--;
                
            }
            
        }}
    cout<<"Bust"<<bust<<endl;

    return 0;
}



