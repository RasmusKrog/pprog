#include <stdio.h>
#include <stdlib.h>
int main(){
	char* hello = "Hello,";
	char* user = getenv("USER");
	printf("%s %s!\n",hello,user);
return 0;
}
