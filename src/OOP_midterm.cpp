#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Schedule{
public:
    Schedule(string Tit,string Loc,string Det,string Y,string M,string D,string BH,string BM,string EH,string EM)
    :title{Tit},location{Loc},detail{Det},year{Y},month{M},day{D},begin{BH,BM},end{EH,EM}
    {}
    string year, month, day;
    string begin [2];
    string end [2];
    string title,location, detail;
};

void AddSchedule(vector<Schedule>&);
void ModifySchedule(vector<Schedule>&);
void DeleteSchedule(vector<Schedule>&);
void ViewSchedule(vector<Schedule>);
void Viewing(Schedule);
void running();
void InputAndSplit(string*,char);

int main(){
	running();
	return 0;
}

void running(){
	vector<Schedule> ScList;
	cout<<endl;
	while(true){
		cout<<"Scheduler Program"<<endl;
		cout<<"Mode 1: Add Schedule"<<endl;
		cout<<"Mode 2: Modify Schedule"<<endl;
		cout<<"Mode 3: Delete Schedule"<<endl;
		cout<<"Mode 4: View Schedule"<<endl;
		cout<<"Mode 5: Exit"<<endl<<endl;
		
		cout<<"Select a Mode Number: ";
		int a;
		cin>>a;
		
		if(a==1)
			AddSchedule(ScList);
		else if(a==2)
			ModifySchedule(ScList);
		else if(a==3)
			DeleteSchedule(ScList);
		else if(a==4)
			ViewSchedule(ScList);
		else if(a==5){
			cout<<"Closing Scheduler"<<endl;
			break;
		}
	}
}

void AddSchedule(vector<Schedule>& v){
	string title, location, detail;
	string date[3], begin[2],end[2];
	cin.ignore();
	cout<<"Add Schdule"<<endl;
	
	cout<<"Enter Title: ";
	getline(cin, title, '\n');
	cout<<"Enter Date(YYYY-MM-DD): ";
	InputAndSplit(date,'-');
	
	cout<<"Enter Begin Time(HH:MM): ";
	InputAndSplit(begin,':');
	
	cout<<"Enter End Time(HH:MM): ";
	InputAndSplit(end,':');
	
	cout<<"Enter Location: ";
	getline(cin, location, '\n');
	
	cout<<"Enter Detail: ";
	getline(cin, detail, '\n');
	
	v.push_back(Schedule(title,location,detail,date[0],date[1],date[2],begin[0],begin[1],end[0],end[1]));

	cout<<"A schedule has been added!"<<endl<<endl;
}

void ModifySchedule(vector<Schedule>& v){
	string date[3],begin[2];
	cin.ignore();
	cout<<endl;
	cout<<"Modify Schedule"<<endl;
	cout<<"Enter the Schedule Date(YYYY-MM-DD): ";
	InputAndSplit(date,'-');
	
	cout<<"Enter th Begin Time(HH:MM): ";
	InputAndSplit(begin,':');
	
	for(Schedule& s:v){
		if(s.year==date[0]&&s.month==date[1]&&s.day==date[2]&&
		  s.begin[0]==begin[0]&&s.begin[1]==begin[1]){
			string title="", location="", detail="";
			for(string& d:date)
				d="";
			for (string& b:begin)
				b="";
			string end[]={"",""};
			
			cout<<endl<<"Current Schedule: "<<endl;
			Viewing(s);
			cout<<endl;
			
			cout<<"Enter New Title (If not changing, press Enter): ";
			getline(cin, title,'\n');
			cout<<"Enter New Date(YYYY-MM-DD) (If unchanged, press Enter): ";
			InputAndSplit(date,'-');
			cout<<"Enter New Begin Time(HH:MM) (If unchanged, press Enter): ";
			InputAndSplit(begin,':');
			cout<<"Enter New End Time(HH:MM) (If unchanged, press Enter): ";
			InputAndSplit(end,':');
			cout<<"Enter New Location (If unchanged, press Enter): ";
			getline(cin, location,'\n');
			cout<<"Enter New Detail (If unchanged, press Enter): ";
			getline(cin, detail, '\n');
			
			if(title!="")
				s.title=title;
			if(date[0]!=""&&date[1]!=""&&date[2]!=""){
				s.year=date[0];
				s.month=date[1];
				s.day=date[2];
			}
			if(begin[0]!=""&&begin[1]!=""){
				s.begin[0]=begin[0];
				s.begin[1]=begin[1];
			}
			if(end[0]!=""&&end[1]!=""){
				s.end[0]=end[0];
				s.end[1]=end[1];
			}
			if(location!="")
				s.location=location;
			if(detail!="")
				s.detail=detail;
			break;
		}
	}
	cout<<endl;
}

void DeleteSchedule(vector<Schedule>& v){
	string date[3],begin[2];
	int index=0;
	cin.ignore();
	cout<<endl;
	cout<<"Remove Schedule"<<endl;
	
	cout<<"Enter the Schedule Date (YYYY-MM-DD): ";
	InputAndSplit(date,'-');
	cout<<"Enter the Begin Time (HH:MM): ";
	InputAndSplit(begin,':');
	
	for(Schedule& s:v){
		if(s.year==date[0]&&s.month==date[1]&&s.day==date[2]&&
		  s.begin[0]==begin[0]&&s.begin[1]==begin[1]){
			v.erase(v.begin()+index,v.begin()+index+1);
			break;
		}
		index++;
	}
	cout<<"The schedule has been removed."<<endl<<endl;
}

void ViewSchedule(vector<Schedule> v){
	int opt;
	cout<<endl;
	cout<<"Option 1: View All Schedules"<<endl;
	cout<<"Option 2: View Schedules by Date"<<endl;
	cout<<"Option 3: View Schedules by Title"<<endl;
	cout<<"Enter an Option Number: ";
	cin>>opt;
	
	if(opt==1){	// view all schedules
		cout<<endl<<"Displaying All Schedules"<<endl;
		for(Schedule s:v){
			Viewing(s);
			cout<<endl;
		}
	}
	else if(opt==2){	// view schedules by date
		string date[3];
		cin.ignore();
		cout<<"Enter the date(YYYY-MM-DD): ";
		InputAndSplit(date,'-');
		cout<<endl<<"Displaying Schedules on "<<date[0]<<"-"<<date[1]<<"-"<<date[2]<<endl;
		for(Schedule s:v){
			if(s.year==date[0]&&s.month==date[1]&&s.day==date[2]){
				Viewing(s);
				cout<<endl;
			}
		}
	}
	else if(opt==3){	// view schedules by title
		string title;
		cout<<"Enter the title: ";
		cin>>title;
		cout<<endl<<"Displaying Schedules of "<<title<<endl;
		for(Schedule s:v){
			if(s.title.find(title)!=string::npos){
				Viewing(s);
				cout<<endl;
			}
		}
		
	}
}

void InputAndSplit(string* arr,char delimiter){
	string inp="";
	getline(cin, inp,'\n');
	for(int i=0,j=0;inp[i];i++){
		if(inp[i]!=delimiter){
			arr[j]+=inp[i];
		}
		else
			j++;
	} 
}

void Viewing(Schedule s){
	cout<<"Title: "<<s.title<<endl;
	cout<<"Date: "<<s.year<<"-"<<s.month<<"-"<<s.day<<endl;
	cout<<"Time: "<<s.begin[0]<<":"<<s.begin[1]<<"-"<<s.end[0]<<":"<<s.end[1]<<endl;
	cout<<"Location: "<<s.location<<endl;
	cout<<"Detail: "<<s.detail<<endl;
	
}