/*
 ============================================================================
 Name        : drinkmachine.h
 Author      : Anthony Swink
 Version     : 1
 Copyright   : ples no take
 Description : File containing main for soda machine program, Takes user
         input and uses content from drinkmachine.h and drinkmachine.c to
         run the machine.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"drinkmachine.h"

int main(void) {
	//Variables
	int drinkChoice = INVALID_INDEX;
	double change = 0;
	double pay = 0;

	//memory allocation
	DrinkMachine *drinkMachine;
    drinkMachine = create();
    DrinkItem *pDrink;				//For firstDrink and nextDrink functions

   //Greeting guest
    printf("Welcome! Today we have %d items for you to choose from:\n", items(drinkMachine));

    //Printing the drink options using firstDrink and nextDrink to showing they work correctly
    printf("Id\tName\t\tPrice\tQty\tSold\n");
    for(pDrink = firstDrink(drinkMachine); pDrink != NULL; pDrink = nextDrink(drinkMachine)){
    	printf("%d\t%-10s\t%.2lf\t%d\n", pDrink->id , pDrink->name, pDrink->price, pDrink->drinkLeft);
    }

    while(drinkChoice != 0){

    	int sep = 0;				//Used to separate first and second input in case the first produces an error

    	puts("Enter a drink id for the drink you would like to purchase or 0 to quit.");
    	fflush(stdout);
        scanf("%d", &drinkChoice);	//Drink input
        if(drinkChoice == 0){
        	break;
        }
		switch(purchase(drinkMachine, drinkChoice, 0, &change)){			//Check for error
		case INVALID:
			puts("Invalid entry, give it another shot, we believe in you.");	//Out of range input
			break;
		case NOT_AVAILABLE:
			puts("We're out of that drink, PLEASE choose another.");		//Drink item sold out
			break;
		default:
			sep = 1;
		}
		if(sep == 1){												//In case no error from first input
			puts("Enter the amount for purchase(up to $2.00)");
			fflush(stdout);

			scanf("%lf", &pay);			//Cash input
			switch(purchase(drinkMachine, drinkChoice, pay, &change)){
			case INSUFFICIENT_FUNDS:
				puts("That's not enough money, nice try Slick. Try again.");	//User put in too little money
				break;
			case OVERLYSUFFICIENT_FUNDS:
				puts("We got a big shot over here putting in more than 2 dollars huh? Try again.");	//User put in too much money
				break;
			case PURCHASED:
				printf("Purchase success! Your change is: $%.2lf\n\n", change);		//User put in right amount of money
				break;
			default:
				break;
			}
		}
		dumpDrinkMachine(drinkMachine);	//Display screen
    }
    printf("Have a wonderful day!\n");
    fflush(stdout);
	destroy(drinkMachine);

	return EXIT_SUCCESS;
}

