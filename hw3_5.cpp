#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
struct card { 
   const char *face;
   const char *suit;
   int face_number;
   int suit_number;
};

typedef struct card Card;
int five_card(Card * const);
void sort_2( Card * const ,int,int);//���ƪ��
void sort_1( Card * const ,int,int);
void fillDeck( Card * const, const char *[], const char *[] ,int [], int [] );	// �]�P��l��
void shuffle( Card * const );									// �~�P
void deal( const Card * const ,int,int);// �C�L�P
void get_card( Card * const, Card * const,int,int );
void swap(Card * const, Card * const,int,int);
int compair(Card * const, Card * const);

void main(){
	Card deck[ 52 ];
    Card north[5],west[5],east[5],south[5];
	int choice,self,want, play;
	int ch,toget,count=0,score;
    const char *face[] = { "Ace", "Deuce", "Three", 
                          "Four", "Five",
                          "Six", "Seven", "Eight", 
                          "Nine", "Ten",
                          "Jack", "Queen", "King"};
    int face_number[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    const char *suit[] = { "Spades","Hearts", "Diamonds", "Clubs" };             
    int suit_number[] ={1,2,3,4};
	Card wanted[5];
	Card player[5];
	
	printf("�@���n�X��?\n");
	scanf("%d",&score);
	printf("(1)���s�}�l\n(2)�~��U�@�^\n(3)�����F\n");
	scanf("%d",&choice);
	while(choice!=3){
		switch(choice){
			case 1:
				count=0;
				srand( time( NULL ) );
				fillDeck( deck, face, suit,face_number,suit_number);		// �]�P��l��
				shuffle( deck );
				get_card(deck,north,0,4);
				get_card(deck,west,5,9);
				get_card(deck,east,10,14);
				get_card(deck,south,15,19);
				printf("��ܤ@�Ӫ��a���ۤv1 2 3 4\n");
				scanf("%d",&play);
				switch(play){
					case 1:
						printf("�A���P:\n");
						get_card(north,player,0,4);
						deal(player,4,0);
						break;
					case 2:
						printf("�A���P:\n");
						get_card(south,player,0,4);
						deal(player,4,0);
						break;
					case 3:
						printf("�A���P:\n");
						get_card(west,player,0,4);
						deal(player,4,0);
						break;
					case 4:
						printf("�A���P:\n");
						get_card(east,player,0,4);
						deal(player,4,0);
						break;
				}
				printf("�n���n���P?(1�n/2���n)\n");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						printf("��ܭn�X�@�����a 1 2 3 4\n");
						scanf("%d",&toget);
						switch(toget){
							case 2:
								get_card(south,wanted,0,4);
								deal(wanted,4,0);
								break;
							case 1:
								get_card(north,wanted,0,4);
								deal(wanted,4,0);
								break;
							case 4:
								get_card(east,wanted,0,4);
								deal(wanted,4,0);
								break;
							case 3:
								get_card(west,wanted,0,4);
								deal(wanted,4,0);
								break;
						}
						printf("��ܦۤv�Q�������P��m�M�Q�����P����m(1/2)�ӤW�����Ƨ�\n");
						scanf("%d/%d",&self,&want);
						swap(player,wanted,self-1,want-1);
						deal(player,4,0);
						printf("\n");
						deal(wanted,4,0);
						if(toget!=1&&play!=1){
							if(compair(player,north)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,north)==0){
								count--;
								printf("�A��F\n");
							    
							}
							else if(compair(player,north)==2)
								printf("����\n");
							deal(north,4,0);
						}
						if(toget!=2&&play!=2){
							if(compair(player,south)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,south)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,south)==2)
								printf("����\n");
							deal(south,4,0);
						}
						if(toget!=3&&play!=3){
							if(compair(player,west)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,west)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,west)==2)
								printf("����\n");
							deal(west,4,0);
						}
						if(toget!=4&&play!=4){
							if(compair(player,east)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,east)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,east)==2)
								printf("����\n");
							deal(east,4,0);
						}
						printf("�ثe�n��:%d",count*score);
						break;
						

						
					case 2:
						if(play!=1){
							if(compair(player,north)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,north)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,north)==2)
								printf("����\n");
							deal(north,4,0);
						}
						if(play!=2){
							if(compair(player,south)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,south)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,south)==2)
								printf("����\n");
							deal(south,4,0);
						}
						if(play!=3){
							if(compair(player,west)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,west)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,west)==2)
								printf("����\n");
							deal(west,4,0);
						}
						if(play!=4){
							if(compair(player,east)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,east)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,east)==2)
								printf("����\n");
							deal(east,4,0);
						}
						
						
						break;
					}
					printf("�ثe�n��:%d",count*score);
					break;
