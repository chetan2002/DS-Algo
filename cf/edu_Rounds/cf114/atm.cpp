#include<bits/stdc++.h>
using namespace std;
#define ll long long int


class ATM {
private:
	int cardNumber;
	bool loggedIn;
public:
	ATM(int cardNumber, int pin) {
		this.cardNumber = cardNumber;
		if(validateCardNumber()) {

		}else {
			showErrorAndExit("invalid card");
		}
		if(validateCardNumberWithPin(pin)) {
			loggedIn = true;
		}else {
			showErrorAndExit("invalid pin");
		}

		// show menu
		if(loggedIn) showMenu();
	}
	bool validateCardNumber() {

	}
	bool validateCardNumberWithPin(int pin) {

	}

	void showMenu() {
		cout<< "Options : " <<endl;
		cout<< "1. check balance \n 2. withdraw \n 3. change pin \n 4. exit" <<endl;
		int option ;
		cin>>option;
		switch (option) {
			case 1: checkbalance();
			case 2: withdraw();
			case 3: changepin();
			case 4: exit();
			default: showErrorAndExit("Not a correct option");
		} 
	}

	

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    return 0;
}