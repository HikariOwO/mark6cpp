#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;
void RNGnum(){
    int CPUnum[8];
    srand(time(NULL));
    CPUnum[1] = rand() % 49+1;
    CPUnum[2] = rand() % 49+1;
    CPUnum[3] = rand() % 49+1;
    CPUnum[4] = rand() % 49+1;
    CPUnum[5] = rand() % 49+1;
    CPUnum[6] = rand() % 49+1;
    CPUnum[7] = rand() % 49+1;
    cout << "開獎號碼: ";
    for (int i = 1; i < 7; i++){
        cout << CPUnum[i] << " ";
    }
    cout << "特別號碼:" << CPUnum[7] << "\n";
}
void RNGUserNum(){
    srand(8745);
    int UserChoice[8];
    UserChoice[1] = rand() % 49+1;
    UserChoice[2] = rand() % 49+1;
    UserChoice[3] = rand() % 49+1;
    UserChoice[4] = rand() % 49+1;
    UserChoice[5] = rand() % 49+1;
    UserChoice[6] = rand() % 49+1;
    UserChoice[7] = rand() % 49+1;
    cout << "你的號碼: ";
    for (int i = 1; i < 7; i++){
        cout << UserChoice [i] << " ";
    }
    cout << "你的特別號碼: " << UserChoice[7] << "\n";
}
void UserInputNum(){
    int UserInChoice[8];
    int a,b,c,d,e,f,g;
    do{
        cout << "請填寫你要的號碼 (49以內的數字): ";
        cin >> a >> b >> c >> d >> e >> f >> g;
    } while(a > 49 || b > 49 || c > 49 || d > 49 || e > 49 || f > 49 || g > 49);
    a = UserInChoice[0];
    b = UserInChoice[1];
    c = UserInChoice[2];
    d = UserInChoice[3];
    e = UserInChoice[4];
    f = UserInChoice[5];
    g = UserInChoice[6];
    cout << "你的號碼: ";
    for (int i = 0; i < 7; i++){
        cout << UserInChoice[i] << " " ;
    }
    cout << "你的特別號碼: " << UserInChoice[6] << "\n";
}

int main(){
    int UserInput;
    cout << "請選擇你要電腦獲取號碼還是人手填寫?\n人手填寫為1\n電腦填寫為2\n";
    cin >> UserInput;
    if (UserInput == 1){
        UserInputNum();
    }
    if (UserInput == 2){
        RNGUserNum();
    }
    RNGnum();
    return 0;
}