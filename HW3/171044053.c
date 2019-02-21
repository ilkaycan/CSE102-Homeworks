#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void menu();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();
int main()
{
	srand(time(NULL));
	menu();
return 0;
}

void menu()
{
	int flag=1;
	while(flag) /* Show menu in every condition except selection is 0 */
	{
		printf("\n1.Horse Racing Game\n");
		printf("2.Occurence Counter\n");
		printf("3.Triangle of Sequences\n");
		printf("0.Exit\n");
		int selection;
		printf("Your Selection:\n");
		scanf("%d", &selection); 
		switch(selection) /* call functions in order to implement selections */
		{
			case 1:
				horseRacingGame();
			break;
			case 2:
				countOccurrence();
			break;
			case 3:
				triangleOfSequences();
			break;
			case 0:
				flag=0; /* exit if selection is 0*/
			break;
			default:
				printf("False selection!!!\n"); /* Warning for false selection*/
			break;
		}
	}	
	
}

int getInt(int mini, int maxi) /* gets an integer input value from user; if it is not in range asks again */
{
	int num;
	do
	{
		scanf("%d", &num);
		if(num>maxi || num<mini)
		{
			printf("Not in Range!!\n");
		}
	} while(num>maxi || num<mini);
return num;
}

int numberGeneratorBetweenRange(int min, int max) /* generates a number between min and max values */
{
	int num;
	num = rand()%(max-min+1) + min;
return num;
}

void horseRacingGame() /* implements a virtual horse race */
{
	int horse, tim, user, winner=21, index=0, inw,winu;
	horse = numberGeneratorBetweenRange(3,5);
	printf("Number of Horses:%d\n", horse);
	printf("Horse number:");
	user = getInt(1, horse);
	printf("\nRacing starts....\n");
		for(int i=1; i<=horse; i++)
		{
			tim = numberGeneratorBetweenRange(10,20);
			printf("Horse %d: %d\n", i, tim);
			index++;
				if(tim<winner)
				{
					winner = tim;
					inw = index; /* winner horse's number */
				} else if(tim == winner)
				{
					if(inw==user && index!=user) /* if there is a draw situation and user is one of them, wins */
					{
						inw=user;
					} else if(inw!= user && index == user)
					{
						inw=user;
					}
				}
		}
		if(inw==user)
		{
			printf("You win!Winner horse is %d\n", user);
		} else {
			printf("You lose!Winner horse is %d\n", inw);
		}
}

void countOccurrence() /*computes number of occurrences of searchNumber in bigNumber */
{
	int num1, num2,temp, temp2,count=0, digit=0, divider, control, flag=1;
	while(flag)
	{
			printf("Please enter 2 positive numbers\n");
			scanf("%d", &num1);
			scanf("%d", &num2);
		if(num1<0 || num2<0)
		{
			printf("You have entered false number\n");
		} else {
			if(num1<num2)
			{
				temp = num2;	
				num2 = num1;
				num1 = temp;
			} 
			temp = num2;
			temp2 = num1;
			while(temp!=0) /*find digit number*/
			{
				temp = temp/10;
				digit++;
			}
			divider = pow(10, digit);
			while(temp2!=0)
			{
				control = temp2%divider;
				temp2 = temp2/10;
				if(control==num2)
				{
					count++; /* if finds an occurence, increases count*/
				}
			}
			printf("Big Number: %d\n", num1 );
			printf("Search Number: %d \n", num2);
			printf("Occurence:%d\n", count);
			flag = 0;
		}	
	}			
}

void triangleOfSequences()/*generates a random integer value between 2 and 10 and then generates a triangle of sequences*/
{
	int line, num;
	line = numberGeneratorBetweenRange(2, 10);
	for(int i = 0; i<=line; i++)
	{
		for(int j = 1; j<=i; j++)
		{
			num = j*i;
			printf("%d ", num);
		}
		printf("\n");
	}
}
