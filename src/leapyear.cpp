#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isLeap(int n){
	if ((!(n%4)&&(n%100))||!(n%400))
		return true;
	else
		return false;
}

int main(){
	int year;
	cout<<"현재 년도를 입력하세요 : ";
	cin>>year;
	
	vector<int> v;
	for(int i=1;i<=year;i++)
		v.push_back(i);
	
	int leaps=count_if(v.begin(),v.end(),isLeap);
	cout<<"현째가지 윤년의 수 : "<<leaps<<endl;
}