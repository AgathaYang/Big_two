#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
int remain[5];
int type_mem;
int s;

struct card { 
   const char *face;
   const char *suit;
   int face_number;
   int suit_number;
};

typedef struct card Card;

void fillDeck( Card * const, const char *[], const char *[] ,int [], int [] );	// 設牌初始值
void shuffle( Card * const );									// 洗牌
void deal( const Card * const ,int,int);// 列印牌
void get_card( Card * const, Card * const,int,int );//塞牌入陣列
int five_card(Card * const);//判斷五張的牌型
int three_card(Card * const);//判斷三張的牌型
void sort_1( Card * const ,int,int );//先排數字再排花色
void sort_2( Card * const ,int,int);//先排花色再排數字
int card_13(Card * const);//看是不是一條龍;
void computer_play(Card * const,Card * const,Card * const,Card * const);//電腦的前中後分法
int counting(Card * const,int,Card * const,int,int,int,int);//找出最大的牌型
int compair(Card * const, Card * const);//比較五張牌的大小
void swap(Card * const, Card * const,int,int);//交換牌
int compair_three(Card * const, Card * const);//比較三張牌的大小
void function(Card * const,int,int *, const char *[], const char *[] ,int [], int []);//main函式的使用者面板
void main(){
	Card deck[ 52 ];
   
    const char *face[] = { "Ace", "Deuce", "Three", 
                          "Four", "Five",
                          "Six", "Seven", "Eight", 
                          "Nine", "Ten",
                          "Jack", "Queen", "King"};//有13種數字
    int face_number[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};//13種數字的編號

    const char *suit[] = { "Spades","Hearts", "Diamonds", "Clubs" };  //有四種花色           
    int suit_number[] ={4,3,2,1};//四種花色的編號

    int choice,count=0;
	int score;
	printf("一局要幾分?\n");
	scanf("%d",&score);
	printf("(1)重新開始\n(2)繼續下一回\n(3)不玩了\n");
	scanf("%d",&choice);
	while(choice!=3){                  //當choice是3時就是跳出不玩了!
		switch(choice){
			case 1:
				count=0;    //重新計分
				function(deck,score,&count,face,suit ,face_number,suit_number);
				
				break;
						
			case 2:
				
				function(deck,score,&count,face,suit ,face_number,suit_number);
				break;
					}
		printf("\n(1)重新開始\n(2)繼續下一回\n(3)不玩了\n");
		scanf("%d",&choice);
}
}
/***********************************************************/
void function(Card * const deck,int score,int *count, const char *face[], const char *suit[] ,int face_number[], int suit_number[]){
	Card north[13],west[13],east[13],south[13];  //共有四家玩家
	Card north_first[5],north_second[5],north_third[3];  //北家的後中前墩
	Card west_first[5],west_second[5],west_third[3];  //西家的後中前墩
	Card south_first[5],south_second[5],south_third[3];  //南家的後中前墩
	Card east_first[5],east_second[5],east_third[3];   //東家的後中前墩
	Card player_first[5],player_second[5],player_third[3];//玩家的前中後墩
	int self,want, play;
	int ch,toget,i,first_number,second_number,third_number,a;
	Card wanted[13];//玩家想合作的電腦
	Card player[13];//玩家

				srand( time( NULL ) );
				fillDeck( deck, face, suit,face_number,suit_number);		// 設牌初始值
				shuffle( deck );
				get_card(deck,north,0,12);//將0~12分給北家
				get_card(deck,west,13,25);//將13~25分給西家
				get_card(deck,east,26,38);//將26~38分給東家
				get_card(deck,south,39,51);//將39~51分給南家
				//deal(north,12,0);
				//deal(west,12,0);
				//deal(east,12,0);
				//deal(south,12,0);
				printf("選擇一個玩家給自己1 2 3 4\n");
				scanf("%d",&play);//選擇要1234哪一家
				switch(play){
					case 1:
						printf("你的牌:\n");
						get_card(north,player,0,12);//選第一家就將第一家設為玩家並印出
						sort_2(player,0,12);
						deal(player,12,0);
						
						break;
					case 2:
						printf("你的牌:\n");
						get_card(south,player,0,12);//選第二家就將第二家設為玩家並印出
						sort_2(player,0,12);
						deal(player,12,0);
						break;
					case 3:
						printf("你的牌:\n");
						get_card(west,player,0,12);//選第三家就將第三家設為玩家並印出
						sort_2(player,0,12);
						deal(player,12,0);
						break;
					case 4:
						printf("你的牌:\n");
						get_card(east,player,0,12);//選第四家就將第四家設為玩家並印出
						sort_2(player,0,12);
						deal(player,12,0);
						break;
				}
				printf("要不要換牌?(1要/2不要)\n");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						//有合作玩家
						printf("選擇要合作的玩家 1 2 3 4\n");
						scanf("%d",&toget);
						switch(toget){
							case 2:
								get_card(south,wanted,0,12);//選擇第一家就將第一家設為合作玩家並印出他的牌
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								break;
							case 1:
								get_card(north,wanted,0,12);//選擇第二家就將第二家設為合作玩家並印出他的牌
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								break;
							case 4:
								get_card(east,wanted,0,12);//選擇第三家就將第三家設為合作玩家並印出他的牌
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								break;
							case 3:
								get_card(west,wanted,0,12);//選擇第四家就將第四家設為合作玩家並印出他的牌
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								
								break;
						}
						printf("選擇自己想換掉的牌位置和想換的牌的位置(1/2)照上面的排序\n");
						scanf("%d/%d",&self,&want);
						swap(player,wanted,self-1,want-1);//換牌
						deal(player,12,0);//印出換玩牌的玩家
						printf("\n");
						deal(wanted,12,0);//印出換玩牌的合作玩家
						
                        printf("後墩\n");//玩家自己組後墩
						for(i=0;i<=4;i++){
							scanf("%d",&first_number);
							player_first[i]=player[first_number-1];
						}
						printf("中墩:\n");//玩家自己組中墩
						for(i=0;i<=4;i++){
							scanf("%d",&second_number);
							player_second[i]=player[second_number-1];
						}
						printf("前墩:\n");//玩家自己組前墩
						for(i=0;i<=2;i++){
							scanf("%d",&third_number);
							player_third[i]=player[third_number-1];
						}
						printf("你的後墩:\n");
						deal(player_first,4,0);
						printf("你的中墩:\n");
						deal(player_second,4,0);
						printf("你的前墩:\n");
						deal(player_third,2,0);
						if(five_card(player_first)>=five_card(player_second)&&five_card(player_second)>=three_card(player_third)){
						
							if(play==1){
								computer_play(south,south_first,south_second,south_third);
								computer_play(east,east_first,east_second,east_third);
								computer_play(west,west_first,west_second,west_third);
							}
							else if(play==2){
								computer_play(north,north_first,north_second,north_third);
								computer_play(east,east_first,east_second,east_third);
								computer_play(west,west_first,west_second,west_third);
							}
							else if(play==3){
								computer_play(south,south_first,south_second,south_third);//東南西北家都自己分前中後墩
								computer_play(north,north_first,north_second,north_third);
								computer_play(east,east_first,east_second,east_third);
							}
							else if(play==4){
								computer_play(south,south_first,south_second,south_third);//東南西北家都自己分前中後墩
								computer_play(north,north_first,north_second,north_third);
								computer_play(west,west_first,west_second,west_third);
							}
						
							if(toget!=1&&play!=1){                    //如果第一家不是玩家跟合作玩家
								if(compair(player_first,north_first)==1){//進行後墩比較
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,north_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,north_first)==2)
									printf("後墩平手\n");
								deal(north_first,4,0);
								if(compair(player_second,north_second)==1){  //進行中墩比較
									(*count)++;
									printf("中墩你贏了!\n");
								}
								else if(compair(player_second,north_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,north_second)==2)
									printf("中墩平手\n");
								deal(north_second,4,0);
								if(compair_three(player_third,north_third)==1){//進行前墩比較
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,north_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,north_third)==2)
									printf("前墩平手\n");
								deal(north_third,2,0);
								if(compair(player_first,north_first)==1&&compair(player_second,north_second)==1&&compair_three(player_third,north_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,north_first)==0&&compair(player_second,north_second)==0&&compair_three(player_third,north_third)==0)
									(*count)=(*count)-3;

							}
							//三墩全輸是輸六墩，三墩全贏是贏六墩
							
							if(toget!=2&&play!=2){								//如果第二家不是玩家跟合作玩家
								if(compair(player_first,south_first)==1){      //進行後墩比較
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,south_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,south_first)==2)
									printf("後墩平手\n");
								deal(south_first,4,0);
					
						
								if(compair(player_second,south_second)==1){//進行中墩比較
									(*count)++;
									printf("中墩你贏了!\n");
								}	
								else if(compair(player_second,south_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,south_second)==2)
									printf("中墩平手\n");
								deal(south_second,4,0);
					
					
								if(compair_three(player_third,south_third)==1){//進行前墩比較
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,south_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,south_third)==2)
										printf("前墩平手\n");
								deal(south_third,2,0);
								if(compair(player_first,south_first)==1&&compair(player_second,south_second)==1&&compair_three(player_third,south_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,south_first)==0&&compair(player_second,south_second)==0&&compair_three(player_third,south_third)==0)
									(*count)=(*count)-3;
							}
							//三墩全輸是輸六墩，三墩全贏是贏六墩
							
							if(toget!=3&&play!=3){//如果第三家不是玩家跟合作玩家
								if(compair(player_first,west_first)==1){//進行後墩比較
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,west_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,west_first)==2)
									printf("後墩平手\n");
								deal(west_first,4,0);
						
								if(compair(player_second,west_second)==1){//進行中墩比較
									(*count)++;
									printf("中墩你贏了!\n");
								}
								else if(compair(player_second,west_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,west_second)==2)
									printf("中墩平手\n");
								deal(west_second,4,0);
						
								if(compair_three(player_third,west_third)==1){//進行前墩比較
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,west_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,west_third)==2)
									printf("前墩平手\n");
								deal(west_third,2,0);
								if(compair(player_first,west_first)==1&&compair(player_second,west_second)==1&&compair_three(player_third,west_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,west_first)==0&&compair(player_second,west_second)==0&&compair_three(player_third,west_third)==0)
									(*count)=(*count)-3;
							}
							//三墩全輸是輸六墩，三墩全贏是贏六墩
							
							if(toget!=4&&play!=4){//如果第四家不是玩家跟合作玩家
								if(compair(player_first,east_first)==1){//進行後墩比較
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,east_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,east_first)==2)
									printf("後墩平手\n");
								deal(east_first,4,0);
						
								if(compair(player_second,east_second)==1){//進行中墩比較
									(*count)++;
									printf("中墩你贏了!\n");
								}
								else if(compair(player_second,east_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,east_second)==2)
									printf("中墩平手\n");
								deal(east_second,4,0);
						
								if(compair_three(player_third,east_third)==1){//進行前墩比較
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,east_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,east_third)==2)
									printf("前墩平手\n");
								deal(east_third,2,0);
								if(compair(player_first,east_first)==1&&compair(player_second,east_second)==1&&compair_three(player_third,east_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,east_first)==0&&compair(player_second,east_second)==0&&compair_three(player_third,east_third)==0)
									(*count)=(*count)-3;
							}
							//三墩全輸是輸六墩，三墩全贏是贏六墩
							
							}
						else{
							printf("你的牌違規!!不可以玩!!\n");
						
						}
							break;
						
						
						

						
					case 2:
						//與case1一樣只是沒有合作玩家
						printf("後墩\n");
						for(i=0;i<=4;i++){
							scanf("%d",&first_number);
							player_first[i]=player[first_number-1];
						}
						printf("中墩:\n");
						for(i=0;i<=4;i++){
							scanf("%d",&second_number);
							player_second[i]=player[second_number-1];
						}
						printf("前墩:\n");
						for(i=0;i<=2;i++){
							scanf("%d",&third_number);
							player_third[i]=player[third_number-1];
						}
						printf("你的後墩:\n");
						deal(player_first,4,0);
						printf("你的中墩:\n");
						deal(player_second,4,0);
						printf("你的前墩:\n");
						deal(player_third,2,0);
						if(five_card(player_first)>=five_card(player_second)&&five_card(player_second)>=three_card(player_third)){
							if(play==1){
								computer_play(south,south_first,south_second,south_third);
								computer_play(east,east_first,east_second,east_third);
								computer_play(west,west_first,west_second,west_third);
							}
							else if(play==2){
								computer_play(north,north_first,north_second,north_third);
								computer_play(east,east_first,east_second,east_third);
								computer_play(west,west_first,west_second,west_third);
							}
							else if(play==3){
								computer_play(south,south_first,south_second,south_third);//東南西北家都自己分前中後墩
								computer_play(north,north_first,north_second,north_third);
								computer_play(east,east_first,east_second,east_third);
							}
							else if(play==4){
								computer_play(south,south_first,south_second,south_third);//東南西北家都自己分前中後墩
								computer_play(north,north_first,north_second,north_third);
								computer_play(west,west_first,west_second,west_third);
							}
							if(play!=1){
								if(compair(player_first,north_first)==1){
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,north_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,north_first)==2)
									printf("後墩平手\n");
								deal(north_first,4,0);
						
								if(compair(player_second,north_second)==1){
									(*count)++;
									printf("中墩你贏了!\n");
								}
								else if(compair(player_second,north_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,north_second)==2)
									printf("中墩平手\n");
								deal(north_second,4,0);
						
					
								if(compair_three(player_third,north_third)==1){
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,north_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,north_third)==2)
									printf("前墩平手\n");
								deal(north_third,2,0);
								if(compair(player_first,north_first)==1&&compair(player_second,north_second)==1&&compair_three(player_third,north_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,north_first)==0&&compair(player_second,north_second)==0&&compair_three(player_third,north_third)==0)
									(*count)=(*count)-3;
							}
							

							if(play!=2){
								if(compair(player_first,south_first)==1){
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,south_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,south_first)==2)
									printf("後墩平手\n");
								deal(south_first,4,0);
						
						
								if(compair(player_second,south_second)==1){
									(*count)++;
									printf("中墩你贏了!\n");
								}
								else if(compair(player_second,south_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,south_second)==2)
									printf("中墩平手\n");
								deal(south_second,4,0);
						
						
								if(compair_three(player_third,south_third)==1){
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,south_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,south_third)==2)
									printf("前墩平手\n");
								deal(south_third,2,0);
								if(compair(player_first,south_first)==1&&compair(player_second,south_second)==1&&compair_three(player_third,south_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,south_first)==0&&compair(player_second,south_second)==0&&compair_three(player_third,south_third)==0)
									(*count)=(*count)-3;
							}
							
							if(play!=3){
								if(compair(player_first,west_first)==1){
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,west_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,west_first)==2)
									printf("後墩平手\n");
								deal(west_first,4,0);
						
						
								if(compair(player_second,west_second)==1){
									(*count)++;
									printf("中墩你贏了!\n");
								}
								else if(compair(player_second,west_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,west_second)==2)
									printf("中墩平手\n");
								deal(west_second,4,0);
						
						
								if(compair_three(player_third,west_third)==1){
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,west_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,west_third)==2)
									printf("前墩平手\n");
								deal(west_third,2,0);
								if(compair(player_first,west_first)==1&&compair(player_second,west_second)==1&&compair_three(player_third,west_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,west_first)==0&&compair(player_second,west_second)==0&&compair_three(player_third,west_third)==0)
									(*count)=(*count)-3;
							}
							
							if(play!=4){
								if(compair(player_first,east_first)==1){
									(*count)++;
									printf("後墩你贏了!\n");
								}
								else if(compair(player_first,east_first)==0){
									(*count)--;
									printf("後墩你輸了\n");
							    
								}
								else if(compair(player_first,east_first)==2)
									printf("後墩平手\n");
								deal(east_first,4,0);
								if(compair(player_second,east_second)==1){
									(*count)++;
									printf("中墩你贏了!\n");
								}
								else if(compair(player_second,east_second)==0){
									(*count)--;
									printf("中墩你輸了\n");
							    
								}
								else if(compair(player_second,east_second)==2)
									printf("中墩平手\n");
								deal(east_second,4,0);
								if(compair_three(player_third,east_third)==1){
									(*count)++;
									printf("前墩你贏了!\n");
								}
								else if(compair_three(player_third,east_third)==0){
									(*count)--;
									printf("前墩你輸了\n");
							    
								}
								else if(compair_three(player_third,east_third)==2)
									printf("前墩平手\n");
								deal(east_third,2,0);
								if(compair(player_first,east_first)==1&&compair(player_second,east_second)==1&&compair_three(player_third,east_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,east_first)==0&&compair(player_second,east_second)==0&&compair_three(player_third,east_third)==0)
									(*count)=(*count)-3;
							}
							
							}
						else{
							printf("你的牌違規!!不可以玩!\n");
							
						}

						break;
							
						
						}
						
						printf("目前積分:%d",(*count) * score);
						
						

}

