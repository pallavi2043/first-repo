#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int GetPlayerToss(char player1[],char player2[],int oversToplay);
int batting(char battingplayer[],char bowlingplayer[],int oversToplay);
int main()
{
 int i,j,overs,noovers,player1Toss,player2Toss;
 char player1[50],player2[50];
 srand(time(NULL));
 cout<<"-----------------------------------WELCOME TO HAND CRICKET GAME-------------------------------------\n";
 cout<<"Enter Player 1 Name:";
 fflush(stdin);
 gets(player1);
 printf("Enter Player 2 Name:");
 fflush(stdin);
 gets(player2);
 cout<<"Enter\n1 - Fixed Overs\n2 - Play Until Out\n3 - How to Play?\n4 - Exit: ";
 cin>>noovers;
  do{
 if(noovers==1)
 {
  cout<<"Enter No Of Overs: ";
  cin>>overs;
  player1Toss=GetPlayerToss(player1,player2,overs); 
  
 }
 else if(noovers==2)
 {
  player1Toss=GetPlayerToss(player1,player2,0);
 }
 else if(noovers==3)
 {
  cout<<"How To Play?\n";
  cout<<"Until a player Won the toss Follow the Output and give whatever it asks you to give\n";
  cout<<"Then the Player who won the toss chooses either to Bat or to Bowl\n";
  cout<<"The Player who chose batting and bowling has to proceed by pressing enter Key one by one\n";
  cout<<"Where System will generate Random number as runs for both players.Player 1 runs keeps on adding until his runs equals to player 2 runs\n";
  cout<<"Finally When Player 1 is Out.Till then his runs are his final Score.The Same process will be Conducted for player 2.\n";
  cout<<"Finally whoever is having Highest Score is the Winner.\n\n";
  cout<<"For Example: Player 1 Won the Toss And Chose Batting.Then When Player 1 Press Enter Key,A score will be generated for Player 1\n";
  cout<<"Suppose runs are 5 So Player 1 Score=5.Then Player 2 Also Presses Enter key.Then if he got a Score of 4.So Player 2 Score =4\n";
  cout<<"As Player 1 Score is not equal to player 2 Score Then Player 1 is not out and hi score will be 5 after 1st ball \n";
  cout<<"In 2nd ball Player 1 got 3 runs and Player 2 got 4.Since again both are not equal.Player 1 Score=5+3=8\n";
  cout<<"If in the 3rd Ball Player 1 got 4 runs and Player 2 also got 4 runs Then Player 1 Score is equal to Player 2's Score Then Player 1 is Out\n";
  cout<<"Then Final Score of player 1 is 8 runs.\n";
  cout<<"The Same Process is done for Player 2.So Finaly who ever got more score is Winner\n";
 }
 else
 {
  cout<<"--------------------------------------------Invalid Choice--------------------------------------------\n";
 }
 cout<<"Enter 1 - Fixed Overs\n2 - Play Until Out\n3 - How to Play?\n4 - Exit: ";
 cin>>noovers;
  }while(noovers>=1 && noovers<=3);
 return(0);
}

