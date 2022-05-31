#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,inp;
	int min, max;
	vector<int> v;
	
	cout<<"정수의 개수: ";

	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"정수를 입력하시오";
		cin>>inp;
		v.push_back(inp);
		
	}
	min=v[0];
	max=v[0];
	for(int i=1;i<n;i++){
		if(min>v[i])
			min=v[i];
		if(max<v[i])
			max=v[i];
		
	}
	cout<<min<<endl<<max;
	return 0;
}
