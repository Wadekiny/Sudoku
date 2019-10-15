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

//改变字体颜色
void setColor(unsigned short ForeColor=7,unsigned short BackGroundColor=0);

//全局变量
int a[9][9]={0};
int judge_color[9][9]={0};

//输入输出函数 
void output();
void input();

//判断函数 
bool judge(int x,int y,int number);


//递归函数  
int caculate(int i,int j);
//主函数 
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
	//如果越界 跳出 返回 1  
	if(i==9){
		return 1;
	}
	//判断是否填入 是则 ++ 越界跳出  
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
	//遍历1-9依次填入数组某元素 
	for(x=1;x<=9;x++){
		if(judge(i,j,x)==true){
			a[i][j]=x;            //填入数组 
			
			//判断下一个 
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
	//某步返回值不为 1 ，置 0 
	a[i][j]=0;
	return 0;
}

bool judge(int x,int y,int number){
	//判断行 
	int i,j;
	for(j=0;j<9;j++){
		if(a[x][j]==number){
			return false;
		}
	}
	//判断列 
	for(i=0;i<9;i++){
		if(a[i][y]==number){
			return false;
		}
	}
	//判断九宫格 
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
	//获取当前窗口句柄
	 HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	//设置颜色
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

