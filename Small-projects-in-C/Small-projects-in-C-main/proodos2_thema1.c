/*Να γραφεί συνάρτηση int changePrimes(int x[], int size);  η οποία δέχεται σαν όρισμα έναν πίνακα ακεραίων x καθώς και το μέγεθος του στην παράμετρο size. 
Η συνάρτηση αυτή θα πρέπει να αλλάζει κάθε πρώτο αριθμό που υπάρχει στον πίνακα x σε -1. Η συνάρτηση να επιστρέφει και το πλήθος των αλλαγών που έκανε. 
Να δείξετε μια χρήση της παραπάνω συνάρτησης μέσα από την main() συνάρτηση.*/

# include <stdio.h>

int isPrime(int n)
{
	int i;
	for(i=2;i<n/2;i++)
	{
		if(n%i==0) 
		   return 0;
	}
	return 1;
}

int changePrimes(int x[], int size)
{
	int i;
	int count = 0;
	for(i=0;i<size;i++)
	{
		if(isPrime(x[i]))
		{
			x[i]=-1;
			count++;
		}
	}
	return count;
}

int main()
{
	int x[5]={11,12,9,20,17};
	int k;
	k=changePrimes(x,5);
	printf("k = %d \n",k);
	return 0;
}
