#include <stdio.h>
#include "dimacs_reader.h"


int clauses_count;
int num_vars;
int cur_clause;
int arr[100][24];
int numLiterals[100];

void init(int numvars, int numclauses) {
    cur_clause = 0;
    num_vars = numvars;
    clauses_count = numclauses;
    
}

void add_clause(int numlits, int literals[]) {
    int i = 0;
    for (i = 0; i < numlits; ++i) {
        arr[cur_clause][i] = literals[i];
    }
    numLiterals[cur_clause] = numlits;
    cur_clause++;
    
}
int pow (x){
    int res = (1 << x);
    return res;
#if 0
    int i =0 ;
    int power=1;
    while(i < x){
        power *= 2;
        i++;
    }
    return power;
#endif
}

char *classify() {
    unsigned int one = 1;
    int satisfiable = 0;
    int tautology = 0;
    int literals[24];
    int unsatisfiable = 0;
    unsigned int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    int num_modelSat=0;
    int num_modelUnsat=0;
    
    for (i = 0; i < pow(num_vars); ++i) {
        count=0;
        for (j = 0; j < clauses_count; ++j) {
            for (k = 0; k < numLiterals[j]; ++k) {
                if (arr[j][k]>0){
                    if (i &(one << (arr[j][k]-1))){
                        count++;
                        break;}
                }
                
                else {
                    if (!(i &(one << (-arr[j][k]-1)))){
                        count++;
                        break;}
                }}
            
        }
        if (count==clauses_count){
            num_modelSat++;
        }
        else if(count<=clauses_count){
            num_modelUnsat++;
        }
        else{
            printf("HELP!");
        }
        if (num_modelSat>0 &&  num_modelUnsat>0){
            return "satisfiable";
        }
    }
    if (num_modelSat>0)
        return "tautology";
    
    else if (num_modelUnsat>0)
        return "unsatisfiable";
    
    return "HELP2!";
    
}



int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; ++i) {
        read_dimacs(argv[i], init, add_clause);
        printf("%s: %s\n", argv[i], classify());
    }
    return 0;
}


