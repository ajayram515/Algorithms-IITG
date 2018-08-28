#include <stdio.h>
/*Name: G AJAY RAM
  Roll: 160101029
  CS204 ALGORITHMS
  */


const int N=5;	//size of array L which contains coins

//calculates min. no. ofcoins required to get sum of 'c' using 'n' coins in 'L' and stores that value in "coinsUsed" array
int coins(int L[],int n,int c,int C,int coinsUsed[N][C],int done[N][C])
{

	//sum<0-->impossible 
	if (c<0)
		return 999;		//returning infinity(here 999 means infinity)




	//eventhough sum!=0 there are no elements in 'L' ie. n=0
	else if (c!=0 && n==0)
		return 999;		//returning infinity


	//to get sum '0' we reqd '0' no. of coins
	else if (c==0||(c==0 && n==0))
		return 0;		//returning '0'



	//our reqd value hasn't calculated before
	else if (done[n-1][c-1]==0)
	{
		int result;		//variale to store result


		int include=1+coins(L,n-1,c-L[n-1],C,coinsUsed,done);		//including highest coin in result and calculating min. for remaining


		int exclude=coins(L,n-1,c,C,coinsUsed,done);				//excluding highest coin in result and calculating min. for remaining


		//finding min. among exclude and include
		if(exclude>include)
			result=include;
		else
			result=exclude;					//storing min. value as result


		coinsUsed[n-1][c-1]= result;		//store the obtained result in matrix
		done[n-1][c-1]=1;					//update status of sub-problem in 'done' matrix

	}
	return coinsUsed[n-1][c-1];				//returning the result
}
int main()
{
	int L[]={1,1,3,4,5};		//Array with coins 
	int n=5;					//size of L
	int c;						//sum required	


	printf("enter the required sum:-");
	scanf("%d",&c);				//prompting required sum from user


	int C=c;					//storing value of 'c' in 'C' so that it woud remain constant 


	int coinsUsed[n][c];		//matrix to store min. coins reqd to get sum of 'c' with 'n' coins  
	int done[n][c];				//matrix to check whether the reqd value is calculated before or not 


	//initializing "done" array with all 0's in it
	int i,j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < c; ++j)
		{											
			done[i][j]=0;
		}
	}


	int rslt= coins(L,n,c,C,coinsUsed,done);		//calling "coins" function which calculates the min. no.of coins reqd to get sum 'c' 

	


	//min. no. of coins should be less than no. of coins in 'L'
	if(rslt<=n)
		printf("Min. no. of coins required :- %d\n", rslt);



	//if not it is impossible to get solution
	else
		printf("impossible to get\n");



	return 0;
}