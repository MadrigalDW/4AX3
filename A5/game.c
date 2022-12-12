/* Some Fun   */
/* Martin v. M. very old code ...  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int  score;   /* Globals */
char in[20];

int user(void)
{
 int i=0;
 while(i!=1 && i!=2){
    printf("We are at %-2d, add 1 or 2? ",score);
    fgets(in,10,stdin);
    i=atoi(in);
  };
 return(i);
}

// my code 
float reward(int temp_score, int depth, bool ourMove){
    float temp, max;
    float gamma=pow(.5, depth);
    
    if (ourMove){
        // Computer's move
        max = 10000000;
        for(int i=1; i<3; i++){
            if (temp_score + i < 20){
                if(reward(temp_score + i, depth + 1, false) < max){
                    max = reward(temp_score + i, depth + 1, false);
                }
            }
        }
        return(gamma*max);
    }
    else{
        // Player's move
        max = -10000000;
        for(int i=1; i<3; i++){
            if (temp_score + i < 20){
                if(reward(temp_score + i, depth + 1, true) > max){
                    max = reward(temp_score + i, depth + 1, true);
                }
            }
        } 
        return(gamma*max);
    }
}

// also my code
int computer(void){
    float bestVal = -100000000; 
    int bestMove = 0;
    printf("We are at %d.\n", score);
    for (int i = 1; i<3; i++){
        // uses reward function to see whether 1 or 2 provides a higher reward
        if (score + i < 20){
            float moveVal = reward(score + i, 0, false);
		    printf("Add %d is %f \n", i, moveVal);
            if (moveVal > bestVal){
                bestMove = i;
                bestVal = moveVal;
            }
        }
        else{
            return i;
        }
    }
    return bestMove; 
}


int computer2(void)
{
 if (score% 3==1) return(1);
 if (score %3==0)return(2);
 else return(rand() %2+1);
}



int main(void)
{
  srand(time(NULL)); 
  int i;
  printf(" Who says first 20 \n \n");
  score=0;
  i=0;
  while(i!=1 && i!=2){
    printf("Who goes first: you=1 computer=2 ? ");
    fgets(in,10,stdin);
    i=atoi(in);
  };
  if(i==2)score=computer();
  while(score <=20){
    score=score+user();
    if(score>=20) {printf(" YOU WIN !!\n ");break;};
    score=score+computer();
    if(score>=20) {printf(" I WIN !! \n ");break;};
 };
return(0);
};