/*********************************************************************************/

			case 2:
				srand( time( NULL ) );
				fillDeck( deck, face, suit,face_number,suit_number);		// �]�P��l��
				shuffle( deck );
				get_card(deck,north,0,4);
				get_card(deck,west,5,9);
				get_card(deck,east,10,14);
				get_card(deck,south,15,19);
				printf("��ܤ@�Ӫ��a���ۤv1 2 3 4\n");
				scanf("%d",&play);
				switch(play){
					case 1:
						printf("�A���P:\n");
						get_card(north,player,0,4);
						deal(player,4,0);
						break;
					case 2:
						printf("�A���P:\n");
						get_card(south,player,0,4);
						deal(player,4,0);
						break;
					case 3:
						printf("�A���P:\n");
						get_card(west,player,0,4);
						deal(player,4,0);
						break;
					case 4:
						printf("�A���P:\n");
						get_card(east,player,0,4);
						deal(player,4,0);
						break;
				}
				printf("�n���n���P?(1�n/2���n)\n");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						printf("��ܭn�X�@�����a 1 2 3 4\n");
						scanf("%d",&toget);
						switch(toget){
							case 2:
								get_card(south,wanted,0,4);
								deal(wanted,4,0);
								break;
							case 1:
								get_card(north,wanted,0,4);
								deal(wanted,4,0);
								break;
							case 4:
								get_card(east,wanted,0,4);
								deal(wanted,4,0);
								break;
							case 3:
								get_card(west,wanted,0,4);
								deal(wanted,4,0);
								break;
						}
						printf("��ܦۤv�Q�������P��m�M�Q�����P����m(1/2)�ӤW�����Ƨ�\n");
						scanf("%d/%d",&self,&want);
						swap(player,wanted,self-1,want-1);
						deal(player,4,0);
						printf("\n");
						deal(wanted,4,0);
						if(toget!=1&&play!=1){
							if(compair(player,north)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,north)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,north)==2)
								printf("����\n");
							deal(north,4,0);
						}
						if(toget!=2&&play!=2){
							if(compair(player,south)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,south)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,south)==2)
								printf("����\n");
							deal(south,4,0);
						}
						if(toget!=3&&play!=3){
							if(compair(player,west)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,west)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,west)==2)
								printf("����\n");
							deal(west,4,0);
						}
						if(toget!=4&&play!=4){
							if(compair(player,east)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,east)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,east)==2)
								printf("����\n");
							deal(east,4,0);
						}
						printf("�ثe�n��:%d",count*score);
						break;
						

						
					case 2:
						if(play!=1){
							if(compair(player,north)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,north)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,north)==2)
								printf("����\n");
							deal(north,4,0);
						}
						if(play!=2){
							if(compair(player,south)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,south)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,south)==2)
								printf("����\n");
							deal(south,4,0);
						}
						if(play!=3){
							if(compair(player,west)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,west)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,west)==2)
								printf("����\n");
							deal(west,4,0);
						}
						if(play!=4){
							if(compair(player,east)==1){
								count++;
								printf("�AĹ�F!\n");
							}
							else if(compair(player,east)==0){
								count--;
								printf("�A��F\n");
							}
							else if(compair(player,east)==2)
								printf("����\n");
							deal(east,4,0);
						}

						printf("�ثe�n��:%d\n",count*score);
						break;



				}
				
				break;
				
		}
		printf("\n(1)���s�}�l\n(2)�~��U�@�^\n(3)�����F\n");
		scanf("%d",&choice);
	
	

}
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
           //   %d \t %5s of %-8s
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
	//deal(Direct,12,0);
	
}
/******************************************************/
int five_card(Card * const wDeck){
	int i,j,count_face=0,count_suit=0,a,count_re=0,b,count=0;
	int type;
	sort_1( wDeck,0,4);
	//printf("�o���i�P:\n");
	//deal(wDeck,4,0);
	for(i=0;i<4;i++){
		for(j=i+1;j<5;j++){

			if(wDeck[i].face_number==wDeck[j].face_number){
				++count_face;

				if(count_face==1){
					a=i;
				}

				if(count_face>=2){
					
						if(wDeck[a].face_number!=wDeck[i].face_number){
							count_face=count_face-1;
							count_re=count_re+1;
						}

					}
			}

			if(wDeck[i].suit_number==wDeck[j].suit_number){
				count_suit++;
			}
			
			
			
			
		}
	}
	for(b=0;b<4;b++){
		if(wDeck[b].face_number == (wDeck[b+1].face_number+1)){
			
			count++;
		}
		

	}
	if(wDeck[0].face_number==13&&(wDeck[0].face_number == (wDeck[4].face_number+12))){
			count++;
		}
		
	if(count_face==0&&count!=4) {
		//printf("���P\n");
		type=1;
	}
	if(count_face==1&&count_re==0){
		//printf("��l\n");
        type=2;
	}
	if(count_re==1&&count_face==1){
		//printf("�G��\n");
		type=3;
	}
	if(count_face==3&&count_re==0){
	    //printf("�T��\n");
		type=4;
	}
	if(count==4&&count_suit!=10){
		//printf("���l\n");
		type=5;
	}
	if(count_suit==10&&count!=4){
		//printf("�P��");
		type=6;
	}
	if(count_re==1&&count_face==3){
		//printf("��Ī\n");
		type=7;
	}
	if(count_face==6&&count_re==0){
		//printf("�|��\n");
		type=8;
	}
	if(count_suit==10&&count==4){
		//printf("�P�ᶶ\n");
		type=9;
	}
	return type;
	
	
}
/*************************************************************/
void sort_2( Card * const wDeck,int start,int end){
	int a,b;
	Card temp;
	
	for( a = start ; a < end ; a++){

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
/*****************************************************/
void swap(Card * const player, Card * const wanted,int self,int want){
	Card temp;
	temp=wanted[want];
	wanted[want]=player[self];
	player[self]=temp;

}
/***********************************************************/
int compair(Card * const player, Card * const opponent){
	int type,i,count=0,j=0,c,d;
	int a,b,count1=0,count2=0;
	if(five_card(player)>five_card(opponent)){
		return 1;
	}
	else if(five_card(player)<five_card(opponent)){
		return 0;
	}
	else if(five_card(player)==five_card(opponent)){
		type=five_card(player);
		if(type==1){
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
		if(type==2){
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //�]���O���ƼƦr�ҥH�@�˪��Ʀr�|�Ʀb�@�_;
					a=player[i].face_number;
				}
				if(opponent[i].face_number==opponent[i+1].face_number){
					b=opponent[i].face_number;
				}
			}
			if(a>b&&b!=1)return 1;
			else if(b==1&&a!=1)return 0;//���l;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;
			else if(a==b){                       //��l�@��->�̧Ǥ�ѤU���Ʀr
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
		if(type==3){
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //�]���O���ƼƦr�ҥH�@�˪��Ʀr�|�Ʀb�@�_;
					a=player[i].face_number;                            //����j����l   
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
			else if(a==b){                           //�p�G���j�����@�ˡA��p����l
				for(i=c+1;i<=4;i++){
					if(player[i].face_number==player[i+1].face_number){    //�]���O���ƼƦr�ҥH�@�˪��Ʀr�|�Ʀb�@�_;
						a=player[i].face_number;                            //����j����l   
					
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
		if(type==4){
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //�]���O���ƼƦr�ҥH�@�˪��Ʀr�|�Ʀb�@�_;
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
		if(type==5){
			if(player[0].face_number>opponent[0].face_number&&opponent[4].face_number!=1)return 1;
			else if(opponent[4].face_number==1&&player[4].face_number!=1)return 0;
			else if(player[0].face_number<opponent[0].face_number&&player[4].face_number!=1)return 0;
			else if(opponent[4].face_number!=1&&player[4].face_number==1)return 1;
			if(player[0].face_number==opponent[0].face_number)return 2;
		}
		if(type==6){
			if(player[0].suit_number>opponent[0].suit_number)return 1;
			else if(player[0].suit_number<opponent[0].suit_number)return 0;
			else if(player[0].suit_number==opponent[0].suit_number){
				if(player[0].face_number>opponent[0].face_number)return 1;
				else if(player[0].face_number<opponent[0].face_number)return 0;

			}
		}
		if(type==7){
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
			else if(b==1&&a!=1)return 0;//���l;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;

		}
		if(type==8){
			for(i=0;i<=4;i++){
				if(player[i].face_number==player[i+1].face_number){    //�]���O���ƼƦr�ҥH�@�˪��Ʀr�|�Ʀb�@�_;
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
		if(type==9){
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

