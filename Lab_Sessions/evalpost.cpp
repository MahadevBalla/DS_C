#include <bits/stdc++.h>
using namespace std;

class Stackk{
	int topp;
	int arr[30];

public:
	Stackk(){
    	topp = -1;
	}

	void push(int n){
    	if (topp >= 29){
        	cout << "Overflow\n";
        	return;
    	}
    	topp++;
    	arr[topp] = n;
	}

	void pop(){
    	if(topp < 0){
        	cout << "Underflow\n";
        	return;
    	}
    	topp--;
	}

	int top(){
    	if(topp < 0){
        	cout << "Underflow\n";
        	return -1;
    	}
    	return arr[topp];
	}

	int size(){
    	return topp + 1;
	}

	bool isEmpty(){
    	return topp == -1;
	}
};

bool isOperator(char c){
	return c=='*' || c=='/' || c=='+' || c=='-';
}

int evaluatePostfix(string s){
	Stackk st;
	for(auto c : s){
    	if(isdigit(c)){
        	st.push(c - '0');
    	}
    	else if(isOperator(c)){
        	int t1 = st.top();
        	st.pop();
        	int t2 = st.top();
        	st.pop();

        	switch(c){
        	case '+': st.push(t2 + t1); break;
        	case '-': st.push(t2 - t1); break;
        	case '*': st.push(t2 * t1); break;
        	case '/': st.push(t2 / t1); break;
        	}
    	}
    	else{
        	cout << "Enter a valid postfix expression!!" << endl;
    	}
	}
	return st.top();
}

int main(){
	string s;
	cout << "Enter input : ";
	cin >> s;
	int ans = evaluatePostfix(s);
	cout << "Answer : " << ans << endl;
	return 0;
}
