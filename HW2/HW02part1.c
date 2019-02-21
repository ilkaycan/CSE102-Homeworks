#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char letterg( int grade);

int main()
{
	char lg;
	double average;
	int flag = 1,flag1=1, selection, a=0, b=0, c=0, d=0, f=0;
	int stuc, grade, grades=-1, gradef=101, index=0, indexs, indexf, stc, total=0;
		while(flag1) /*if number is not in range ask again*/
		{		
			srand(40);
			printf("Enter student count:");
			scanf("%d", &stuc);
			stc = stuc; /*stuc changes in while loop so hold another variable stc to calculate average etc*/
			
			if(stuc>2 && stuc<51){
				flag1 = 0;
				while(stuc>0) /* print grades as much as student count */
				{
					grade = 0+rand()%100 ;
					printf("%d", grade);
					printf(" ");
					index++; /* calculate index */
					total = total + grade; /*hold variables for most succesful and unsuccesful students' grade and index */
					if(grade>grades){
						grades = grade;
						indexs = index;
					} 
					if(grade<gradef)
					{
						gradef = grade;	
						indexf = index;
					} 
					
					lg = letterg(grade); /* letter grade informations */
					if(lg == 'A'){
						a++;
					} else if(lg == 'B'){
						b++;
					} else if(lg == 'C'){
						c++;
					} else if(lg == 'D'){
						d++;
					} else if(lg == 'F'){
						f++;
					}
					
					stuc--;		
				}
				
			}else{
				printf("\nNot in Range!!!\n");
			}

		}	
	while(flag) /* show menu repeatedly */
	{
			printf("\n-------------------------------------------------------------\n");
			printf("\nStudent Score Calculater Menu for %d Student\n", stc);
			printf("\n1) Most Succesful Student\n");
			printf("2)Most Unsuccesful Student\n");
			printf("3)Letter Grade Statics\n");
			printf("4)Calculate Average\n");
			printf("5)Show all Data\n");

			printf("			Make Selection:");
			scanf("%d", &selection);

			switch (selection)
			{
			case 1:													/*informations of most succesful student*/
				printf("Most succesfully student:\n"); 
				printf("Index: %d\n", indexs);
				printf("Score: %d\n", grades);
				printf("Letter grade %c\n", letterg(grades));
				break;
			case 2:													/*informations of most unsuccesful student*/
				printf("Most unsuccesfully student:\n"); 
				printf("Index: %d\n", indexf);
				printf("Score: %d\n", gradef);
				printf("Letter grade %c\n", letterg(gradef));
				break;
			case 3:													/*letter grade informations*/
				printf("%d student got letter 'A'", a);    
				printf("\n%d student got letter 'B'", b);
				printf("\n%d student got letter 'C'", c);
				printf("\n%d student got letter 'D'", d);
				printf("\n%d student got letter 'F'", f);
				break;
			case 4:                                                 /*average grade*/
				average = (double)total/stc;
				printf("\nThe average Score of %d student is %.2lf\n", stc, average);
				break;
			case 5:     											/* all information */
				printf("Most succesfully student:\n");
				printf("Index: %d\n", indexs);
				printf("Score: %d\n", grades);
				printf("Letter grade %c\n", letterg(grades));

				printf("Most unsuccesfully student:\n");
				printf("Index: %d\n", indexf);
				printf("Score: %d\n", gradef);
				printf("Letter grade %c\n", letterg(gradef));

				printf("%d student got letter 'A'", a);
				printf("\n%d student got letter 'B'", b);
				printf("\n%d student got letter 'C'", c);
				printf("\n%d student got letter 'D'", d);
				printf("\n%d student got letter 'F'", f);

				average = (double)total/stc;
				printf("\nThe average Score of %d student is %.2lf:", stc, average);
				break;
			case -1:								/*-1 ends program */
				flag=0;
				break;
			default:                                
			printf("\nFalse selection!!!");
			}
	} 				
return 0;
}
char letterg(int grade)   /* find letter grade */
{
	char letter;
	if(grade<60){
		letter = 'F';
	} else if(grade>59 && grade<70){
		letter = 'D';
	} else if(69<grade && grade<80){
		letter = 'C';
	} else if(79<grade && grade<90){
		letter = 'B';
	} else {
		letter = 'A';
	}
return letter;
}





























