//Calculator – Perform basic arithmetic operations (+, -, *, /).

#include<iostream>

using namespace std;

int main(){
	
	int choice;
	double num1, num2, result;
	
	cout<<"Simple Calculator"<<endl;
	cout<<"*****************"<<endl<<endl;
	
	while(1){
		
	cout<<"Choose an Option"<<endl;
	cout<<"1. Add"<<endl;
	cout<<"2. Subtract"<<endl;
	cout<<"3. Multiply"<<endl;
	cout<<"4. Divide"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"Enter Your Choice: ";
	cin>>choice;
	
	if(choice > 0 && choice < 5){
		cout<<"Enter Two Numbers: ";
		cin>>num1>>num2;	
	}else if(choice == 5){
		return 0;
	}else{
		cout<<"Please enter a valid choice!!"<<endl;
		continue;
	}
	
	
	switch(choice){
		case 1:
			result = num1 + num2;
			break;
		case 2:
			result = num1 - num2;
			break;
		case 3:
			result = num1 * num2;
			break;
		case 4:
			if(num2 != 0){
				result = num1 / num2;
			}else{
				cout<<"Division by zero is not allowed!"<<endl;
				return 1;
			}
			break;
		default:
			cout<<"Invalid Operation !!"<<endl;
			return 1;
	}
	
	cout<<"Result: "<<result<<endl<<endl;

	}	
return 0;
}
