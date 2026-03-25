/*Να γραφεί η συνάρτηση void getStats(int x[],int size,int *count1,int *count2); Η συνάρτηση αυτή δέχεται σαν ορίσματα έναν πίνακα ακεραίων x, το μέγεθος του πίνακα size καθώς και δύο δείκτες count1 και count2.
Η συνάρτηση θα πρέπει να επιστρέψει στον δείκτη count1 (με αποαναφοροποίηση) το πλήθος των στοιχείων του πίνακα x που δεν έχουν κανένα διαιρέτη και στον δείκτη count2 το πλήθος των στοιχείων του πίνακα x 
που έχουν πάνω από 2 διαιρέτες. Να δείξετε μια χρήση της παραπάνω συνάρτησης μέσα από την main() συνάρτηση.*/

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
void getStats(int x[],int size,int *count1,int *count2)
{
	int i;
	*count1=0;
	*count2=0;
	for(i=0;i<size;i++)
	{
		int k = countDivisors(x[i]);
		if(k==0) *count1=*count1+1;
		else
		if(k>=2) *count2=*count2+1;
	}
}

int main()
{
	int x[10]={7,9,20,40,12,100,21,19,23,10};
	int count1,count2;
	getStats(x,10,&count1,&count2);
	printf("Metrites %d %d \n",count1,count2);
	return 0;
}
