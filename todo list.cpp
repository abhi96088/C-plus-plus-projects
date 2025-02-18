// program to create a todo list

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void displayTasks(const vector<string> &tasks){
	if(tasks.empty()){
		cout<<"No Tasks Available"<<endl;
		return;
	}
	
	cout<<"To-Do List"<<endl;
	
	for(size_t i =0; i<tasks.size(); i++){
		cout<<i+1<<". "<<tasks[i]<<endl;
	}
}

int main(){
	vector<string> tasks;
	int choice;
	string task;
	
	do{
		cout<<"\nTo-Do List Menu"<<endl;
		cout<<"1. Add Task"<<endl;
		cout<<"2. Remove Task"<<endl;
		cout<<"3. Display Task"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cin.ignore();
		
		switch(choice){
		case 1:
			cout<<"Enter task: ";
			getline(cin, task);
			tasks.push_back(task);
			cout<<"Task added successfully!"<<endl;
			break;
		case 2:
			int index;
			displayTasks(tasks);
			if(!tasks.empty()){
				cout<<"Enter task number to remove"<<endl;
				cin>>index;
				if(index > 0 && index <= tasks.size()){
					tasks.erase(tasks.begin() + index - 1);
					cout<<"Task removed successfully"<<endl;
				}else{
					cout<<"Invalid tsk number!"<<endl;
				}
			}     				
			break;            	
		case 3:
			displayTasks(tasks);
			break;
		case 4:
			cout<<"Exiting..."<<endl;
			break;
		default:
			cout<<"Invalid choice! please enter a number between 1 and 4."<<endl;
				
		}
	}while(choice!=4);
	
return 0;
}
