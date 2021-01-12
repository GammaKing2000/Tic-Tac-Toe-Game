#include<iostream>
using namespace std;

void display(int, int);
int gameBegin();
int pointCheck();
char mat[3][3];
int points[3][3], flag, count=0;

int main()
{
	char pla1[50], pla2[50];
	int winner; 
	char ch='n';
	do
	{
		cout<<"*********************************************************************************************"<<endl;
		cout<<"========   ========     ===         ========    ||       ===       ========   ()()   ||====  "<<endl;
		cout<<"   ||         ||       =   =           ||      |  |     =   =         ||     ()  ()  ||      "<<endl;
		cout<<"   ||         ||      =        ===     ||     |====|   =       ===    ||    ()    () ||==    "<<endl;
		cout<<"   ||         ||       =   =           ||    |      |   =   =         ||     ()  ()  ||      "<<endl;
		cout<<"   ||      ========     ===            ||   |        |   ===          ||       ()    ||====  "<<endl;
		cout<<"*********************************************************************************************"<<endl;
		cout<<"**maximize window for best experience**\n\n";
		cout<<"\nEnter player 1's name: ";
		gets(pla1);
		cout<<"\nEnter player 2's name: ";
		gets(pla2);
		cout<<"\nbelow are the board coordinates:\n";
		for(int i=0; i<3; i++)
		{
			for(int j=0;j<3; j++)
			{
				if(j<2)
					cout<<" ("<<i<<","<<j<<") |";
			    else
			    	cout<<" ("<<i<<","<<j<<")";
			    mat[i][j]='~';
			}
			if(i<2)
				cout<<"\n_______|_______|_______\n";
		}
		cout<<"\nEnter coordinates like this-> 0 0 or 2 1 (just enter the values with a space between them)\n\n";
		winner = gameBegin();
		if(winner==1)
			cout<<"winner is "<<pla1<<" !!!";
		else if(winner==2)
			cout<<"winner is "<<pla2<<" !!!";
		else
			cout<<"IT'S A TIE!";
		cout<<"\n\nDo you want to play again?(y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;	
}

int gameBegin()
{
	int x, y, winner=0;
	do
	{
		
		retry1:
		cout<<"\nPlayer 1, enter your desired coordinates: ";
		cin>>x>>y;
		flag=0;
		if(mat[x][y]=='~')
			display(x, y);
		else
		{
			cout<<"\nThat place is already filled!!! Try again";
			goto retry1;
		}
		winner = pointCheck();
		if (winner==1)
			break;
		count++;
		if(count==9)
			break;
		retry2:
		cout<<"\nPlayer 2, enter your desired coordinates: ";
		cin>>x>>y;
		flag=1;
		if(mat[x][y]=='~')
			display(x, y);
		else
		{
			cout<<"\nThat place is already filled!!! Try again";
			goto retry2;
		}
		winner=pointCheck();
		count++;
		if(count==9)
			break;
	}while(winner==0);
	return winner;
	
}
void display(int x, int y)
{
	if (flag==0)
	{
	    mat[x][y] = 'O';
	    points[x][y]=79;
	}
	else if(flag==1)
	{
		mat[x][y]='X';
		points[x][y]=88;
	}
	cout<<"\n";
	for(int i=0; i<3; i++)
		{
			for(int j=0;j<3; j++)
			{
				if(j<2)
					cout<<" "<<mat[i][j]<<" |";
			    else
			    	cout<<" "<<mat[i][j];
			}
			if(i<2)
				cout<<"\n___|___|___\n";
		}
	cout<<"\n   |   |   \n";
}

int pointCheck()
{
	//player 1 wins when points==237
	//player 2 wins when points==264
	int row=0, col=0;
	//row sum
	for(int i=0; i<3;i++)
	{
		row = points[i][0]+points[i][1]+points[i][2];
		if(row==237)
			return 1;
		else if(row==264)
			return 2;		
	}
	//daigonal sum
	if(points[0][0]+points[1][1]+points[2][2]==237||points[2][0]+points[1][1]+points[0][2]==237)
		return 1;
	else if(points[0][0]+points[1][1]+points[2][2]==264||points[2][0]+points[1][1]+points[0][2]==264)
		return 2;
	for(int i=0; i<3;i++)
	{
		col = points[0][i]+points[1][i]+points[2][i];
		if(col==237)
			return 1;
		else if(col==264)
			return 2;		
	}
	return 0;
}