/*********************************************************/
void fillDeck( Card * const wDeck, const char * wFace[], 
               const char * wSuit[],int wFace_number[],int wSuit_number[] )
{ 
   int i;

   for ( i = 0; i <= 51; i++ ) { 

      wDeck[ i ].face = wFace[ i % 13 ];
	  wDeck[ i ].face_number = wFace_number[i % 13];

      wDeck[ i ].suit = wSuit[ i / 13 ];
	  wDeck[ i ].suit_number=wSuit_number[ i / 13];
   }
}
/****************************************************************/
void shuffle( Card * const wDeck )
{ 
   int i, j;
   Card temp;

   for ( i = 0; i <= 51; i++ ) { 

      j = rand() % 52;
      
	  temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   }
}
/********************************************************************/

void deal( const Card * const wDeck ,int size,int start)
{ 
   int i;

   for ( i = start; i <= size; i++ ){

	   printf( "%d \t %5s of %-8s   %d %d",i+1, wDeck[ i ].face, wDeck[ i ].suit ,wDeck[ i ].suit_number,wDeck[ i ].face_number);
	   printf("\n");
         
	  }
   
}
/*********************************************************************/
void get_card( Card * const wDeck,Card * const Direct,int start,int end){
	int i;
	int j=0;
	for(i=start;i<=end;i++){
		Direct[j].face = wDeck[i].face;
		Direct[j].face_number = wDeck[i].face_number;
		Direct[j].suit = wDeck[i].suit;
		Direct[j].suit_number = wDeck[i].suit_number;
		j++;
	}
	
}
/******************************************************/
int five_card(Card * const wDeck){
	int i,j,count_face=0,count_suit=0,a,count_re=0,b,count=0;
	int type=0;
	sort_1( wDeck,0,4);
	for(i=0;i<4;i++){         //所有兩兩情況都考慮過一遍
		for(j=i+1;j<5;j++){

			if(wDeck[i].face_number==wDeck[j].face_number){//數字兩兩相同的次數記錄
				++count_face;

				if(count_face==1){
					a=i;//記住i以便後面檢查時可以使用
				}

				if(count_face>=2){ //ex:11223這種例子count_face會算成2
					
						if(wDeck[a].face_number!=wDeck[i].face_number){//檢查有沒有像11223這種情況要是有就將count_face減一，否則會重複計算
							count_face=count_face-1;
							count_re=count_re+1;//count_re是計算當有兩個對子時11223就是這種情況這樣就可以判斷有幾個對子
						}

					}
			}

			if(wDeck[i].suit_number==wDeck[j].suit_number){
				count_suit++;//花色兩兩相同時的記錄
			}
			
			
			
			
		}
	}
	for(b=0;b<4;b++){
		if(wDeck[b].face_number == (wDeck[b+1].face_number+1)){
			
			count++;//因為是用先排數字再排花色，這是在看順子
		}
		

	}
	if(wDeck[0].face_number==13&&(wDeck[0].face_number == (wDeck[4].face_number+12))){
			count++;//因為有ace，king...也是順子
		}
		
	if(count_face==0&&count!=4) {//散牌
		
		type=1;
	}
	if(count_face==1&&count_re==0){//對子
		
        type=2;
	}
	if(count_re==1&&count_face==1){//二對
		
		type=3;
	}
	if(count_face==3&&count_re==0){//三條
	    
		type=4;
	}
	if(count==4&&count_suit!=10){//順子
		
		type=5;
	}
	if(count_suit==10&&count!=4){//同花
		
		type=6;
	}
	if(count_re==1&&count_face==3){//葫蘆
		
		type=7;
	}
	if(count_face==6&&count_re==0){//四條
		
		type=8;
	}
	if(count_suit==10&&count==4){//同花順
		
		type=9;
	}
	return type;
	
	
}
/*************************************************************/
int three_card(Card * const wDeck){
	int type=0;
	int i,j,count=0,count_suit=0;

	for(i=0;i<2;i++){
		for(j=i+1;j<3;j++){
			if(wDeck[i].face_number==wDeck[j].face_number){//數字兩兩相同的次數記錄
				count++;
			}
			if(wDeck[i].suit_number==wDeck[j].suit_number){//花色兩兩相同時的記錄
				count_suit++;
			}
		}
	}

	switch(count){
		case 0://散牌
			
			type=1;
			break;
		case 1://對子
			
			type=2;
			break;
		case 3://三條
			
			type=4;
			break;
		default:
			break;
	}
	if(count_suit==3)//同花
		type=6;
   return type;
		

}
/**************************************************************/
void sort_2( Card * const wDeck,int start,int end){
	int a,b;
	Card temp;
	
	for( a = start ; a < end ; a++){//bubble sort

		for( b = start ; b < end ; b++){

			if( wDeck[b].face_number < wDeck[b+1].face_number ){

				 temp = wDeck[ b+1 ];
				 wDeck[ b+1 ] = wDeck[ b ];
				 wDeck[ b ] = temp;
			}

		}
	}
	for( a = start ; a < end ; a++){

		for( b = start ; b < end ; b++){

			if ( wDeck[b].suit_number > wDeck[b+1].suit_number ){
	
  				 temp = wDeck[ b+1 ];
				 wDeck[ b+1 ] = wDeck[ b ];
				 wDeck[ b ] = temp;
			}

		}
	}
}
/****************************************************************/
void sort_1( Card * const wDeck,int start,int end)
{
	
	int a,b;
	Card temp;
	
	for( a = start ; a < end ; a++){

		for( b = start ; b< end ; b++){

			if( wDeck[b].suit_number > wDeck[b+1].suit_number ){

				 temp = wDeck[ b+1 ];
				 wDeck[ b+1 ] = wDeck[ b ];
				 wDeck[ b ] = temp;
			}

		}
	}
	for( a = start ; a < end ; a++){

		for( b = start ; b < end ; b++){

			if( wDeck[b].face_number < wDeck[b+1].face_number ){ 

				 temp = wDeck[ b+1 ];
				 wDeck[ b+1 ] = wDeck[ b ];
				 wDeck[ b ] = temp;
			}

		}
	}
}
/******************************************************************/
int card_13(Card * const wDeck){
	sort_1(wDeck,0,12);
	int i,count=0,type;
	for(i=0;i<13;i++){
		if(wDeck[i].face_number==(wDeck[i+1].face_number+1)){//檢查是不是1~13都有
			count++;
		}
	}
	if(count==12){//一條龍
		
		type=10;
		return type;
	}
	
	return 0;



}
/**********************************************************************/
void computer_play(Card * const Direct,Card * const first,Card * const second,Card * const third){
	int i,j, a=0,b=0;
	
	Card temp[8];
	if ( (card_13(Direct)) == 10 ){
		printf("computer win!!");
	}
	sort_2(Direct,0,12);
	for(i=9;i>=0;i--){                      //找後墩
		if(counting(Direct,i,first,8,10,10,0)==1)
			break;
	}
	
	for(j=0;j<=12;j++){//first用過的牌不可以再用
		if(j==remain[0]||j==remain[1]||j==remain[2]||j==remain[3]||j==remain[4]){//remain是記取出的牌在direct裡的位置
			continue;
		}
		temp[a]=Direct[j];
		a++;
	}
	
	
	for(i=type_mem;i>=0;i--){                //找中墩，但是不可以比後墩大所以從小於後墩的型態開始找
		if(counting(temp,i,second,3,5,5,0)==1)
			break;
	}
	for(j=0;j<=7;j++){//second用過的牌不可以再用
		if(j==remain[0]||j==remain[1]||j==remain[2]||j==remain[3]||j==remain[4]){//remain是記取出的牌在direct裡的位置
			continue;
		}
		third[b]=temp[j];
		b++;
	}



}
int counting(Card * const Direct,int type,Card * const Place,int ii,int jj,int kk,int x)//找尋最適合的牌型
{
	int i,j,k,h,w,count=0,count_array=0;
	Card temp[5];
	for(i=x;i<=ii;i++){        //跑不同的可能
		for(j=i+1;j<=jj;j++){
			for(k=j+1;k<=kk;k++){
				h=k+1;
				w=h+1;
				s=i;
				temp[0]=Direct[i];//將跑到可能的內容放入temp中
				temp[1]=Direct[j];
				temp[2]=Direct[k];
				temp[3]=Direct[h];
				temp[4]=Direct[w];
				if(five_card(temp)==type){//如果temp的type是剛好等於傳入的type
					if(count_array!=1){ //找到最大的就不要再找了!
						remain[0]=i;
						remain[1]=j;
						remain[2]=k;
						remain[3]=h;
						remain[4]=w;
						type_mem=type;
						get_card(temp,Place,0,4);
						count_array++;
					}
				}
			}
		}
	}
	return count_array;
}
/***************************************************************/
int compair(Card * const player, Card * const opponent){
	int type,i,count=0,j=0,c,d;
	int a,b,count1=0,count2=0;
	if(five_card(player)>five_card(opponent)){ //如果玩家比較大就回傳1
		return 1;						  
	}									
	else if(five_card(player)<five_card(opponent)){//如果對手比較大就回傳0
		return 0;
	}
	else if(five_card(player)==five_card(opponent)){//看兩個比較的牌type是否一樣一樣就比較其中的數字
		type=five_card(player);
		if(type==1){//如果都為散牌的話比數字
			for(i=0;i<=4;i++){
				if(player[i].face_number>opponent[i].face_number&&opponent[i].face_number!=1)
					return 1;
				else if(opponent[i].face_number==1&&player[i].face_number!=1)
					return 0;
				else if(player[i].face_number<opponent[i].face_number&&player[i].face_number!=1)
					return 0;
				else if(player[i].face_number==1&&opponent[i].face_number!=1)
					return 1;
				else if(player[i].face_number==opponent[i].face_number){
					count++;
					continue;
				}
				if(count==5)
					return 2;
			}
		}
		if(type==2){//如果都為對子就比對子大小，如果對子大小相同的話，依序比較另外的幾張牌
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //因為是先排數字所以一樣的數字會排在一起;
					a=player[i].face_number;
				}
				if(opponent[i].face_number==opponent[i+1].face_number){
					b=opponent[i].face_number;
				}
			}
			if(a>b&&b!=1)return 1;
			else if(b==1&&a!=1)return 0;//比對子;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;
			else if(a==b){                       //對子一樣->依序比剩下的數字
				for(i=0;i<=4;i++){
					if(player[i].face_number==a){
						continue;
					}
					if(opponent[j].face_number==b){
						j++;
					}
					if(player[i].face_number>opponent[j].face_number&&opponent[j].face_number!=1)
						return 1;
					
					else if(opponent[j].face_number==1&&player[i].face_number!=1)
						return 0;
					
					else if(opponent[j].face_number>player[i].face_number&&player[i].face_number!=1)
						return 0;
					
					else if(player[i].face_number==1&&opponent[j].face_number!=1)
						return 1;
					j++;
					
				}
			}
		}
		if(type==3){//如果都是兩對的話，先比大的對子，再比小的對子，均同的話，比另外的那張牌。  

			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //因為是先排數字所以一樣的數字會排在一起;
					a=player[i].face_number;                            //找較大的對子   
					c=i;
				}
			}
			for(i=0;i<=4;i++){
				if(opponent[i].face_number==opponent[i+1].face_number){
					b=opponent[i].face_number;
					d=i;
				}
			}
			
			if(a>b&&b!=1)return 1;
			else if(b==1&&a!=1)return 0;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;
			else if(a==b){                           //如果較大的都一樣，找小的對子
				for(i=c+1;i<=4;i++){
					if(player[i].face_number==player[i+1].face_number){    //因為是先排數字所以一樣的數字會排在一起;
						a=player[i].face_number;                            //找較大的對子   
					
					}
				}
				for(i=d+1;i<=4;i++){
					if(opponent[i].face_number==opponent[i+1].face_number){
						b=opponent[i].face_number;
					
					}
				}
				if(a>b&&b!=1)return 1;
				else if(b==1&&a!=1)return 0;
				else if(a<b&&a!=1)return 0;
				else if(a==1&&b!=1)return 1;

			}



		}
		if(type==4){//如果都是三條就比較三條的數字
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //因為是先排數字所以一樣的數字會排在一起;
					a=player[i].face_number;
				}
				if(opponent[i].face_number==opponent[i+1].face_number){
					b=opponent[i].face_number;
				}
			}
			if(a>b&&b!=1)return 1;
			else if(b==1&&a!=1)return 0;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;

		}
		if(type==5){//若都是順子的話就比第一張因為都依照數字排好了!如果最後一張不是1的話就直接比第一張的大小，如果最後一張是1的話就代表他是最大的那副順子
			if(player[0].face_number>opponent[0].face_number&&opponent[4].face_number!=1)return 1;
			else if(opponent[4].face_number==1&&player[4].face_number!=1)return 0;
			else if(player[0].face_number<opponent[0].face_number&&player[4].face_number!=1)return 0;
			else if(opponent[4].face_number!=1&&player[4].face_number==1)return 1;
			if(player[0].face_number==opponent[0].face_number)return 2;
		}
		if(type==6){//如果都是同花就比較第一張花色大小，要是花色都一樣的話就比第一張的數字，因為都排好了
			if(player[0].suit_number>opponent[0].suit_number)return 1;
			else if(player[0].suit_number<opponent[0].suit_number)return 0;
			else if(player[0].suit_number==opponent[0].suit_number){
				if(player[0].face_number>opponent[0].face_number)return 1;
				else if(player[0].face_number<opponent[0].face_number)return 0;

			}
		}
		if(type==7){//都是葫蘆的話就比較三條數字大小
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){
					count1++;
				}
				if(count1==2){
					a=player[i].face_number;
					break;
				}
			}
			for(i=0;i<=4;i++){
				if(opponent[i].face_number==opponent[i+1].face_number){
					count2++;
				}
				if(count2==2){
					b=opponent[i].face_number;
					break;
				}
			}
			if(a>b&&b!=1)return 1;
			else if(b==1&&a!=1)return 0;//比三條;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;

		}
		if(type==8){//都是四條就比較四條的數字大小
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //因為是先排數字所以一樣的數字會排在一起;
					a=player[i].face_number;
				}
				if(opponent[i].face_number==opponent[i+1].face_number){
					b=opponent[i].face_number;
				}
			}
			if(a>b&&b!=1)return 1;
			else if(b==1&&a!=1)return 0;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;

		}
		if(type==9){//都是同花順就比較第一張看誰大
			if(player[0].face_number>opponent[0].face_number&&opponent[4].face_number!=1)
					return 1;
					
			else if(opponent[4].face_number==1&&player[4].face_number!=1)
					return 0;
					
			else if(opponent[0].face_number>player[0].face_number&&player[4].face_number!=1)
					return 0;
					
			else if(player[4].face_number==1&&opponent[4].face_number!=1)
					return 1;
			else if(player[0].face_number==opponent[0].face_number){
				if(player[0].suit_number>opponent[0].suit_number)return 1;
				else if(player[0].suit_number<opponent[0].suit_number)return 0;
			}
			
		}

	}

}
/******************************************************************/

