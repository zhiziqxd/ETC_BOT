#ifndef check_H
#define check_H
#include "user.h"
#include "game.h"
#include "afk.h"
#include "say.h"
using namespace std;
string digit(int x){
	string t;
	while(x>0){
		t+=x%10;
		x/=10;
	}
	return f(t);
}
string lol[10]={
"�����ѽ��ˣ���������һ����������������������Ϊ����������!",
"����ĥ�˵Ļ�����һ������ս�������Ƿ������ճ����",
"��Ů��֪�����ޣ������̳���ͥ����",
"I'm nothing without you.",
"�δ������ݣ����۷�ⱱ��¥��",
"����ɽ����������ʱ���������š�",
"����Ҫ���ݣ�����Ҫ�������ǡ�",
"�����޷��ص���ȥ��ǰ���ķ���ֻ��δ����",
"�˵ľ���˼�뷽�������Խ�󣬸��������µĿռ��ԽС��"
}
string check(string str,string name){
	if(bot.lock==false){
		if(str.find("���"))<=str.length()||str.find("hi")<=str.length()){
		  if(rand()%2==0){
			  return "hiyo";
		  }
		  else{
		  	return "��ð�";
			}
	  }
		else if(afk_find(str)){
			return "@"+name+" �������ڹһ�Ŷ";
		}
		else if(str=="game"){
			if(bot.game=false){
				game_start();
				bot.game=true;
			}
			else{
				return game_end();
			}
		}
		else if(str=="r"&&bot.game==false){
			return digit(rand()%999+1);
		}
		else if(str=="r"&&bot.game==true){
			game_r();
			return digit(game.back());
		}
		else if(str=="afk"){
			add_afk(name);
			return name+"����afk,����!";
		}
		else if(str=="114514"||str=="������"){
			return "С����¶�������˰�";
		}
		else if(str.find("say ")<=str.length()){
			say(str,name);
			return "���Գɹ�!";
		}
		else if(str=="fuck"){
			return "@"+name<<" fuck you";
		}
		else if(str=="lol"){
			return lol[rand()%9];
		}
		else if(str=="lock"&&admin_find(trip)){
			bot.lock=true;
			return "�Ѿ���ס�����õ�������!";
		}
		else{
			r=rand()%10;
			if(r==0||r==1){
				return".";
			}
			else{
				return "no";
			}
		}
	}
	else if(admin_find(trip)&&str=="lock"){
		bot.lock=false;
		return "��������ing";
	}
}
#endif
