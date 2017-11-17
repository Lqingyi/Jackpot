#include<iostream>
#include<cstdlib>
#include<ctime>

#define random(b) (rand()%b+1)

using namespace std;

void start();
void timescounter();

char d=1;
int times=6;
int temp=0;
int randnum=0;

int main()
{
	cout<<"Jackpot is a game."<<endl;
	cout<<"You should try to guess a nubmer,and you have only six chances!"<<endl;
	cout<<"Have fun."<<endl;
	start();
	return 0;
}

void start()
{
	d=1;
	srand((unsigned)time(NULL));
	cout<<"Choose difficulty:"<<endl;
	cout<<"  ESAY(1~20) input'1'"<<endl;
	cout<<"MIDDLE(1~40) input'2'"<<endl;
	cout<<"  HARD(1~60) input'3'"<<endl;
	cout<<"input other key to exit the game!"<<endl;
	cin>>d;
	switch (d)
	{
	case '1':randnum=random(20);break;
	case '2':randnum=random(40);break;
	case '3':randnum=random(60);break;
	default:exit(0);
	}
	timescounter();
}

void timescounter()
{
	if(times<=0)
	{
		cout<<"You Lose!"<<endl;
		start();
	}
	else
	{
		cout<<times<<"times left!"<<endl;
		cout<<"Your number:"<<endl;
		cin>>temp;
		if(temp>=1&&temp<=((int)d*20))
		{
			if(temp==randnum)
			{
				cout<<"You Win!"<<endl;
				start();
			}
			else if(temp>randnum)
			{
				cout<<"Your number is to big!"<<endl;
				--times;
				timescounter();
			}
			else
			{
				cout<<"Your number is to small!"<<endl;
				--times;
				timescounter();
			}
		}
		else
		{
			cout<<"You number is out of range!"<<endl;
			cout<<"Please try a new number."<<endl;
			timescounter();
		}
	}	
}
