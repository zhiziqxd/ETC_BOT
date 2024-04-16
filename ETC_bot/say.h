#ifndef say_H
#define say_H
#include "check.h"
using namespace std;
struct to_say{
	string from;
	string left;
	string say;
};
vector<to_say> s;
void say(string str,string name){
	string left="";
	int cnt;
	string talk="";
	for(int i=3;str[i]!=' '&&i<str.length();i++){
		left+=str[i];
		cnt=i;
	}
	for(int i=cnt;i<str.length();i++){
		talk+=str[i];
	}
	s.push_back({name,left,talk});
	return;
}
string read(string name){
	string r="";
	for(int i=0;i<s.size();i++){
		if(name==s.at(i).left){
			r+=s.at(i).from+":"+s.at(i).say+"/n";
		}
	}
	return r;
}
#endif
