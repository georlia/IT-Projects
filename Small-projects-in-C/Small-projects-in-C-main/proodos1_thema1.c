/*Να γραφεί συνάρτηση void alterTable(int x[], int size);  η οποία δέχεται σαν όρισμα έναν πίνακα ακεραίων x καθώς και το μέγεθος του στην παράμετρο size. 
Η συνάρτηση θα πρέπει να αλλάζει κάθε αριθμό που έχει λιγότερους από τρεις διαιρέτες σε 1 και κάθε άλλο αριθμό σε 0. 
Να δείξετε μια χρήση της παραπάνω συνάρτησης μέσα από την main() συνάρτηση. */

# include <stdio.h>

/** metraei tous diairetes tou n **/
int countDivisors(int n)
{
	int count = 0;
	int i;
	for(i=2;i<n/2;i++)
	{
		if(n%i==0) count++;
	}
	return count;
}

void alterTable(int x[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(countDivisors(x[i])<3) x[i]=1; else x[i]=0;
	}
}

int main()
{
	int i;
	int x[5]={10,11,12,20,9};
	alterTable(x,5);
	for(i=0;i<5;i++) 
	  printf("%d \n",x[i]);
	return 0;
}
