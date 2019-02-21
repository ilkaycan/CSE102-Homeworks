#include<stdio.h>
int main()
{
	int n, num, divider=1, division, rem, count, flag=1;
	while(flag)/*if number is not in range ask again*/
	{
	printf("\nEnter the number:");
	scanf("%d", &num);
	printf("\n");
		if(num>22 && num<98761){
			flag=0; /* if number is in range end loop */
		} else {
			printf("Not in Range!!!\n");
		}
	}
	if(num>22 && num<100){ /* Find digit number */
		n=2;
	}
	else if(99<num && 1000>num){
		n=3;
	}
	else if(999<num && num<10000){
		n=4;
	}else if(9999<num && num<98761){
		n=5;
	}
	
	count = n-1;

	while(count>0){      /* calculate divider*/
	divider = divider*10;
	
	count--;
	}

	while(n>0){                     /* divide until all digits have been found */
		
		division = num/divider;
		rem = num%divider ;
		if(n==5){
		printf("Fifth digit is:  %d\n", division); /*print digits*/
		} if(n==4){
		printf("Forth digit is:  %d\n", division);
		} if(n==3){
		printf("Third digit is:  %d\n", division);
		} if(n==2){
		printf("Second digit is: %d\n", division);
		} if(n==1){
		printf("First digit is:  %d\n", division);
		}
		divider = divider/10;
		num = rem;
		n--;
	}
return 0;
}

