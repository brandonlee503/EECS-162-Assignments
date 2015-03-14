#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class mystring {
private:
    int count;
    char *str;
    char *cstr;
public:
    mystring();
    mystring(const char *);
    ~mystring();
    void display();
    char at(int);
    int length();
    void operator = (const char*);
    void operator += (const char *s);
    int find(const char *s);
    char* substr(int a, int b);
    char* substr(int a);
    char* c_str();
};


mystring::mystring(){
    cout << "default" << endl;
    count = 0;
    str = NULL;
    cstr = NULL;
}

mystring::mystring(const char *s){
    cout << "const" << " s: " << s << endl;
    count = strlen(s);
    cout << "count: " << count << endl;
    if(str!=NULL){
        delete [] str;
        delete [] cstr;
    }
    str = new char[count];
    cstr = new char[count + 1];
    for (int i = 0; i < count; i++){
        str[i] = s[i];
        cstr[i] = s[i];
    }
    cstr[count + 1] = '\0';
    cout << "assigned" << endl;
}

mystring::~mystring(){
    if(str!=NULL)
        delete [] str;
    
}

int mystring::length(){
    return count;
}

char* mystring::substr(int a, int b){
    char* temp = new char[b];
    int p = 0;
    for(int i = (a - 1); i < (a + b); i++){
        temp[p] = str[i];
        p++;
    }
    return temp;
}

char* mystring::substr(int a){
    char* temp = new char[count - a];
    int p = 0;
    for(int i = a; i < count; i++){
        temp[p] = str[i];
        p++;
    }
    return temp;
}


char mystring::at(int n){
    if(count == 0 || n > count){
        cout << "broken" << endl;
    }
    else
        return str[n];
    
    return 1;
}

char* mystring::c_str(){
    return cstr;
}

int mystring::find(const char *s){
    int size, i, t = 0, p = 0;
    size = strlen(s);
    for(i = 0; i < count; i++){
        if(str[i] == s[p]){
            t++;
            p++;
        }
        else{
            t = 0;
            p = 0;
        }
        if(t == size){
            return (i - t + 1);
        }
    }
}

void mystring::operator = (const char *s){
    count = strlen(s);
    if(str!=NULL){
        delete [] str;
        delete [] cstr;
    }
    str = new char[count];
    cstr = new char[count + 1];
    for (int i = 0; i < count; i++){
        str[i] = s[i];
        cstr[i] = s[i];
    }
    cstr[count + 1] = '\0';
    cout << "assigned" << endl;
}


void mystring::operator += (const char *s){
    int count2, j = 0;
    char *temp = new char[count];
    count2 = strlen(s) + count;
    if(str!=NULL){
        for(int i = 0; i < count; i++)
            temp[i] = str[i];
        delete [] str;
        delete [] cstr;
        str = new char[count2];
        cstr = new char[count2 + 1];
    }
    else{
        str = new char[count2];
        cstr = new char[count2 + 1];
    }
    
    for(int i = 0; i < count; i++){
        str[i] = temp[i];
        cstr[i] = temp[i];
    }
    for(int i = count; i < count2; i++){
        str[i] = s[j];
        cstr[i] = s[j];
        j++;
    }
    cstr[count2 + 1] = '\0';
    count = count2;
    cout << "assigned" << endl;
}


void mystring::display(){
    cout << str << endl;
}

int main(){
	mystring str;
    char* test1;
    char* test2;
    str = "hello";
    
    str.display();
    cout << "length: " << str.length() << endl;
    str += " world";
    
    str.display();
    
    cout << "length: " << str.length() << endl;

    cout << "found at: " << str.find("orld") << endl;
    test1 = str.substr(7, 5);
    test2 = str.substr(3 );
    cout << "substring " << test1 << endl;
    cout << "substring overload " << test2 << endl;
    
    cout << "c_str: " << str.c_str() << endl;
    //cout << str.length() << endl;
    cout << str.at(3) << endl;
    

    
    return 1;
}
