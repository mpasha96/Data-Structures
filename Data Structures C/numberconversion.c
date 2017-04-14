#include <stdio.h>
#include <stdlib.h>
#define max 9

int top = -1;
int stack[max];
int flag = 1;

int main()
{
    int num;
    printf("Enter number :");
	scanf("%d",&num);

	while(num>0)
	{
		push(num%10);
		num = num/10;
	}

	convert(top+1);

    return 0;
}

void push(int digit)
{

	if(top>max)
	{
		printf("Stack overflow.");

		getch();
		exit(0);

	}

	else
		stack[++top] = digit;

}

void print(int num)
{

	switch(num)
	{

		case 1:
			printf("ONE ");
			break;

		case 2:
			printf("TWO ");
			break;

		case 3:
			printf("THREE ");
			break;

		case 4:
			printf("FOUR ");
			break;

		case 5:
			printf("FIVE ");
			break;

		case 6:
			printf("SIX ");
			break;

		case 7:
			printf("SEVEN ");
			break;

		case 8:
			printf("EIGHT ");
			break;

		case 9: printf("NINE ");
			break;

	}

}

void printtwo(int num)
{

	switch(num)
	{

		case 1:
			switch(stack[top])
			{

				case 1:
					printf("ELEVEN ");
					break;

				case 2:
					printf("TWELVE ");
					break;

				case 3:
					printf("THIRTEEN ");
					break;

				case 4:
					printf("FOURTEEN ");
					break;

				case 5:
					printf("FIFTEEN ");
					break;

				case 6:
					printf("SIXTEEN ");
					break;

				case 7:
					printf("SEVENTEEN ");
					break;

				case 8:
					printf("EIGHTEEN ");
					break;

				case 9: printf("NINETEEN ");
					break;

				case 0:
					printf("TEN ");
					flag = 0;
			}
			break;

		case 2:
			printf("TWENTY ");
			break;

		case 3:
			printf("THIRTY ");
			break;

		case 4:
			printf("FORTY ");
			break;

		case 5:
			printf("FIFTY ");
			break;

		case 6:
			printf("SIXTY ");
			break;

		case 7:
			printf("SEVENTY ");
			break;

		case 8:
			printf("EIGHTY ");
			break;

		case 9: printf("NINETY ");
			break;

	}

}

void convert(int length)
{

	if(length==9)
	{
		printtwo(stack[top--]);

		if(stack[top+1]!=1 && flag)
			print(stack[top--]);
		else
			top--;

		printf("CRORES ");

	}

	if(length>=7)
	{

		if(length==8)
		{

			print(stack[top--]);
			printf("CRORES ");

		}

		printtwo(stack[top--]);

		if(stack[top+1]!=1 && flag)
			print(stack[top--]);

		else
			top--;

		if(stack[6]!=0||stack[5]!=0)
			printf("LACS ");

		if(flag==0)
		      flag = 1;

	}

	if(length>=5)
	{

		if(length==6)
		{

			print(stack[top--]);
			printf("LACS ");

		}

		printtwo(stack[top--]);

		if(stack[top+1]!=1 && flag)
			print(stack[top--]);
		else
			top--;

		if(stack[4]!=0||stack[3]!=0)
			printf("THOUSAND ");

		if(flag==0)
			flag = 1;

	}

	if(length>=3)
	{

		if(length==4)
		{

			print(stack[top--]);
			printf("THOUSAND ");

		}

		print(stack[top--]);

		if(stack[2]!=0)
			printf("HUNDERED ");

		if(stack[1]==0&&stack[0]!=0)
		{

			printf("AND ");
			print(stack[0]);

		}

		else if(stack[1]!=0)
		{

			printf("AND ");
			printtwo(stack[top--]);

			if(stack[top+1]!=1 && flag)
				print(stack[top--]);

		}

	}

	if(length==2)
	{

		printtwo(stack[top--]);

		if(stack[top+1]!=1 && flag)
			print(stack[top--]);

		if(flag==0)
			flag = 1;

	}

	if(length==1)
		print(stack[top--]);

}


