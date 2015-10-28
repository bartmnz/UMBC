#include <stdio.h>
#include <stdbool.h>

void printString(int number, bool inText);
void printLine(int number, bool inString);
void printBottles(int number);


int main (int argc, char *argv[]){

	int reps = 99;
	if (argc > 1 && 1 <= atoi(argv[1]) <= 99) reps = atoi(argv[1]);
	while (reps > 0) printLine(reps--, true);

}

void printString(int number, bool inText){
	int msb = number / 10;
	int lsb = number % 10;
	const char * one[] = {"No more","One", "Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
	const char * ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};
	const char * teens[] = {"","Eleven","Twelve","Thirteen","Fourteen","Fiveteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	const char * tens[] = {"","","Twenty","Thirty","Fourty","Fifety","Sixety","Seventy","Eighty","Ninety"};
	if(inText){
		if ( number < 11) printf("%s", one[number]);
		else if ( number < 20) printf("%s", teens[lsb]);
		else if (lsb)printf("%s-%s", tens[msb],ones[lsb]);
		else printf("%s", tens[msb]);
	}
	else printf("%d", number);
}

void printBottles(int number){
	if (number == 1) printf(" bottle ");
	else printf(" bottles ");
}

void printLine(int number, bool inString){
	printString(number, inString);
	printBottles(number);
	printf("of beer on the wall\n");
	printString(number, inString);
	printBottles(number);
	printf("of beer!\n");
	printf("Take one down\n");
	printf("And pass it around\n");
	printString(number -1, inString);
	printBottles(number-1);
	printf("of beer on the wall\n\n");

}
