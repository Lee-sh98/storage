#include <stdio.h>
#include <stdlib.h>
//해당금액에 맞는 최적의 동전 갯수 구하기
int _pow();
int main(){
	
	int num;
	int i=0;
	int *arr = malloc(50*sizeof(int));
	
	scanf("%d",&num);

	while(num){  //split each decimal and discriminate whether the decimal is over 5 before store it in array
		if(num%10>4){
			arr[i]=num%10-5;
			arr[i+1]=1;
		}
		else{
			arr[i]=num%10;
			arr[i+2]=0;
		}
		i+=2;
		num/=10;
	}
	/*printf("i : %d \n",i);
	for(int j=0; j<i;j+=2){
		printf("%d %d\n",arr[j],arr[j+1]);
	}*/
	
	for(int j=0; j<i;j+=2){
		if(arr[j])printf("%6d원 %d개  ",_pow(10,j/2),arr[j]);
		if(arr[j+1])printf("%6d원 %d개",_pow(10,j/2)*5,arr[j+1]);
		if(arr[j]||arr[j+1])printf("\n");
		num=num+arr[j]+arr[j+1];
	}
	
	free(arr);
	printf("총 동전 갯수 : %d\n",num);
	return 0;
}
int _pow(int base, int exponent){
	int result = 1;
	for(int i = 0; i<exponent;i++){
		result*=base;
	}
	return result;
}