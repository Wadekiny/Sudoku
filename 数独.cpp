/*
0 0 5 0 0 2 0 0 0
0 0 0 0 0 1 0 4 0
4 1 0 0 5 9 0 6 0
0 0 8 0 0 0 0 7 0
3 7 0 0 0 0 0 9 4
0 4 0 0 0 0 6 0 0
0 3 0 8 2 0 0 1 5
0 9 0 3 0 0 0 0 0
0 0 0 9 0 0 4 0 0
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>
using namespace std;

//�ı�������ɫ
void setColor(unsigned short ForeColor=7,unsigned short BackGroundColor=0);

//ȫ�ֱ���
int a[9][9]={0};
int judge_color[9][9]={0};

//����������� 
void output();
void input();

//�жϺ��� 
bool judge(int x,int y,int number);


//�ݹ麯��  
int caculate(int i,int j);
//������ 
int main()
{
	cout<<"Please input the question\n\n";
	output();
	input();
	memcpy(judge_color,a,sizeof(a));
	cout<<"\n\tAnswer\n\n"; 
	caculate(0,0);
	output();
	cout<<endl;
	system("pause");
	return 0;
} 


int caculate(int i,int j){
	int x;
	//���Խ�� ���� ���� 1  
	if(i==9){
		return 1;
	}
	//�ж��Ƿ����� ���� ++ Խ������  
	while(a[i][j]!=0){
		if(j==8){
			i++;
			j=0;
		}else{
			j++;
		}
		if(i==9){
			return 1;
		}
	}
	//����1-9������������ĳԪ�� 
	for(x=1;x<=9;x++){
		if(judge(i,j,x)==true){
			a[i][j]=x;            //�������� 
			
			//�ж���һ�� 
			if(j==8){
				if(caculate(i+1,0)){
					return 1;         
				}
			}else{
				if(caculate(i,j+1)){
					return 1;
				}
			}
			
		}
	}
	//ĳ������ֵ��Ϊ 1 ���� 0 
	a[i][j]=0;
	return 0;
}

bool judge(int x,int y,int number){
	//�ж��� 
	int i,j;
	for(j=0;j<9;j++){
		if(a[x][j]==number){
			return false;
		}
	}
	//�ж��� 
	for(i=0;i<9;i++){
		if(a[i][y]==number){
			return false;
		}
	}
	//�жϾŹ��� 
	if(x<=2){
		if(y<=2){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}else if(y<=5){
			for(i=0;i<3;i++){
				for(j=3;j<6;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		
		}else if(y<=8){
			for(i=0;i<3;i++){
				for(j=6;j<9;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}
	}else if(x<=5){
		if(y<=2){
			for(i=3;i<6;i++){
				for(j=0;j<3;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}else if(y<=5){
			for(i=3;i<6;i++){
				for(j=3;j<6;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}else if(y<=8){
			for(i=3;i<6;i++){
				for(j=6;j<9;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}
	}else if(x<=8){
		if(y<=2){
			for(i=6;i<9;i++){
				for(j=0;j<3;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}else if(y<=5){
			for(i=6;i<9;i++){
				for(j=3;j<6;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}else if(y<=8){
			for(i=6;i<9;i++){
				for(j=6;j<9;j++){
					if(a[i][j]==number){
						return false;
					}
				}
			}
		}
	}
	return true;
}

void output(){
	int i,j; 
	for(i=0;i<9;i++){
		cout<<" ";
		for(j=0;j<9;j++){
			 setColor(15);
			if(judge_color[i][j]){
				 setColor(14);
			}
			cout<<a[i][j]<<" ";
			 setColor(7);
			if(j==8){
				cout<<endl;
			}
			if((j+1)%3==0 && j!=8){
				cout<<"| ";
			}
		}
		if((i+1)%3==0 && i!=8){
			 setColor(7);
			cout<<"------- ------- -------"<<endl;
		} 
	}
}

void setColor(unsigned short ForeColor,unsigned short BackGroundColor){
	//��ȡ��ǰ���ھ��
	 HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	//������ɫ
	 SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);
}

void input(){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cin>>a[i][j];
			system("cls");
			output();
		} 
	}
	system("cls");
	cout << "\tQUESTION" << endl << endl;
	output();
}

