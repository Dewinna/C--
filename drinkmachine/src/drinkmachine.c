/*
 ============================================================================
 Name        : drinkmachine.h
 Author      : Anthony Swink
 Version     : 1
 Copyright   : ples no take
 Description : Main file for soda machine program, contains functions to be
 used in DrinkMachineDriver.c
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"drinkmachine.h"


DrinkMachine *create(void){								//Allocates memory for drinkMachine and drinkItem structures


	FILE *inFile;
	DrinkMachine *drinkMachine;

	drinkMachine = calloc(1, sizeof(DrinkMachine));		// Memory allocation
	if(drinkMachine == NULL){							// Check success
		return NULL;
	}

	drinkMachine->version = 1;							//Drink version
	drinkMachine->drinkLocation = INVALID_INDEX;		//Initial setting of drinkLocation

														// Open the input file for reading
	inFile = fopen("drink_machine.txt" , "r");
	if(!inFile){
		perror("Error opening file");
		free (drinkMachine);
		return NULL;
	}
														// Read drink count from file
	fscanf(inFile, "%d", &(drinkMachine->numItems));

														// Dynamically create memory for array of drink item structures
	drinkMachine->drinkItem = calloc(drinkMachine->numItems, sizeof(DrinkItem));
	if(drinkMachine->drinkItem == NULL){
		perror("Error allocating memory");
		return NULL;
	}

																	// Put information from file into drinkItem structs
	for(int i=0; i < drinkMachine->numItems; ++i){
		char temp[100];
		int tempsize = 1;
		fscanf(inFile, "%s %lf %d", temp, &(drinkMachine->drinkItem[i].price), &(drinkMachine->drinkItem[i].drinkLeft));
		for(int n = 0; temp[n] != '\0'; n++){
			tempsize++;
		}
		(drinkMachine->drinkItem[i].name) = calloc(1, tempsize);	//Create memory for the names
		strncpy(drinkMachine->drinkItem[i].name,temp,tempsize);		//Copy in names from temporary holder
		drinkMachine->drinkItem[i].id = i+1;
		//printf("DEBUG drink %d is: %s  \t%.2lf\t%d\n", drinkMachine->drinkItem[i].id , drinkMachine->drinkItem[i].name, drinkMachine->drinkItem[i].price, drinkMachine->drinkItem[i].drinkLeft);
	}

	// Close inFile
	fclose(inFile);

																	// Force output to screen
	//puts("DEBUG readFile Success!");
	fflush(stdout);

	return drinkMachine;
}


void destroy(DrinkMachine *drinkMachine){
	if (drinkMachine == NULL)										// Safety check
		return;

																	// Free the Integer Array
	//puts("DEBUG: Freeing Integer Array");
	if (drinkMachine->drinkItem != NULL){
		free(drinkMachine->drinkItem);
		for(int i=0; i < drinkMachine->numItems; ++i){
			free(drinkMachine->drinkItem[i].name);
		}
	}

																	// Free the actual struct
	free (drinkMachine);

	return;
}


DrinkItem *firstDrink(DrinkMachine *drinkMachine){					//First drink function, returns address of first drink location
	if(drinkMachine->drinkItem[0].name == 0){
		perror("Error: No array entries\n");
		drinkMachine->drinkLocation = INVALID_INDEX;
		return NULL;
	}
	drinkMachine->drinkLocation = 0;
	return &(drinkMachine->drinkItem[0]);
}
DrinkItem *nextDrink(DrinkMachine *drinkMachine){					//Next drink function, increments drinkLocation up by 1 and returns the address of the next drink
	if(drinkMachine->drinkLocation == INVALID_INDEX){
		perror("Error: DrinkLocation at INVALID_INDEX when sent to nextDrink\n");
		return NULL;
	}
	if(drinkMachine->drinkLocation >= drinkMachine->numItems - 1){
		drinkMachine->drinkLocation = INVALID_INDEX;
		return NULL;
	}else{
		drinkMachine->drinkLocation++;
	}
	return &(drinkMachine->drinkItem[drinkMachine->drinkLocation]);
}


int items(DrinkMachine *drinkMachine){								//returns number of drink items
	return drinkMachine->numItems;
}
int available(DrinkMachine *drinkMachine, int id){					//Checks if the drink is available
	if(drinkMachine->drinkItem[id-1].drinkLeft > 0){
		return 1;
	}
	return 0;
}
double cost(DrinkMachine *drinkMachine, int id){					//returns cost of drink item associated with the drink associated with the id passed to it
	return drinkMachine->drinkItem[id - 1].price;
}
Purchase purchase(DrinkMachine *drinkMachine, int id, double pay, double *change){		//Checks for various errors and increments drinks left/sold
	if(id > items(drinkMachine) || id < 0){				//Check if first input is within range
		return INVALID;
	}else if(available(drinkMachine, id) == 0){			//Check if drink is available
		return NOT_AVAILABLE;
	}else if(cost(drinkMachine, id) > pay){				//Check if user inputed enough money
		return INSUFFICIENT_FUNDS;
	}else if(pay>2){									//Check if user inputed too much money
		return OVERLYSUFFICIENT_FUNDS;
	}else{
		*change = pay - drinkMachine->drinkItem[id-1].price;
		drinkMachine->drinkItem[id-1].drinkLeft--;			//One drink less left
		drinkMachine->drinkItem[id-1].drinkSold++;			//One more drink sold
		return PURCHASED;
	}
}
void dumpDrinkMachine(DrinkMachine *drinkMachine){		//Output display
	printf("Id\tName\t\tPrice\tQty\tSold\n");
	for(int i=0; i < drinkMachine->numItems; ++i){
		printf("%d\t%-10s\t%.2lf\t%d\t%d\n", drinkMachine->drinkItem[i].id , drinkMachine->drinkItem[i].name, drinkMachine->drinkItem[i].price, drinkMachine->drinkItem[i].drinkLeft,drinkMachine->drinkItem[i].drinkSold);
	}
}
