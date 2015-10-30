#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//int diceRoll[13];
int * rollDice(int);		
void printHistogram(int, int, int *);
int isNum(char []);
/*Function simulates the rolls of two dice, and prints the results as a percentage, and a histogram. 
 * Parameters if given: are the number of rolls (first command line argument
 * and the scale of the hitsogram (second connand line argument)
 *
 */
int main (int argc, char *argv[]){
	srand(time(NULL));	
	int size = 100;
	int scale= 1;	
	if( argc == 3 && isNum(argv[1]) && isNum(argv[2]) ){
		size = atoi(argv[1]);
		scale = atoi(argv[2]);
	}
	else if ( argc == 2 && isNum(argv[1]) ){
		size = atoi(argv[1]);
	}
	const int diceOdds[13] = {0,0,1,2,3,4,5,6,5,4,3,2,1};
	int *diceRoll = rollDice(size);
	for (int temp = 2; temp <= 12; temp++){
		double projected = (100 * diceOdds[temp])/36;
		double percent = (100 * (diceRoll[temp])/size);
		double difference = abs(projected - percent);
		printf("%-3d Expected %5.1f, Percentage %5.1f, Difference %5.1f ",temp, projected, percent, difference);	
		printHistogram(scale, temp, diceRoll);
	}
	free(diceRoll);
	exit(0);
}
/*Function simulates the rolls of two dice numTimes and stores the results in diceRoll[]
 *
 */

int * rollDice(int numTimes){
	int *theRolls = malloc(12*sizeof(int));
	while(numTimes){
		int dice1 = rand()%6 + 1;
		int dice2 = rand()%6 + 1;
		theRolls[dice1 + dice2]++;
		numTimes--;
	}
	return theRolls;
}
/*
 * Function prints a histogram of the data stored in diceRoll[] at position num and using scale num
 */
	
void printHistogram(int arg2, int num, int * diceRollp){
	int numStars = diceRollp[num]/arg2;
	int remainder = diceRollp[num] % arg2;
	while (numStars){
		printf("*");
		numStars--;
	}
	printf("%d\n", remainder);
}

/*Function takes a string as an argument and returns 1 if the string is an integer or 0 if it is not.
 */

int isNum(char *array){
	unsigned int count;
	for(count = 0; count< strlen(array); count++){
		if(!isdigit(array[count])) return 0;
	}
	return 1;

}
