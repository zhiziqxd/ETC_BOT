#ifndef game_H
#define game_H
#include <iostream>
#include <cstdlib>
#include <queue>
#include "user.h"
using namespace std;
struct bot{
	string say;
	bool lock=false;
	bool game=false;
}bot;
void lock(){
	bot.lock=~bot.lock;
	return;
}
queue<int> game;
void game_start(){
	bot.game=true;
	while(game.empty()==false){
		game.pop();
	}//清空队列
	return;
}
string f(string str){
	string t;
	for(int i=str.length();i>0;i--){
		t+=str[i];
	}
	return t;
}
string game_end(){
	bot.game=false;
	int maxx=INT_MIN,minn=INT_MAX;
	while(game.empty()==false){
		maxx=max(maxx,game.back());
		minn=min(minn,game.back());
	}
	string str="",str2="";
	while(maxx>0){
		str+=char(maxx%10+48);//转为字符串
	}
	while(minn>0){
		str2+=char(minn%10+48);
	}
	return "最大:"+f(str)+" 最小:"+f(str2);//倒转str
}
void game_r(){
	game.push(rand()%1000+1);
	return;
}
#endif
