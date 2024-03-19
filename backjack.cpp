#include <bits/stdc++.h>
using namespace std;

map<int,string> card={
     {1, "A"},
     {2, "2"},
     {3, "3"},
     {4, "4"},
     {5, "5"},
     {6, "6"},
     {7, "7"},
     {8, "8"},
     {9, "9"},
     {10, "10"},
     {11, "J"},
     {12, "Q"},
     {13, "K"},
};
int main(){
    srand(time(NULL));
    int n;
    int coin=10000;
    while(coin>=1000){
        int roundcoin;
        cout << "Your Coins : " << coin << "$" << "\n\n" << "How much do you want to bet? : ";
        while(true){
            cin >> roundcoin;
            if(roundcoin>=1000&&roundcoin<=coin){
                break;
            }
            if(roundcoin<1000){
                cout << "A bet must be larger than 1000$ : ";
            }
            else{
                cout << "bet something you can afford! : ";
            }
        }
        coin-=roundcoin;
        int roundcards[10]={};
        int dcards[14]={};
        for(int i=0; i<2; i++){
            int a=rand()%13+1;
            if(dcards[a]<4){
                roundcards[i]=rand()%13+1;
                dcards[a]++;
            }
            else i--;
        }
        cout << "\n" << "Your Cards:\n\n   " << card[roundcards[0]] << "  " << card[roundcards[1]];
        int choice,total=0;
        for(int a:roundcards){
            if(a>10) total+=10;
            else total+=a;
        }
        if(total==11){
            cout << "\n\n" << "You Win!\n\n";
            coin+=2*roundcoin;
            continue;
        }
        cout << "\n\nDo you want to add cards? ( press 0 for no and 1 for yes ) : ";
        while(cin >> choice && choice==1){
            total=0;
            for(int i=0; i<10; i++){
                if(roundcards[i]==0){
                    for(int j=0; j<1; j++){
                        int a=rand()%13+1;
                        if(dcards[a]<4){
                            roundcards[i]=a;
                            dcards[a]++;
                        }
                        else j--;
                    }
                    break;
                }
            }
            for(int a:roundcards){
                if(a>10) total+=10;
                else total+=a;
            }
            cout << "\nYour Cards:\n\n   ";
            for(int a:roundcards){
            if(a!=0) cout << card[a] << "  ";
            }
            cout << "\n\n";
            if(total<=21){
                 cout << "Do you want to add cards? ( press 0 for no and 1 for yes ) : ";
            }
            else{
                cout << "You Lose!\n\n";
                break;
            }
        }
        if(total>21){
            continue;
        }
        int robot[10]={};
        for(int i=0; i<2; i++){
            int a=rand()%13+1;
            if(dcards[a]<4){
                robot[i]=a;
                dcards[a]++;
            }
            else i--;
        }
        int robottotal=0;
        for(int a:robot){
            if(a>10) robottotal+=10;
            else robottotal+=a;
        }

        while(robottotal<17&&robottotal!=11){
            for(int i=0; i<10; i++){
                if(robot[i]==0){
                    for(int j=0; j<1; j++){
                        int a=rand()%13+1;
                        if(dcards[a]<4){
                            robot[i]=a;
                            dcards[a]++;
                            robottotal+=a;
                        }
                        else j--;
                    }
                    break;
                }
            }
        }
        cout << "\nOpponent Cards:\n\n   ";
        for(int a:robot){
            if(a!=0) cout << card[a] << "  ";
        }
        cout << "\n\n";
        if(robottotal>21){
            cout << "You Win!\n\n";
            coin+=2*roundcoin;
            continue;
        }
        int playerfinal,robotfinal;
        sort(robot,robot+10,greater<int>());
        sort(roundcards,roundcards+10,greater<int>());
        for(int a:robot){
            if(a==1&&robotfinal+11<=21) robotfinal+=11;
            else if(a>10) robotfinal+=10;
            else robotfinal+=a;
        }
        for(int a:roundcards){
            if(a==1&&playerfinal+11<=21) playerfinal+=11;
            else if(a>10) playerfinal+=10;
            else playerfinal+=a;
        }
        if(robotfinal>playerfinal){
            cout << "You Lose!\n\n";
        }
        else if(robotfinal==playerfinal){
            cout << "Tie!\n\n";
            coin+=roundcoin;
        }
        else{
            cout << "You Win!\n\n";
            coin+=2*roundcoin;
        }
    }
    cout << "You Can't bet cause you're out of coins!";
    return 0;
}
