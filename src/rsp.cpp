#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void GetInput(string& s){
	cin>>s;
	if(not(s=="가위"||s=="바위"||s=="보"))
		throw "\"가위\", \"바위\", \"보\" 중에서만 선택하세요.";
}
void ComputerInput(string& t){
	srand((unsigned int)time(NULL));
	int n=rand()%3;
	if (n==0)
		t="가위";
	else if(n==1)
		t="바위";
	else
		t="보";
}
int main(){
	string s;
	string t;
	try{
		cout<<"가위, 바위, 보 게임입니다.\n";
		cout<<"무엇을 내시겠습니까 : ";
		GetInput(s);
		ComputerInput(t);
		cout<<"컴퓨터는 "<<t<<"를 냈습니다.\n\n";
		
		if((s=="가위"&&t=="바위")||(s=="바위"&&t=="보")||(s=="보"&&t=="가위"))
			cout<<"당신이 졌습니다.\n";
		else if((s=="가위"&&t=="가위")||(s=="바위"&&t=="바위")||(s=="보"&&t=="보"))
			cout<<"비겼습니다.\n";
		else
			cout<<"당신이 이겼습니다.\n";
	}
	catch(const char* e){
		cerr<<"오류 : "<<e<<endl;
		return -1;
	}
	catch(...){
		cerr<<"오류";
	}
	return 0;
}