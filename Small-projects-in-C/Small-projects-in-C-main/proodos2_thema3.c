/*Να γραφεί η συνάρτηση void getStats(char x[],int *count1,int *count2);  Η συνάρτηση αυτή δέχεται σαν ορίσματα ένα αλφαριθμητικό x και δύο δείκτες count1 και count2. 
Η συνάρτηση με την χρήση αποαναφοροποίησης θα πρέπει να επιστρέφει στον δείκτη count1 το πλήθος των αριθμητικών συμβόλων του αλφαριθμητικού x και 
στον δείκτη count2 το πλήθος των συμβόλων που δεν είναι ούτε πεζά ούτε κεφαλαία γράμματα. Να δείξετε μια χρήση της παραπάνω συνάρτησης μέσα από την main() συνάρτηση.*/

# include <stdio.h>
# include <string.h>
# include <ctype.h>

void getStats(char x[],int *count1,int *count2)
{
	int i;
	*count1=0;
	*count2=0;
	for(i=0;i<strlen(x);i++)
	{
	  if(isdigit(x[i])) *count1=*count1+1;
	  if(!isupper(x[i]) && !islower(x[i])) *count2=*count2+1;
	}
}


int main()
{
	char x[100]="ABxxx###123";
	int count1,count2;
	getStats(x,&count1,&count2);
	printf("Counters: %d %d \n",count1,count2);
}
