#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;
class Checker{
	public: 
	Checker(){
	};
	string check(string line){
		if(line[0] == '>'){
			if(line[1] == ' '){
				return "RelOp: GT";
			}
			if(line[1] == '='){
				if(line[2] == ' '){
					return "RelOp: GTE";
				}
				else{
					return "**ERROR**";
				}
			}
			else{
				return "**ERROR**";
			}
		}
		
		if(line[0] == '<'){
			
			if(line[1] == ' '){
				return "RelOp: LT";
			}
			
			if(line[1] == '='){
				if(line[2] == ' '){
					return "RelOp: LTE";
				}
				else{
					return "**ERROR**";
				}
			}
	
			if(line[1] == '>'){
				if(line[2] == ' '){
					return "RelOps: NE";
				}
				else{
					return "**ERROR**";
				}
			}
			else{
				return "**ERROR**";
			}
		}
		
		if(line[0] == '='){
			if(line[1] == ' '){
				return "RelOp: AssOp";
			}
			if(line[1] == '='){
				if(line[2] == ' '){
					return "RelOp: EqlCheck";
				}
				else{
					return "**ERROR**";
				}
			}
			else{
				return "**ERROR**";
			}
		}
		
	}
};

int main(){
	string currLine;
	ifstream fileOpener("op.txt");
	
	Checker checker;
	while(getline(fileOpener,currLine)){
		cout<<"input: "<<currLine<<" output: "<< checker.check(currLine)<<endl;
	}
	
	return 0;
}