int GetPlayerToss(char player1[],char player2[],int oversToplay)
{
 int player1Choice,player2Choice,toss,player1Toss,batorbowlChoice,player2Score,player1Score;
     cout<<player1;
     cout<<" Choose your choice either 1 for head or 2 for tail: ";
  cin>>player1Choice;
  if(player1Choice==1)
  {
   player2Choice=2;
   cout<<player2<<" Choice is Tail\n";
  }
  else if(player1Choice==2)
  {
   player2Choice=1;
   cout<<player2<<"Choice is Head\n";
  }
  else
  {
   cout<<"--------------------------------------------Invalid Choice--------------------------------------------\n";
   return(0);
  }
  toss=rand()%2;
  toss=toss+1;
  if(toss==1)
  cout<<"Toss is Head\n";
  else
  cout<<"Toss is Tail\n";
  if(toss==player1Choice)
  {
   player1Toss=1;
   cout<<"Player 1 "<<player1<<"Won the Toss\n";
   cout<<"Choose\n1 - Batting\n2 - Bowl: ";
   cin>>batorbowlChoice;
   if(batorbowlChoice==1)
   {
        cout<<"----------------"<<player1<<" is Going to bat Now-----------------------\n";
    player1Score=batting(player1,player2,oversToplay);
cout<<"----------------"<<player2<<" is Going to bat Now-----------------------\n";
    player2Score=batting(player2,player1,oversToplay);
    cout<<"----------------Its Time for Results-----------------------\n";
   }
   else
   {
    cout<<"----------------"<<player2<<" is Going to bat Now-----------------------\n";
    player2Score=batting(player2,player1,oversToplay);
cout<<"----------------"<<player1<<" is Going to bat Now-----------------------\n";
    player1Score=batting(player1,player2,oversToplay);
    cout<<"----------------Its Time for Results-----------------------\n";
   }
  }
  else if(toss==player2Choice)
  {
   player1Toss=2;
   cout<<"Player 2 "<<player2<<" Won the Toss\n";
cout<<"Choose\n1 - Batting\n2 - Bowl: ";
   cin>>batorbowlChoice;
   if(batorbowlChoice==1)
   {
    cout<<"----------------"<<player2<<" is Going to bat Now-----------------------\n";
    player2Score=batting(player2,player1,oversToplay);
    cout<<"----------------"<<player1<<" is Going to bat Now-----------------------\n";
    player1Score=batting(player1,player2,oversToplay);
cout<<"----------------Its Time for Results-----------------------\n";
   }
   else
   {
    cout<<"----------------"<<player1<<" is Going to bat Now-----------------------\n";
    player1Score=batting(player1,player2,oversToplay);
    cout<<"----------------"<<player2<<" is Going to bat Now-----------------------\n";
    player2Score=batting(player2,player1,oversToplay);
    cout<<"----------------Its Time for Results-----------------------\n";
   }
  }
  else
  {
   cout<<"------------------------------------------------Error-------------------------------------------------\n";
   return(0);
  }
  if(player1Score==player2Score)
  {
   cout<<"Draw Match\nThanks For Playing the Game\n";
  }
  if(player1Score>player2Score)
  cout<<player1<<" Won the Match\nThanks for Playing the Game\n";
  if(player1Score<player2Score)
  cout<<player2<<" Won the Match\nThanks for Playing the Game\n";
  return(player1Toss);
}

int batting(char battingplayer[],char bowlingplayer[],int oversToplay)
{
 int i,j,battingScore,sum=0,bowlerSocre,flag=1;
 char c;
 if(oversToplay>0)
 {
  for(i=1;i<=oversToplay;i++)
  {
   for(j=1;j<=6;j++)
   {
    cout<<i<<j<<"ball\n";
    cout<<bowlingplayer<<" Press Enter key to bowl :";
    fflush(stdin);
    cin>>c;
    fflush(stdin);
    bowlerSocre=(int)rand()%7;//Generate from 0-6 where 0 means no ball
    cout<<battingplayer<<" Press Enter key to bat :";
    fflush(stdin);
    cin>>c;
    fflush(stdin);
    battingScore=rand()%7;//Generate 0-6 runs
    if(battingScore==bowlerSocre)
    {
     flag=0;
     cout<<"-----------------"<<battingplayer<<" is Out----------------\n";
     cout<<battingplayer<<" Total Score="<<sum<<"\n";
     if(sum==0)
            cout<<"-----------Hehehe Duck Out-----------------\n";
     break;
    }
    else
    {
    cout<<"Got "<<battingScore<<"runs\n";
                    if(battingScore==6)
                    cout<<"Sixerrrrrr Keep it Up\n";
                    if(battingScore==4)
            cout<<"Its a Four Great Man\n";
     sum=sum+battingScore;
     cout<<battingplayer<<" Score="<<sum<<"\n";
    }
   }
   if(flag==0)
   break;
  }
 
  return(sum);
 }
   if(oversToplay==0)
   {
      while(flag)
      {
        cout<<bowlingplayer<<" Press Enter key to bowl :";
  fflush(stdin);
  cin>>c;
  fflush(stdin);
  bowlerSocre=(int)rand()%7;//Generate from 0-6 where 0 means no ball
  cout<<battingplayer<<"Press Enter key to bat :";
  fflush(stdin);
  cin>>c;
  fflush(stdin);
  battingScore=rand()%7;//Generate 0-6 runs
  if(battingScore==bowlerSocre)
  {
   flag=0;
   cout<<"-----------------"<<battingplayer<<"is Out----------------\n";
   cout<<battingplayer<<" Total Score="<<sum;
   if(sum==0)
   cout<<"-----------Hehehe Duck Out-----------------\n";
   break;
  }
  else
  {
   cout<<battingScore<<"Got "<<sum<<" runs\n";
            if(battingScore==6)
            cout<<"Sixerrrrrr Keep it Up\n";
            if(battingScore==4)
       cout<<"Its a Four Great Man\n";
   sum+=battingScore;
   cout<<battingplayer<<" Score="<<sum;
  }
      }
      return(sum);
   }
 
}