//================================
//Roosevelt Bannerman
//Infix to Postfix convertor
//================================
#include <iostream>
#include <string>
//#include "stackADT.h"
#include <stack>

using namespace std;

int obtainMenuSelection();
string obtainInfix();
string obtainInfixWithNum();
string obtainPostfix();
string convertToPostfix(string);
string evalulatePostFix(string);
int calcOperands(char);
int runOperator(int,int,char);

int main(){
    int selection;

    do {
        selection = obtainMenuSelection();
        switch(selection){
        case 1:{
            string infix = obtainInfix();
            string postfix = convertToPostfix(infix);
            cout << "\n\tInfix  : " << infix;
            cout << "\n\tPostfix: " << postfix;
            break;
        }
        case 2:{
            string postfix = obtainPostfix();
            string result = evalulatePostFix(postfix);
            cout << "\n\tPostfix: " << postfix;
            cout << "\n\tResult : " << result;
            break;
        }
        case 3:
            string infix = obtainInfixWithNum();
            string postfix = convertToPostfix(infix);
            string result = evalulatePostFix(postfix);
            cout << "\n\tInfix  : " << infix;
            cout << "\n\tPostfix: " << postfix;
            cout << "\n\tResult : " << result;
            break;
        }
    } while(selection != 4);

    cout << "\n\n\tGoodbye.";

}

//==============================
//Obtains menu selection
//Returns the menu selection
//==============================
int obtainMenuSelection(){
    bool isValid = true;
    string entry;
    cout << "\n\n\t1 - Infix to postfix conversion";
    cout << "\n\t2 - Postfix Evaluation";
    cout << "\n\t3 - Infix to postfix Evaluation";
    cout << "\n\t4 - Quit";

    do {
        cout << "\n\n\tWhat would you like to do: ";
        getline(cin,entry);
        isValid = true;
        const int LENGTH = entry.length();

        if(entry.empty()){
            isValid = false;
        }
        else if(LENGTH != 1){
            isValid = false;
        }
        else if(entry[0] < '1' || entry[0] > '4'){
            isValid = false;
        }

        if(!isValid){
            cout << "\n\tEntry error. Please try again.";
        }
    } while(!isValid);

    return (entry[0] - '0');
}

//==============================
//Obtains the infix expression with only letters
//Returns the infix expression
//==============================
string obtainInfix(){

    bool isValid = true;
    string entry;

    do{
        cin.clear();
        cout << "\n\tPlease enter the infix expression: ";
        getline(cin,entry);
        const int LENGTH = entry.length();
        isValid = true;

        if(entry.empty()){
            isValid = false;
        }

        if(LENGTH < 3){
            isValid = false;
        }

        for(int i=0;i<LENGTH;i++){
            if(entry[i] > 'Z' || (entry[i] < 'A'
            && entry[i] != '+' && entry[i] != '-'
            && entry[i] != '*' && entry[i] != '/'
            && entry[i] != '(' && entry[i] != ')')){
                isValid = false;
            }
        }

        if (!isValid){
            cout << "\tEntry error. Please try again.";
        }
    } while(!isValid);

    return entry;
}

//==============================
//Obtains the infix expression with letters and numbers
//Returns the infix expression
//==============================
string obtainInfixWithNum(){

    bool isValid = true;
    string entry;

    do{
        cin.clear();
        cout << "\n\n\tPlease enter the Infix expression: ";
        getline(cin,entry);
        const int LENGTH = entry.length();
        isValid = true;

        if(entry.empty()){
            isValid = false;
        }

        if(LENGTH < 3){
            isValid = false;
        }

        for(int i=0;i<LENGTH;i++){
            if(entry[i] > 'Z' || (entry[i] < '1'
            && entry[i] != '+' && entry[i] != '-'
            && entry[i] != '*' && entry[i] != '/'
            && entry[i] != '(' && entry[i] != ')')
            ||(entry[i] > '9' && entry[i] < 'A')){
                isValid = false;
            }
        }

        if (!isValid){
            cout << "\tEntry error. Please try again.";
        }
    } while(!isValid);

    return entry;
}

