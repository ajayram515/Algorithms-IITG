#include <stdio.h>
/*Name: G AJAY RAM
  Roll: 160101029
  CS204 ALGORITHMS
  */


int main()
{
	int L[]={5,4,3,1,1};		//Array with coins 
	int n=5;					//size of L

	int c;						//sum required


	printf("enter the required sum:-");
	scanf("%d",&c);				//prompting required sum from user


	int coinsUsed[n+1][c+1];	//matrix to store min. coins reqd to get sum of 'c' with 'n' coins  



	//initializing "done" array with all 999(infinity)'s in it
	int i,j;
	for (i = 0; i <=n; ++i)
	{
		for (j = 0; j<= c; ++j)
		{
			coinsUsed[i][j]=999;
		}
	}



	//with 0 coins we can't make any sum
	for (j=0; j <=c; ++j)
	{
		coinsUsed[0][j]=0;
	}



	
	for (i = 1; i <=n; ++i)
	{
		if(L[i-1]<=c)
			coinsUsed[1][L[i-1]]=1;			//with '1' coin we can form sum with min '1' coin for coin in 'L' only


		coinsUsed[i][0]=0;					//to make sum '0' we reqd '0' coins
	}




	int include,exclude;
	int k; 

	//using more than '1' coins
	for (i = 2; i <=n; ++i)
	{
		//calculating for each from 1 to reqd sum 'c'
		for (j = 1; j <= c; ++j)
		{

			include=999;	//initializing include for every itteration


				//loop for including each element in 'L'
				for (k= 0; k <n; ++k)
				{
					if(j-L[k]>=0&&include>1+coinsUsed[i-1][j-L[k]]&&coinsUsed[i-1][j-L[k]]!=999)
						if(j-L[k]>=L[k]&&L[k]!=1)
							include=999;
						else
							include=1+coinsUsed[i-1][j-L[k]];		
				}


					
				exclude=coinsUsed[i-1][j];		//exclude value is already calculated in previous row



				//storing min. value among exclude and include in Matrix
				if(include>exclude )
					coinsUsed[i][j]=exclude;
				else if(include<=exclude )
					coinsUsed[i][j]=include;
			
		}
	
	}




	//printing coinsUsed matrix
	for (i = 1; i <=n; ++i)
	{
		for (j = 1; j<= c; ++j)
		{
			printf("%5d ",coinsUsed[i][j]);
		}
		printf("\n");
	}




	if(coinsUsed[n][c]>5||coinsUsed[n][c]<0)
		printf("impossible to get\n");
	else
		printf("Min. no. of coins required :-%d\n ",coinsUsed[n][c] );
		
	return 0;
}
