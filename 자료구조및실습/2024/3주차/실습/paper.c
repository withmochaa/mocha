#include<stdio.h>
#include<string.h>

int Check(char *str, int len, char char1){
	if (len != 0){
		if (*(str + strlen(str) - 1 - len) == char1)
			return 1 + Check(str, len - 1, char1);
		else
			return 0 + Check(str, len - 1, char1);
	}
	else{
		if (*(str + strlen(str) - 1) == char1)
			return 1;
		else
			return 0;
	}
}
void main(){
	char str[100];
	char char1;
	gets(str);
	char1 = getchar();
	printf("%d\n", Check(str, strlen(str) - 1, char1));
}