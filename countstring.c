#include <stdio.h>

int main(){
	char countthis[] = {"this is a very long sentence suitable for counting 1234567890 lololol"};
	char *counter = countthis;
	for (int i = 0; i < 10000; i++){
		if (*(counter+i) == '\0'){
			printf("%d 글자\n",i);
			break;
		}
	}
	return 0;
}