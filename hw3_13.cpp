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

void fillDeck( Card * const, const char *[], const char *[] ,int [], int [] );	// �]�P��l��
void shuffle( Card * const );									// �~�P
void deal( const Card * const ,int,int);// �C�L�P
void get_card( Card * const, Card * const,int,int );//��P�J�}�C
int five_card(Card * const);//�P�_���i���P��
int three_card(Card * const);//�P�_�T�i���P��
void sort_1( Card * const ,int,int );//���ƼƦr�A�ƪ��
void sort_2( Card * const ,int,int);//���ƪ��A�ƼƦr
int card_13(Card * const);//�ݬO���O�@���s;
void computer_play(Card * const,Card * const,Card * const,Card * const);//�q�����e������k
int counting(Card * const,int,Card * const,int,int,int,int);//��X�̤j���P��
int compair(Card * const, Card * const);//������i�P���j�p
void swap(Card * const, Card * const,int,int);//�洫�P
int compair_three(Card * const, Card * const);//����T�i�P���j�p
void function(Card * const,int,int *, const char *[], const char *[] ,int [], int []);//main�禡���ϥΪ̭��O
void main(){
	Card deck[ 52 ];
   
    const char *face[] = { "Ace", "Deuce", "Three", 
                          "Four", "Five",
                          "Six", "Seven", "Eight", 
                          "Nine", "Ten",
                          "Jack", "Queen", "King"};//��13�ؼƦr
    int face_number[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};//13�ؼƦr���s��

    const char *suit[] = { "Spades","Hearts", "Diamonds", "Clubs" };  //���|�ت��           
    int suit_number[] ={4,3,2,1};//�|�ت�⪺�s��

    int choice,count=0;
	int score;
	printf("�@���n�X��?\n");
	scanf("%d",&score);
	printf("(1)���s�}�l\n(2)�~��U�@�^\n(3)�����F\n");
	scanf("%d",&choice);
	while(choice!=3){                  //��choice�O3�ɴN�O���X�����F!
		switch(choice){
			case 1:
				count=0;    //���s�p��
				function(deck,score,&count,face,suit ,face_number,suit_number);
				
				break;
						
			case 2:
				
				function(deck,score,&count,face,suit ,face_number,suit_number);
				break;
					}
		printf("\n(1)���s�}�l\n(2)�~��U�@�^\n(3)�����F\n");
		scanf("%d",&choice);
}
}
/***********************************************************/
void function(Card * const deck,int score,int *count, const char *face[], const char *suit[] ,int face_number[], int suit_number[]){
	Card north[13],west[13],east[13],south[13];  //�@���|�a���a
	Card north_first[5],north_second[5],north_third[3];  //�_�a���ᤤ�e�[
	Card west_first[5],west_second[5],west_third[3];  //��a���ᤤ�e�[
	Card south_first[5],south_second[5],south_third[3];  //�n�a���ᤤ�e�[
	Card east_first[5],east_second[5],east_third[3];   //�F�a���ᤤ�e�[
	Card player_first[5],player_second[5],player_third[3];//���a���e����[
	int self,want, play;
	int ch,toget,i,first_number,second_number,third_number,a;
	Card wanted[13];//���a�Q�X�@���q��
	Card player[13];//���a

				srand( time( NULL ) );
				fillDeck( deck, face, suit,face_number,suit_number);		// �]�P��l��
				shuffle( deck );
				get_card(deck,north,0,12);//�N0~12�����_�a
				get_card(deck,west,13,25);//�N13~25������a
				get_card(deck,east,26,38);//�N26~38�����F�a
				get_card(deck,south,39,51);//�N39~51�����n�a
				//deal(north,12,0);
				//deal(west,12,0);
				//deal(east,12,0);
				//deal(south,12,0);
				printf("��ܤ@�Ӫ��a���ۤv1 2 3 4\n");
				scanf("%d",&play);//��ܭn1234���@�a
				switch(play){
					case 1:
						printf("�A���P:\n");
						get_card(north,player,0,12);//��Ĥ@�a�N�N�Ĥ@�a�]�����a�æL�X
						sort_2(player,0,12);
						deal(player,12,0);
						
						break;
					case 2:
						printf("�A���P:\n");
						get_card(south,player,0,12);//��ĤG�a�N�N�ĤG�a�]�����a�æL�X
						sort_2(player,0,12);
						deal(player,12,0);
						break;
					case 3:
						printf("�A���P:\n");
						get_card(west,player,0,12);//��ĤT�a�N�N�ĤT�a�]�����a�æL�X
						sort_2(player,0,12);
						deal(player,12,0);
						break;
					case 4:
						printf("�A���P:\n");
						get_card(east,player,0,12);//��ĥ|�a�N�N�ĥ|�a�]�����a�æL�X
						sort_2(player,0,12);
						deal(player,12,0);
						break;
				}
				printf("�n���n���P?(1�n/2���n)\n");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						//���X�@���a
						printf("��ܭn�X�@�����a 1 2 3 4\n");
						scanf("%d",&toget);
						switch(toget){
							case 2:
								get_card(south,wanted,0,12);//��ܲĤ@�a�N�N�Ĥ@�a�]���X�@���a�æL�X�L���P
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								break;
							case 1:
								get_card(north,wanted,0,12);//��ܲĤG�a�N�N�ĤG�a�]���X�@���a�æL�X�L���P
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								break;
							case 4:
								get_card(east,wanted,0,12);//��ܲĤT�a�N�N�ĤT�a�]���X�@���a�æL�X�L���P
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								break;
							case 3:
								get_card(west,wanted,0,12);//��ܲĥ|�a�N�N�ĥ|�a�]���X�@���a�æL�X�L���P
								sort_2(wanted,0,12);
								deal(wanted,12,0);
								
								break;
						}
						printf("��ܦۤv�Q�������P��m�M�Q�����P����m(1/2)�ӤW�����Ƨ�\n");
						scanf("%d/%d",&self,&want);
						swap(player,wanted,self-1,want-1);//���P
						deal(player,12,0);//�L�X�����P�����a
						printf("\n");
						deal(wanted,12,0);//�L�X�����P���X�@���a
						
                        printf("��[\n");//���a�ۤv�ի�[
						for(i=0;i<=4;i++){
							scanf("%d",&first_number);
							player_first[i]=player[first_number-1];
						}
						printf("���[:\n");//���a�ۤv�դ��[
						for(i=0;i<=4;i++){
							scanf("%d",&second_number);
							player_second[i]=player[second_number-1];
						}
						printf("�e�[:\n");//���a�ۤv�իe�[
						for(i=0;i<=2;i++){
							scanf("%d",&third_number);
							player_third[i]=player[third_number-1];
						}
						printf("�A����[:\n");
						deal(player_first,4,0);
						printf("�A�����[:\n");
						deal(player_second,4,0);
						printf("�A���e�[:\n");
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
								computer_play(south,south_first,south_second,south_third);//�F�n��_�a���ۤv���e����[
								computer_play(north,north_first,north_second,north_third);
								computer_play(east,east_first,east_second,east_third);
							}
							else if(play==4){
								computer_play(south,south_first,south_second,south_third);//�F�n��_�a���ۤv���e����[
								computer_play(north,north_first,north_second,north_third);
								computer_play(west,west_first,west_second,west_third);
							}
						
							if(toget!=1&&play!=1){                    //�p�G�Ĥ@�a���O���a��X�@���a
								if(compair(player_first,north_first)==1){//�i���[���
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,north_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,north_first)==2)
									printf("��[����\n");
								deal(north_first,4,0);
								if(compair(player_second,north_second)==1){  //�i�椤�[���
									(*count)++;
									printf("���[�AĹ�F!\n");
								}
								else if(compair(player_second,north_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,north_second)==2)
									printf("���[����\n");
								deal(north_second,4,0);
								if(compair_three(player_third,north_third)==1){//�i��e�[���
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,north_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,north_third)==2)
									printf("�e�[����\n");
								deal(north_third,2,0);
								if(compair(player_first,north_first)==1&&compair(player_second,north_second)==1&&compair_three(player_third,north_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,north_first)==0&&compair(player_second,north_second)==0&&compair_three(player_third,north_third)==0)
									(*count)=(*count)-3;

							}
							//�T�[����O�餻�[�A�T�[��Ĺ�OĹ���[
							
							if(toget!=2&&play!=2){								//�p�G�ĤG�a���O���a��X�@���a
								if(compair(player_first,south_first)==1){      //�i���[���
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,south_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,south_first)==2)
									printf("��[����\n");
								deal(south_first,4,0);
					
						
								if(compair(player_second,south_second)==1){//�i�椤�[���
									(*count)++;
									printf("���[�AĹ�F!\n");
								}	
								else if(compair(player_second,south_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,south_second)==2)
									printf("���[����\n");
								deal(south_second,4,0);
					
					
								if(compair_three(player_third,south_third)==1){//�i��e�[���
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,south_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,south_third)==2)
										printf("�e�[����\n");
								deal(south_third,2,0);
								if(compair(player_first,south_first)==1&&compair(player_second,south_second)==1&&compair_three(player_third,south_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,south_first)==0&&compair(player_second,south_second)==0&&compair_three(player_third,south_third)==0)
									(*count)=(*count)-3;
							}
							//�T�[����O�餻�[�A�T�[��Ĺ�OĹ���[
							
							if(toget!=3&&play!=3){//�p�G�ĤT�a���O���a��X�@���a
								if(compair(player_first,west_first)==1){//�i���[���
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,west_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,west_first)==2)
									printf("��[����\n");
								deal(west_first,4,0);
						
								if(compair(player_second,west_second)==1){//�i�椤�[���
									(*count)++;
									printf("���[�AĹ�F!\n");
								}
								else if(compair(player_second,west_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,west_second)==2)
									printf("���[����\n");
								deal(west_second,4,0);
						
								if(compair_three(player_third,west_third)==1){//�i��e�[���
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,west_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,west_third)==2)
									printf("�e�[����\n");
								deal(west_third,2,0);
								if(compair(player_first,west_first)==1&&compair(player_second,west_second)==1&&compair_three(player_third,west_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,west_first)==0&&compair(player_second,west_second)==0&&compair_three(player_third,west_third)==0)
									(*count)=(*count)-3;
							}
							//�T�[����O�餻�[�A�T�[��Ĺ�OĹ���[
							
							if(toget!=4&&play!=4){//�p�G�ĥ|�a���O���a��X�@���a
								if(compair(player_first,east_first)==1){//�i���[���
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,east_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,east_first)==2)
									printf("��[����\n");
								deal(east_first,4,0);
						
								if(compair(player_second,east_second)==1){//�i�椤�[���
									(*count)++;
									printf("���[�AĹ�F!\n");
								}
								else if(compair(player_second,east_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,east_second)==2)
									printf("���[����\n");
								deal(east_second,4,0);
						
								if(compair_three(player_third,east_third)==1){//�i��e�[���
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,east_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,east_third)==2)
									printf("�e�[����\n");
								deal(east_third,2,0);
								if(compair(player_first,east_first)==1&&compair(player_second,east_second)==1&&compair_three(player_third,east_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,east_first)==0&&compair(player_second,east_second)==0&&compair_three(player_third,east_third)==0)
									(*count)=(*count)-3;
							}
							//�T�[����O�餻�[�A�T�[��Ĺ�OĹ���[
							
							}
						else{
							printf("�A���P�H�W!!���i�H��!!\n");
						
						}
							break;
						
						
						

						
					case 2:
						//�Pcase1�@�˥u�O�S���X�@���a
						printf("��[\n");
						for(i=0;i<=4;i++){
							scanf("%d",&first_number);
							player_first[i]=player[first_number-1];
						}
						printf("���[:\n");
						for(i=0;i<=4;i++){
							scanf("%d",&second_number);
							player_second[i]=player[second_number-1];
						}
						printf("�e�[:\n");
						for(i=0;i<=2;i++){
							scanf("%d",&third_number);
							player_third[i]=player[third_number-1];
						}
						printf("�A����[:\n");
						deal(player_first,4,0);
						printf("�A�����[:\n");
						deal(player_second,4,0);
						printf("�A���e�[:\n");
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
								computer_play(south,south_first,south_second,south_third);//�F�n��_�a���ۤv���e����[
								computer_play(north,north_first,north_second,north_third);
								computer_play(east,east_first,east_second,east_third);
							}
							else if(play==4){
								computer_play(south,south_first,south_second,south_third);//�F�n��_�a���ۤv���e����[
								computer_play(north,north_first,north_second,north_third);
								computer_play(west,west_first,west_second,west_third);
							}
							if(play!=1){
								if(compair(player_first,north_first)==1){
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,north_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,north_first)==2)
									printf("��[����\n");
								deal(north_first,4,0);
						
								if(compair(player_second,north_second)==1){
									(*count)++;
									printf("���[�AĹ�F!\n");
								}
								else if(compair(player_second,north_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,north_second)==2)
									printf("���[����\n");
								deal(north_second,4,0);
						
					
								if(compair_three(player_third,north_third)==1){
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,north_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,north_third)==2)
									printf("�e�[����\n");
								deal(north_third,2,0);
								if(compair(player_first,north_first)==1&&compair(player_second,north_second)==1&&compair_three(player_third,north_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,north_first)==0&&compair(player_second,north_second)==0&&compair_three(player_third,north_third)==0)
									(*count)=(*count)-3;
							}
							

							if(play!=2){
								if(compair(player_first,south_first)==1){
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,south_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,south_first)==2)
									printf("��[����\n");
								deal(south_first,4,0);
						
						
								if(compair(player_second,south_second)==1){
									(*count)++;
									printf("���[�AĹ�F!\n");
								}
								else if(compair(player_second,south_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,south_second)==2)
									printf("���[����\n");
								deal(south_second,4,0);
						
						
								if(compair_three(player_third,south_third)==1){
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,south_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,south_third)==2)
									printf("�e�[����\n");
								deal(south_third,2,0);
								if(compair(player_first,south_first)==1&&compair(player_second,south_second)==1&&compair_three(player_third,south_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,south_first)==0&&compair(player_second,south_second)==0&&compair_three(player_third,south_third)==0)
									(*count)=(*count)-3;
							}
							
							if(play!=3){
								if(compair(player_first,west_first)==1){
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,west_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,west_first)==2)
									printf("��[����\n");
								deal(west_first,4,0);
						
						
								if(compair(player_second,west_second)==1){
									(*count)++;
									printf("���[�AĹ�F!\n");
								}
								else if(compair(player_second,west_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,west_second)==2)
									printf("���[����\n");
								deal(west_second,4,0);
						
						
								if(compair_three(player_third,west_third)==1){
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,west_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,west_third)==2)
									printf("�e�[����\n");
								deal(west_third,2,0);
								if(compair(player_first,west_first)==1&&compair(player_second,west_second)==1&&compair_three(player_third,west_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,west_first)==0&&compair(player_second,west_second)==0&&compair_three(player_third,west_third)==0)
									(*count)=(*count)-3;
							}
							
							if(play!=4){
								if(compair(player_first,east_first)==1){
									(*count)++;
									printf("��[�AĹ�F!\n");
								}
								else if(compair(player_first,east_first)==0){
									(*count)--;
									printf("��[�A��F\n");
							    
								}
								else if(compair(player_first,east_first)==2)
									printf("��[����\n");
								deal(east_first,4,0);
								if(compair(player_second,east_second)==1){
									(*count)++;
									printf("���[�AĹ�F!\n");
								}
								else if(compair(player_second,east_second)==0){
									(*count)--;
									printf("���[�A��F\n");
							    
								}
								else if(compair(player_second,east_second)==2)
									printf("���[����\n");
								deal(east_second,4,0);
								if(compair_three(player_third,east_third)==1){
									(*count)++;
									printf("�e�[�AĹ�F!\n");
								}
								else if(compair_three(player_third,east_third)==0){
									(*count)--;
									printf("�e�[�A��F\n");
							    
								}
								else if(compair_three(player_third,east_third)==2)
									printf("�e�[����\n");
								deal(east_third,2,0);
								if(compair(player_first,east_first)==1&&compair(player_second,east_second)==1&&compair_three(player_third,east_third)==1)
									(*count)=(*count)+3;
								else if(compair(player_first,east_first)==0&&compair(player_second,east_second)==0&&compair_three(player_third,east_third)==0)
									(*count)=(*count)-3;
							}
							
							}
						else{
							printf("�A���P�H�W!!���i�H��!\n");
							
						}

						break;
							
						
						}
						
						printf("�ثe�n��:%d",(*count) * score);
						
						

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
	for(i=0;i<4;i++){         //�Ҧ���ⱡ�p���Ҽ{�L�@�M
		for(j=i+1;j<5;j++){

			if(wDeck[i].face_number==wDeck[j].face_number){//�Ʀr���ۦP�����ưO��
				++count_face;

				if(count_face==1){
					a=i;//�O��i�H�K�᭱�ˬd�ɥi�H�ϥ�
				}

				if(count_face>=2){ //ex:11223�o�بҤlcount_face�|�⦨2
					
						if(wDeck[a].face_number!=wDeck[i].face_number){//�ˬd���S����11223�o�ر��p�n�O���N�Ncount_face��@�A�_�h�|���ƭp��
							count_face=count_face-1;
							count_re=count_re+1;//count_re�O�p�����ӹ�l��11223�N�O�o�ر��p�o�˴N�i�H�P�_���X�ӹ�l
						}

					}
			}

			if(wDeck[i].suit_number==wDeck[j].suit_number){
				count_suit++;//�����ۦP�ɪ��O��
			}
			
			
			
			
		}
	}
	for(b=0;b<4;b++){
		if(wDeck[b].face_number == (wDeck[b+1].face_number+1)){
			
			count++;//�]���O�Υ��ƼƦr�A�ƪ��A�o�O�b�ݶ��l
		}
		

	}
	if(wDeck[0].face_number==13&&(wDeck[0].face_number == (wDeck[4].face_number+12))){
			count++;//�]����ace�Aking...�]�O���l
		}
		
	if(count_face==0&&count!=4) {//���P
		
		type=1;
	}
	if(count_face==1&&count_re==0){//��l
		
        type=2;
	}
	if(count_re==1&&count_face==1){//�G��
		
		type=3;
	}
	if(count_face==3&&count_re==0){//�T��
	    
		type=4;
	}
	if(count==4&&count_suit!=10){//���l
		
		type=5;
	}
	if(count_suit==10&&count!=4){//�P��
		
		type=6;
	}
	if(count_re==1&&count_face==3){//��Ī
		
		type=7;
	}
	if(count_face==6&&count_re==0){//�|��
		
		type=8;
	}
	if(count_suit==10&&count==4){//�P�ᶶ
		
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
			if(wDeck[i].face_number==wDeck[j].face_number){//�Ʀr���ۦP�����ưO��
				count++;
			}
			if(wDeck[i].suit_number==wDeck[j].suit_number){//�����ۦP�ɪ��O��
				count_suit++;
			}
		}
	}

	switch(count){
		case 0://���P
			
			type=1;
			break;
		case 1://��l
			
			type=2;
			break;
		case 3://�T��
			
			type=4;
			break;
		default:
			break;
	}
	if(count_suit==3)//�P��
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
		if(wDeck[i].face_number==(wDeck[i+1].face_number+1)){//�ˬd�O���O1~13����
			count++;
		}
	}
	if(count==12){//�@���s
		
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
	for(i=9;i>=0;i--){                      //���[
		if(counting(Direct,i,first,8,10,10,0)==1)
			break;
	}
	
	for(j=0;j<=12;j++){//first�ιL���P���i�H�A��
		if(j==remain[0]||j==remain[1]||j==remain[2]||j==remain[3]||j==remain[4]){//remain�O�O���X���P�bdirect�̪���m
			continue;
		}
		temp[a]=Direct[j];
		a++;
	}
	
	
	for(i=type_mem;i>=0;i--){                //�䤤�[�A���O���i�H���[�j�ҥH�q�p���[�����A�}�l��
		if(counting(temp,i,second,3,5,5,0)==1)
			break;
	}
	for(j=0;j<=7;j++){//second�ιL���P���i�H�A��
		if(j==remain[0]||j==remain[1]||j==remain[2]||j==remain[3]||j==remain[4]){//remain�O�O���X���P�bdirect�̪���m
			continue;
		}
		third[b]=temp[j];
		b++;
	}



}
int counting(Card * const Direct,int type,Card * const Place,int ii,int jj,int kk,int x)//��M�̾A�X���P��
{
	int i,j,k,h,w,count=0,count_array=0;
	Card temp[5];
	for(i=x;i<=ii;i++){        //�]���P���i��
		for(j=i+1;j<=jj;j++){
			for(k=j+1;k<=kk;k++){
				h=k+1;
				w=h+1;
				s=i;
				temp[0]=Direct[i];//�N�]��i�઺���e��Jtemp��
				temp[1]=Direct[j];
				temp[2]=Direct[k];
				temp[3]=Direct[h];
				temp[4]=Direct[w];
				if(five_card(temp)==type){//�p�Gtemp��type�O��n����ǤJ��type
					if(count_array!=1){ //���̤j���N���n�A��F!
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
	if(five_card(player)>five_card(opponent)){ //�p�G���a����j�N�^��1
		return 1;						  
	}									
	else if(five_card(player)<five_card(opponent)){//�p�G������j�N�^��0
		return 0;
	}
	else if(five_card(player)==five_card(opponent)){//�ݨ�Ӥ�����Ptype�O�_�@�ˤ@�˴N����䤤���Ʀr
		type=five_card(player);
		if(type==1){//�p�G�������P���ܤ�Ʀr
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
		if(type==2){//�p�G������l�N���l�j�p�A�p�G��l�j�p�ۦP���ܡA�̧Ǥ���t�~���X�i�P
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
		if(type==3){//�p�G���O��諸�ܡA����j����l�A�A��p����l�A���P���ܡA��t�~�����i�P�C  

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
		if(type==4){//�p�G���O�T���N����T�����Ʀr
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
		if(type==5){//�Y���O���l���ܴN��Ĥ@�i�]�����̷ӼƦr�Ʀn�F!�p�G�̫�@�i���O1���ܴN������Ĥ@�i���j�p�A�p�G�̫�@�i�O1���ܴN�N��L�O�̤j�����ƶ��l
			if(player[0].face_number>opponent[0].face_number&&opponent[4].face_number!=1)return 1;
			else if(opponent[4].face_number==1&&player[4].face_number!=1)return 0;
			else if(player[0].face_number<opponent[0].face_number&&player[4].face_number!=1)return 0;
			else if(opponent[4].face_number!=1&&player[4].face_number==1)return 1;
			if(player[0].face_number==opponent[0].face_number)return 2;
		}
		if(type==6){//�p�G���O�P��N����Ĥ@�i���j�p�A�n�O��ⳣ�@�˪��ܴN��Ĥ@�i���Ʀr�A�]�����Ʀn�F
			if(player[0].suit_number>opponent[0].suit_number)return 1;
			else if(player[0].suit_number<opponent[0].suit_number)return 0;
			else if(player[0].suit_number==opponent[0].suit_number){
				if(player[0].face_number>opponent[0].face_number)return 1;
				else if(player[0].face_number<opponent[0].face_number)return 0;

			}
		}
		if(type==7){//���O��Ī���ܴN����T���Ʀr�j�p
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
			else if(b==1&&a!=1)return 0;//��T��;
			else if(a<b&&a!=1)return 0;
			else if(a==1&&b!=1)return 1;

		}
		if(type==8){//���O�|���N����|�����Ʀr�j�p
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
		if(type==9){//���O�P�ᶶ�N����Ĥ@�i�ݽ֤j
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

void swap(Card * const player, Card * const wanted,int self,int want){//�洫
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
		if(type==1){//�p�G�������P���ܤ�Ʀr
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
		if(type==2){//�p�G������l�N���l�j�p�A�p�G��l�j�p�ۦP���ܡA�̧Ǥ���t�~���X�i�P
				for(i=0;i<=2;i++){
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
		if(type==4){//�p�G���O�T���N����T�����Ʀr
			if(player[0].face_number>opponent[0].face_number&&opponent[0].face_number!=1)
						return 1;
					
			else if(opponent[0].face_number==1&&player[0].face_number!=1)
						return 0;
					
			else if(opponent[0].face_number>player[0].face_number&&player[0].face_number!=1)
						return 0;
					
			else if(player[0].face_number==1&&opponent[0].face_number!=1)
						return 1;
			
		}
		if(type==6){//�p�G���O�P��N����Ĥ@�i���j�p�A�n�O��ⳣ�@�˪��ܴN��Ĥ@�i���Ʀr�A�]�����Ʀn�F
			if(player[0].suit_number>opponent[0].suit_number)return 1;
			else if(player[0].suit_number<opponent[0].suit_number)return 0;
			else if(player[0].suit_number==opponent[0].suit_number){
				if(player[0].face_number>opponent[0].face_number)return 1;
				else if(player[0].face_number<opponent[0].face_number)return 0;
			}
		}
	}

}
