//  Write a program to implement stack using (ii) TWO Queues 
#include<iostream>
#include<queue>
using namespace std;

class stacktwoqueues{
	queue<int> q1,q2;
	public:
		void push(int x){
			q1.push(x);
		}
		void pop(){
			if(q1.empty()){
				cout<<"empty stack"<<endl;
			}
			else{
				while(q1.size()>1){
					q2.push(q1.front());
					q1.pop();
				}
				q1.pop();
				// queue<int> q=q1;
				q1=q2;
				// q2=q;
				while(!q2.empty()){
					q2.pop();
				}
			}
		}
		int top(){
			if(q1.empty()){
				cout<<"empty stack\t";
				return -1;
			}
			else{
				while(q1.size()>1){
					q2.push(q1.front());
					q1.pop();
				}
				int x=q1.front();
				q2.push(q1.front());
				q1.pop();
				queue<int> q=q1;
				q1=q2;
				q2=q;
				return x;
			}
		}
		int size(){
			return q1.size();
		}
		bool empty(){
			return q1.empty();
		}
};
int main(){
	stacktwoqueues s;
	s.push(5);
	s.push(4);
	s.push(3);
	cout<<s.size()<<endl;
	s.push(2);
	s.push(1);
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
}
