#include <iostream>
#include <random>
#include <time.h>

using namespace std;
int CPUnum[7],CPUsNum;
int UserChoice[7],UserSChoice;
int UserInChoice[7],UserInSChoice;
int a,b,c,d,e,f,g;
int a1,b1,c1,d1,e1,f1,g1;

void RNGnum(){
    do{
        a1 = rand() % 49+1;
        b1 = rand() % 49+1;
        c1 = rand() % 49+1;
        d1 = rand() % 49+1;
        e1 = rand() % 49+1;
        f1 = rand() % 49+1;
        g1 = rand() % 49+1;
    } while (a1 == b1 || b1 == c1 || c1 == d1 || d1 == e1 || f1 == g1|| g1 == a1|| a1 == c1 || a1 == d1 || a1 == e1 || a1 == f1 || a1 == g1 || b1 == d1 || b1 == e1 || b1 == f1 || b1 == g1|| c1 == e1 || c1 == f1 || c1 == g1 || d1 == f1 || d1 == g1|| e1 == g1);
    CPUnum[1] = a1;
    CPUnum[2] = b1;
    CPUnum[3] = c1;
    CPUnum[4] = d1;
    CPUnum[5] = e1;
    CPUnum[6] = f1;
    CPUsNum = g1;
    cout << ": ";
    for (int i = 1; i < 7; i++){
        cout << CPUnum[i] << " ";
    }
    cout << "特別號碼:" << CPUsNum << "\n";
}


void UserInputNum(){
    do{
        cout << "Please input the numbers you want (49 or under): ";
        cin >> a >> b >> c >> d >> e >> f >> g;
    } while(a > 49 || b > 49 || c > 49 || d > 49 || e > 49 || f > 49 || g > 49);
    UserInChoice[0] = a;
    UserInChoice[1] = b;
    UserInChoice[2] = c;
    UserInChoice[3] = d;
    UserInChoice[4] = e;
    UserInChoice[5] = f;
    UserInSChoice = g;
    cout << "Your numbers: ";
    for (int i = 0; i < 6; i++){
        cout << UserInChoice[i] << " " ;
    }
    cout << "Your special number: " << UserInSChoice << "\n";
}


int main(){
    srand(time(NULL));
    string UserInput;
    int score;
    int money = 1000;
    int OriMoney = 1000;
    int normalmatch, specialmatch,winorlose;
    do{
    cout << "Please type 「y」to play" << endl << "Type「n」to end";
    cout << "Your wallet: HKD$" << money << endl << "Every time you play cost you HKD$50" << endl;
    cin >> UserInput;
    if (UserInput == "y" or UserInput == "Y"){
        UserInputNum();
        RNGnum();
        sort(UserInChoice, UserInChoice+6);
        sort(CPUnum, CPUnum+6);
        money = money - 50;
        for (int i = 0; i != 6; i++) {
            for (int j = 0; j != 7; j++) {
                if (UserInChoice[i] == CPUnum[j]) {
                    normalmatch++;
                }
            }
        }  

        cout <<"You got" << normalmatch << "ordinary numbers" << endl;

        if (UserInSChoice == CPUsNum){
            cout << "You got the special number";
            specialmatch++;
            cout <<"You got" << normalmatch << "ordinary numbers" << "and one more special number." << endl;
        } 

        score = normalmatch*2 + specialmatch;

        switch(score){
            case 13: //7個號碼全中
            money = money + 50000000;
            cout << "Congrats, you got the grand prize" << endl;
            break;

            case 12: //6個普通號碼中
            money = money + 50000000;
            cout << "Congrats, you got the grand prize" << endl;
            break;

            case 11: //5個普通+1個特別
            money = money + 1500000;
            cout << "Congrats, you got the second prize" << endl;
            break;

            case 10: //5個普通
            money = money + 100000;
            cout << "Congrats, you got the third prize" << endl;
            break;

            case 9: //4個普通+特別
            money = money + 10000;
            cout << "Congrats, you got the forth prize" << endl;
            break;

            case 8: //4個普通
            money = money + 640;
            cout << "Congrats, you got the fifth prize" << endl;
            break;

            case 7: //3個普通+特別
            money = money + 320;
            cout << "Congrats, you got the sixth prize"<< endl;
            break;

            case 6: //3個普通
            money = money + 40;
            cout << "Congrats, you got the seventh prize" << endl;
            break;

            default:
            cout << "You lose this round" <<  endl;
        }
        cout << "Wallet: HKD$" << money << endl << endl;
    }
    if (money < 50) {
        cout << "You lost all your money" << endl;
        return 0;
    }
    } while (UserInput == "y" or UserInput == "Y");

    if (UserInput == "n") {
            cout << "Play again next time" << endl;
            winorlose = OriMoney - money;
            if (winorlose > 0 ){
                cout << "You lose: HKD$" << winorlose << endl;
                return 0;
            }
            if (winorlose < 0){
                winorlose = winorlose*-1;
                cout << "You win: HKD$" << winorlose << endl;
                return 0;  
            }
            if (winorlose == 0){
                cout << "It's a draw!" << endl;
                return 0;
            }
        }
    return 0;
}