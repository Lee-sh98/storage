#include <iostream>

using namespace std;

template <class S, class T>
bool isEqual(S *s, T *t,int n){
	for (int i =0; i<n; i++){
		if(s[i]!=t[i])
			return false;
	}
	return true;
}

int main(){
	float  list1 [] ={1.2, 3.3, 9.0, 1.5, 8.7};
	float  list2 [] ={1.2, 3.3, 9.0, 1.5, 8.7};
	bool check=isEqual(list1,list2,5);
	cout<<boolalpha<<check<<endl;
	return 0;
}