//==============================
//Obtains the postfix expression with letters and numbers
//Returns the postfix expression
//==============================
string obtainPostfix(){

    bool isValid = true;
    string entry;

    do{
        cin.clear();
        cout << "\n\n\tPlease enter the postfix expression: ";
        getline(cin,entry);
        const int LENGTH = entry.length();
        isValid = true;

        if(entry.empty()){
            isValid = false;
        }

        if(LENGTH < 3){
            isValid = false;
        }

        for(int i=0;i<LENGTH;i++){
            if(entry[i] > 'Z' || (entry[i] < '1'
            && entry[i] != '+' && entry[i] != '-'
            && entry[i] != '*' && entry[i] != '/'
            && entry[i] != '(' && entry[i] != ')')
            ||(entry[i] > '9' && entry[i] < 'A')){
                isValid = false;
            }
        }

        if (!isValid){
            cout << "\tEntry error. Please try again.";
        }
    } while(!isValid);

    return entry;
}

//==============================
//Recieves the infix expressions
//Converts the infix to postfix
//Returns the postfix expression
//==============================
string convertToPostfix(string infix){

    string postfix;
    stack<char> inventory;
    int bracket = 0;

    while (!infix.empty() || !inventory.empty()){

        char current = infix[0];
        infix.erase(0,1);

        if((current>='A' && current <= 'Z') || (current >= '1' && current <= '9')){
            postfix += current;
            continue;
        }

        else if (current == '('){
            inventory.push(current);
            bracket++;
            continue;
        }
        else if (current == ')'){
            while(inventory.top()!='('){
                postfix += inventory.top();
                inventory.pop();
            }
            inventory.pop();
            bracket--;
            continue;
        }

        if(bracket == 0 && (current == '+' || current == '-')){
            while(!inventory.empty()){
                postfix += inventory.top();
                inventory.pop();
            }
            inventory.push(current);
            continue;
        }
        else if(bracket == 0 && (current == '*' || current == '/')){
            if(inventory.empty()){
                inventory.push(current);
                continue;
            }
            else{
                while(inventory.top() == '*' || inventory.top() == '/'){
                    postfix += inventory.top();
                    inventory.pop();
                }
                inventory.push(current);
                continue;
            }
        }

        if(bracket != 0){
            inventory.push(current);
            continue;
        }

        if(infix.empty()){
            postfix += inventory.top();
            inventory.pop();
        }

    }

    return postfix;
}

//==============================
//Recieves the postfix expression
//Calculates the result
//Returns the result
//==============================
string evalulatePostFix(string postfix){

    stack<char> inventory;

    const int P_LENGTH = postfix.length();

    for (int i=0;i<P_LENGTH;i++){
        if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/'){
            int temp = calcOperands(postfix[i]);
            inventory.push(temp);
        }
        else{
            int temp1 = inventory.top();
            inventory.pop();
            int temp2 = inventory.top();
            inventory.pop();
            int result = runOperator(temp2,temp1,postfix[i]);
            inventory.push(result);
        }
    }

    string result;

    int temp = inventory.top() / 36;

    result += temp +'0';
    temp = inventory.top() - (temp*36);

    if(temp > 9){
        result += temp + '7';
    }
    else{
        result += temp + '0';
    }



    const int R_LENGTH = result.length();

    for(int i=0;i<R_LENGTH;i++){
        if(result[i]=='0'){
            result.erase(0,1);
        }
        else{
            break;
        }
    }
    return result;
}

//==============================
//Recieves a character
//Returns the base 36 integer of that character
//==============================
int calcOperands(char arg){

    if(arg > '9'){
        return(arg - '@' + 9);
    }
    else{
        return(arg - '0');
    }

}

//==============================
//Recieves two integers and an operator
//Returns the result of the operation
//==============================
int runOperator(int arg1,int arg2,char arg3){

    if(arg3 == '+'){
        return arg1 + arg2;
    }
    else if(arg3 == '-'){
        return arg1 - arg2;
    }
    else if(arg3 == '*'){
        return arg1 * arg2;
    }
    else{
        return arg1 / arg2;
    }
}
