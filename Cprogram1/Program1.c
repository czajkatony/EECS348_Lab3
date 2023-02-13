#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct month{
    char name[10];
    float sale;
};

void SalesReport(struct month *allMonths){
    printf("\nMonthly Sales report for 2022: \n\n");
    printf("Month       Sales\n\n");
    for(int i = 0; i < 12; i++){
        int length = strlen(allMonths[i].name);
        int numSpaces = 12 - length;
        printf("%s", allMonths[i].name);
        for(int i = 0; i< numSpaces; i++){
            printf(" ");
        }
        printf("$%.2f\n", allMonths[i].sale );
    }
}

void SalesSummary(struct month *allMonths){
    struct month *min = &allMonths[0];
    struct month *max = &allMonths[0];
    float total = 0;
    for(int i = 0; i< 12; i++){
        if(allMonths[i].sale > max->sale){
            max = &allMonths[i];
        }
        else if(allMonths[i].sale < min->sale){
            min = &allMonths[i];
        }
        total += allMonths[i].sale;
    }
    float average = total / 12;
    printf("\nSales Summary: \n\n");
    printf("Minimum sales:   $%.2f  (%s)\n", min->sale, min->name);
    printf("Maximum sales:   $%.2f  (%s)\n", max->sale, max->name); 
    printf("Average sales:   $%.2f\n", average); 
}

void SixMonthAverage(struct month *allMonths){
    printf("\nSix-Month Moving Average Report:\n\n");
    for(int i = 0; i<7; i++){
        float total = 0;
        for(int j = i; j< i+6; j++){
            total += allMonths[j].sale;
        }
        float sixAverage = total / 6;
        int length = strlen(allMonths[i].name);
        int numSpaces = 12 - length;
        printf("%s", allMonths[i].name);
        for(int b = 0; b< numSpaces; b++){
            printf(" ");
        }
        printf("-  ");
        length = strlen(allMonths[i+5].name);
        numSpaces = 12 - length;
        printf("%s", allMonths[i+5].name);
        for(int b = 0; b< numSpaces; b++){
            printf(" ");
        }
        printf("$%.2f\n", sixAverage);
    }
}

void selectionSort(struct month *allMonths, int n){
    for(int i = 0; i< 11; i++){
        for(int j = i+1; j<12; j++){
            if(allMonths[i].sale < allMonths[j].sale){
                struct month temp = allMonths[j];
                allMonths[j] = allMonths[i];
                allMonths[i] = temp;
            }
        }
    }
}

void SortSales(struct month *allMonths){
   selectionSort(allMonths, 12);
   printf("\nSales Report (Highest to Lowest):\n");
   printf("Month       Sales\n\n");
    for(int i = 0; i < 12; i++){
        int length = strlen(allMonths[i].name);
        int numSpaces = 12 - length;
        printf("%s", allMonths[i].name);
        for(int i = 0; i< numSpaces; i++){
            printf(" ");
        }
        printf("$%.2f\n", allMonths[i].sale );
    }
}

int main(){
    char fileName[100];
    printf("Please enter the name of the input file: ");
    if(scanf("%s", fileName) != 1){
        printf("Error reading file name.\n");
    }
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
        printf("File Empty or error with file name, please run again.");
        return (1);
    }
    struct month allMonths[12];
    char *monthNames[12] = {"January", "February", "March", "April", "May",
                            "June", "July", "August", "September", "October",
                            "November", "December"};
    for(int i = 0; i<12; i++){
        fscanf(file,"%f", &allMonths[i].sale);
        strcpy(allMonths[i].name, monthNames[i]);
    }
    fclose(file);

    // salesNumbers is the array with the data.
    SalesReport(allMonths);
    SalesSummary(allMonths);
    SixMonthAverage(allMonths);
    SortSales(allMonths);
}
