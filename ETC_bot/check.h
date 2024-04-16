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
"世界脱节了，这是怎样一个被诅咒的因果啊，竟是因为纠正它而生!",
"最折磨人的或许不是一场惨烈战争，而是烦琐的日常生活。",
"商女不知亡国恨，隔江犹唱后庭花。",
"I'm nothing without you.",
"何处望神州？满眼风光北固楼。",
"力拔山兮气盖世。时不利兮骓不逝。",
"自责要短暂，不过要长久铭记。",
"我们无法回到过去，前进的方向，只有未来。",
"人的精神思想方面的优势越大，给无聊留下的空间就越小。"
}
string check(string str,string name){
	if(bot.lock==false){
		if(str.find("你好"))<=str.length()||str.find("hi")<=str.length()){
		  if(rand()%2==0){
			  return "hiyo";
		  }
		  else{
		  	return "你好啊";
			}
	  }
		else if(afk_find(str)){
			return "@"+name+" 此人正在挂机哦";
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
			return name+"正在afk,加油!";
		}
		else if(str=="114514"||str=="蔡徐坤"){
			return "小黑子露出鸡脚了吧";
		}
		else if(str.find("say ")<=str.length()){
			say(str,name);
			return "留言成功!";
		}
		else if(str=="fuck"){
			return "@"+name<<" fuck you";
		}
		else if(str=="lol"){
			return lol[rand()%9];
		}
		else if(str=="lock"&&admin_find(trip)){
			bot.lock=true;
			return "已经锁住，不用担心我了!";
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
		return "继续工作ing";
	}
}
#endif
