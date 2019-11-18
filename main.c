#include <stdio.h>
#include <stdlib.h>

#define MAX_FOODTYPE_NAME 20
#define MAX_DRINK_NAME 20
#define MAX_SPECIFIC_FOOD_NAME 20

void readNameAndPrice(char* food, double *price);

int main() {

    //read no of food types
    int noOfFoodTypes;
    printf("Please input number of food types\n");
    scanf("%d", &noOfFoodTypes);
    fflush(stdin);

    // read food types
    printf("Please food types (each on a new line, may contain spaces)\n");
    char **foodTypes = (char **) malloc(noOfFoodTypes * sizeof(char *));
    for (int i = 0; i < noOfFoodTypes; ++i) {
        //read each food type
        foodTypes[i] = (char *) malloc(MAX_FOODTYPE_NAME * sizeof(char));
        gets(foodTypes[i]);
    }


    int *noOfSpecificFood = (int *) malloc(noOfFoodTypes * sizeof(int));
    double **foodPrices = (double **) malloc(noOfFoodTypes * sizeof(double *));
    char ***specificFood = (char ***) malloc(noOfFoodTypes * sizeof(char **));
    for (int i = 0; i < noOfFoodTypes; ++i) {
        //read no of specific food
        printf("\nPlease input no of speciffic foods for food \"%s\"\n", foodTypes[i]);
        scanf("%d", &noOfSpecificFood[i]);
        fflush(stdin);

        //read specific foods and their prices prices
        specificFood[i] = (char **) malloc(noOfSpecificFood[i] * sizeof(char *));
        foodPrices[i] = (double *) malloc(noOfSpecificFood[i] * sizeof(double));

        printf("Please input \"%s\" speciffic foods &prices: each line in the format <speciffic food> (price):\n",foodTypes[i]);
        for (int j = 0; j < noOfSpecificFood[i]; ++j) {
            specificFood[i][j] = (char*) malloc(MAX_SPECIFIC_FOOD_NAME* sizeof(char));
            readNameAndPrice(specificFood[i][j],&foodPrices[i][j]);
        }
    }

    //read no of drinks
    int noOfDrinks;
    printf("\nPlease input no of drinks\n");
    scanf("%d",&noOfDrinks);
    fflush(stdin);

    //read drinks and their prices
    double * drinkPrice = (double*) malloc( noOfDrinks* sizeof(double));
    char ** drinks = (char**) malloc( noOfDrinks* sizeof(char *));
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    for (int i = 0; i < noOfDrinks; ++i) {
        drinks[i] = (char *)malloc(MAX_DRINK_NAME* sizeof(char));
        readNameAndPrice(drinks[i],&drinkPrice[i]);
    }

    //food data printing
    printf("The food data is:\n");
    for(int i=0;i<noOfFoodTypes;i++) {
        // display food classified by food type
        printf("%s: ", foodTypes[i]);
        for(int j=0;j<noOfSpecificFood[i];j++) {
            printf("(%s - %.2lf) ",specificFood[i][j],foodPrices[i][j]);
        }
        printf("\n");
    }

    //drink data printing
    printf("The drinks data is:\n");
    printf("drinks: ");
    for(int i=0;i<noOfDrinks;i++) {
        // display food classified by food type
        if(i!=(noOfDrinks-1))
            printf("%s, ",drinks[i]);
        else
            printf("%s ",drinks[i]);
    }
    printf("\nprices: ");
    for(int i=0;i<noOfDrinks;i++) {
        // display food classified by food type
        if(i!=(noOfDrinks-1))
            printf("%.0lf, ",drinkPrice[i]);
        else
            printf("%.0lf ",drinkPrice[i]);
    }

    //deallocate food memory
    for (int i = 0; i < noOfFoodTypes; ++i) {
        for (int j = 0; j < noOfSpecificFood[i]; ++j) {
            free(specificFood[i][j]);
        }
        free(specificFood[i]);
        free(foodTypes[i]);
        free(foodPrices[i]);
    }
    free(specificFood);
    free(foodTypes);
    free(foodPrices);
    free(noOfSpecificFood);

    //deallocate drinks memory
    for (int i = 0; i < noOfDrinks; ++i) {
        free(drinks[i]);
    }
    free(drinks);
    free(drinkPrice);

    return 0;
}

void readNameAndPrice(char* food, double *price){
    char c = getchar();
    int i=0;
    while(c!='(') {
        food[i] = c;
        c = getchar();
        i++;
    }
    food[i-1] = '\0';
    scanf("%lf",price);
    fflush(stdin);
}

