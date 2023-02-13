#include <stdio.h>

void calculatePoints(int totalPoints){
    for(int i=0; i< totalPoints; i++){
        for (int j=0; j<totalPoints; j++) {
            for (int k = 0; k<totalPoints;k++) {
                for (int l = 0; l<totalPoints; l++) {
                    for (int m = 0; m < totalPoints; m++) {
                        if(i*8+j*7+k*6+l*3+m*2 == totalPoints){
                            printf("%d TD+2pt, %d TD+xp, %d TD, %d FG, %d Safety\n", i,j,k,l,m);
                        }
                    }
                
                }
            
            }
        
        }
    }
}

int main(){
    int userChoice;
    do {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &userChoice);
        scanf("Possible Combinations of scoring plays:\n");
        calculatePoints(userChoice);
    }while (userChoice >1);
}
