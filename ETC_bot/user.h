#ifndef user_H
#define user_H
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <ctime>
#include <vector>
using namespace std;
struct user{
	string trip;
	bool admin=false;
	bool no;
};
vector<user> u;
int ans;
void init(){
	u.resize(3);//�ڴ��Զ�����
	freopen("bot.in","r",stdin);
	cin>>ans>>lock;//��Ϊ����ǰvector�޷���size
	user a;
	for(int i=1;i<=ans;i++){//����vector��������Ҳ���õ����ڴ汬��
		cin>>a.trip>>a.admin;
		u.push_back(a);
	}
	freopen("CON","r",stdin);
}
void end(){
	freopen("bot.in","w",stdin);
	cout<<ans<<" "<<lock<<endl;
	for(int i=1;i<=ans;i++){
		cout<<u.at(i).trip;
	}
	return;
}
void add(string t,bool a,bool n){
	user flag;
	flag.trip=t;
	flag.admin=a;
	flag.no=n;
	return;
}
void change_admin(int x){
	u.at(x).admin=~u.at(x).admin;
}
void change_no(int x){
	u.at(x).no=~u.at(x).no;
}
void user_clear(){
	u.clear();
}
bool no_find(string str){
	for(int i=1;i<=ans;i++){
		if(u.at(i).trip==str&&u.at(i).no==true){
			return true;
		}
	}
	return false;
}
#endif
