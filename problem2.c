#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int diceRoll[13];
int diceOdds[13] = {0,0,1,2,3,4,5,6,5,4,3,2,1};
void rollDice(int);		
void printHistogram(int, int);
int isNum(char []);

int main (int argc, char *argv[]){
	int size = 100;
	int asterix = 1;
	//printf("%d\n", isNum(argv[1]));	
	if( argc == 3){
		if(isNum(argv[1])&& isNum(argv[2])){
			size = atoi(argv[1]);
			asterix = atoi(argv[2]);
		}
		printf("%s\n",argv[1]);
	}
	int temp;
	rollDice(size);
	for (temp = 2; temp <= 12; temp++){
		double projected = (100*diceOdds[temp])/36;
		double percent = (100*diceRoll[temp]/size);
		double difference = abs(projected - percent);
		printf("%d\t Expected %5.1f, Percentage %5.1f, Difference %5.1f",temp, projected, percent, difference);	
		printHistogram(asterix, temp);
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

int isNum(char *array){
	int count;
	for(count = 0; count< strlen(array); count++){
		if(!isdigit(array[count])) return 0;
	}
	return 1;

}
