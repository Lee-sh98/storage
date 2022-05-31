#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class student{
public:
	student(string n,float* g)
		:name(n), grade(g){}	// constructor
	string name;
	float* grade;
	string gpa;
};

/* function prototype */
void get_file(vector<int>&, vector<student>&);
void compute_grade(vector<int>, vector<student>&);
void write_file(vector<student>);

int main(){

	try{
		vector<int> ratio;
		vector<student> student_list;
		
		get_file(ratio,student_list);
		compute_grade(ratio,student_list);
		write_file(student_list);
		
	}
	catch(const char* e){
		cout<<e<<endl;
	}
	return 0;
}

void get_file(vector<int>& ratio,vector<student>& student_list){
	
	ifstream is;	// input file stream object 'is'
	cout<<"성적 파일 이름을 입력하세요: ";
	string file_name;
	getline(cin,file_name,'\n');

	is.open(file_name);
	/* confirm whether the file exists */
	if(!is){
		throw "파일 오픈에 실패하였습니다.";
	}
	
	string inp;
	getline(is, inp);
	string tmp="";
	
	/* input grade ratio into variable "ratio" */
	for(int i=0,count=0;inp[i];i++){
		if(inp[i]!=' '){
			tmp+=inp[i];
		}
		else{
			if(count){
				ratio.push_back(stoi(tmp));
			}
			count++;
			tmp="";
		}
		if(!inp[i+1]){
			ratio.push_back(stoi(tmp));
			tmp="";
		}
	}
	
	/*	get name and grades of students 
		then input student class into sutdent_list */
	while(getline(is,inp)){
		
		string name;
		float* grade =new float [ratio.size()];

		for(int i=0,count=0;inp[i];i++){
			if(inp[i]!=' '){
				tmp+=inp[i];
			}
			else{	// differntiate name and grade
				if(count==0){
					name=tmp;
				}
				else{
					grade[count-1]=stoi(tmp);
				}
				count++;
				tmp="";
			}
			if(!inp[i+1]){
				grade[count-1]=stoi(tmp);
				tmp="";
			}
		}
		student_list.push_back(student(name,grade));
	}
	
	is.close();
}

void compute_grade(vector<int> ratio, vector<student>& student_list){
	/* compute gpa of student */
	for(student& s:student_list){
		float num=0;
		int i=0;
		
		for(float* g=s.grade;*g;i++,g++){
			num+=*g*ratio[i]/100;
		}
		
		if(num>=85)
			s.gpa="A";
		else if(num>=70)
			s.gpa="B";
		else if(num>=55)
			s.gpa="C";
		else if(num>=40)
			s.gpa="D";
		else
			s.gpa="F";
	}
}

void write_file(vector<student> student_list){
	ofstream os;	// output file stream variable "os"
	os.open("grade.txt");
	
	if(os.fail()){
		throw "출력 파일을 열지 못하였습니다.";
	}
	for(student& s: student_list){
		string msg=s.name+": "+s.gpa+"\n";
		
		os.write(msg.c_str(),msg.size());
	}
	os.close();
}