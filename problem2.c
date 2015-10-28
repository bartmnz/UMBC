#include <stdio.h>
#include <stdlib.h>

int diceRoll[13];
int diceOdds[13] = {0,0,1,2,3,4,5,6,5,4,3,2,1};
void rollDice(int);		
void printHistogram(int, int);

int main (int argc, char *argv[]){
	
	int size = atoi(argv[1]);
	printf("%s\n",argv[1]);
	int temp;
	rollDice(size);
	for (temp = 2; temp <= 12; temp++){
		int projected = (diceOdds[temp]* size)/36;
		int difference = abs(diceRoll[temp]-projected);
		int percent = 100*diceRoll[temp]/size;
		printf("%d Expected %d\t, Percentage %d\t, Difference %d\t",temp, projected, percent, difference);	
		printHistogram(atoi(argv[2]), temp);
	}
}

void rollDice(int numTimes){
	while(numTimes){
		int dice1 = rand()%6 + 1;
		int dice2 = rand()%6 + 1;
		diceRoll[dice1 + dice2]++;
		numTimes--;
	}
}
	
void printHistogram(int arg2, int num){
		int numStars = diceRoll[num]/arg2;
		int remainder = diceRoll[num] % arg2;
		while (numStars){
			printf("*");
			numStars--;
		}
		printf("%d\n", remainder);
}
