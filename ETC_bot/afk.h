#ifndef afk_H
#define afk_H
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
vector<string> afk;
void add_afk(string str){
	afk.push_back(str);
	return;
}
bool del_afk(string str){//�п���ʧ��
	for(int i=0;i<afk.size();i++){
		if(afk.at(i)==str){
			afk.erase(i);
			return true;//�ɹ�
		}
	}
	return false;
}
bool check_afk(string str){
	for(int i=0;i<afk.size();i++){
		if(afk.at(i)==str){
			return true;
		}
	}
	return false;
}
int afk_number(){
	return afk.size();
	return;
}
string afk_find(string str){
	for(int i=0;i<str.length()-1;i++){
		str[i]=str[i+1];//ȥ��@
	}
	string t="";
	for(int i=0;str[i]!=' '&&i<str.length();i++){
		t+=str[i];
	}
	for(int i=0;i<afk.size();i++){
		if(afk.at(i)==t){
			return true;
		}
	}
	return false;
}
#endif
