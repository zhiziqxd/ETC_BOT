#ifndef check_H
#define check_H
#include "user.h"
#include "game.h"
#include "afk.h"
using namespace std;
string digit(int x){
	string t;
	while(x>0){
		t+=x%10;
		x/=10;
	}
	return f(t);
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
		else{
			r=rand()%10;
			if(r==0||r==1){
				return".";
			}
			else{
				return"";
			}
		}
	}
}
#endif