void swap(Card * const player, Card * const wanted,int self,int want){//交換
	Card temp;
	temp=wanted[want];
	wanted[want]=player[self];
	player[self]=temp;

}
/****************************************************************/
int compair_three(Card * const player, Card * const opponent){
	int a,b,type,j=0,i,count=0;
	if(three_card(player)>three_card(opponent)){
		return 1;
	}
	else if(three_card(player)<three_card(opponent)){
		return 0;
	}
	else if(three_card(player)==three_card(opponent)){
		type=three_card(player);
		if(type==1){//如果都為散牌的話比數字
			for(i=0;i<=2;i++){
				if(player[i].face_number>opponent[i].face_number&&opponent[i].face_number!=1)
					return 1;
				else if(opponent[i].face_number==1&&player[i].face_number!=1)
					return 0;
				else if(player[i].face_number<opponent[i].face_number&&player[i].face_number!=1)
					return 0;
				else if(player[i].face_number==1&&opponent[i].face_number!=1)
					return 1;
				else if(player[i].face_number==opponent[i].face_number){
					count++;
					continue;
				}
				if(count==3)
					return 2;
			}
		}
		if(type==2){//如果都為對子就比對子大小，如果對子大小相同的話，依序比較另外的幾張牌
				for(i=0;i<=2;i++){
				if(player[i].face_number==player[i+1].face_number){    //因為是先排數字所以一樣的數字會排在一起;
					a=player[i].face_number;
				}
				if(opponent[i].face_number==opponent[i+1].face_number){
					b=opponent[i].face_number;
				}
			}
			if(a>b&&b!=1)return 1;
			else if(b==1&&a!=1)return 0;//比對子;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;
			else if(a==b){                       //對子一樣->依序比剩下的數字
				for(i=0;i<=2;i++){
					if(player[i].face_number==a){
						continue;
					}
					if(opponent[j].face_number==b){
						j++;
					}
					if(player[i].face_number>opponent[j].face_number&&opponent[j].face_number!=1)
						return 1;
					
					else if(opponent[j].face_number==1&&player[i].face_number!=1)
						return 0;
					
					else if(opponent[j].face_number>player[i].face_number&&player[i].face_number!=1)
						return 0;
					
					else if(player[i].face_number==1&&opponent[j].face_number!=1)
						return 1;
					j++;
					
				}
			}
		}
		if(type==4){//如果都是三條就比較三條的數字
			if(player[0].face_number>opponent[0].face_number&&opponent[0].face_number!=1)
						return 1;
					
			else if(opponent[0].face_number==1&&player[0].face_number!=1)
						return 0;
					
			else if(opponent[0].face_number>player[0].face_number&&player[0].face_number!=1)
						return 0;
					
			else if(player[0].face_number==1&&opponent[0].face_number!=1)
						return 1;
			
		}
		if(type==6){//如果都是同花就比較第一張花色大小，要是花色都一樣的話就比第一張的數字，因為都排好了
			if(player[0].suit_number>opponent[0].suit_number)return 1;
			else if(player[0].suit_number<opponent[0].suit_number)return 0;
			else if(player[0].suit_number==opponent[0].suit_number){
				if(player[0].face_number>opponent[0].face_number)return 1;
				else if(player[0].face_number<opponent[0].face_number)return 0;
			}
		}
	}

}
