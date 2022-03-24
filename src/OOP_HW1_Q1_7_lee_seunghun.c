#include <stdio.h>
#include <stdlib.h>
//문자열내 소문자를 대문자로 바꾸기
int main(){
	char *str=malloc(50*sizeof(char));
	scanf("%s",str);
	
	int i=0;
	while(str[i]){
		if(97<=(int)str[i]&&(int)str[i]<=122){
			str[i]=(int)str[i]-32;
	
		i++;
	}
	printf("%s",str);
	free(str);
	return 0;
}