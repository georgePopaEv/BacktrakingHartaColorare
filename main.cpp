#include <iostream>
#include <fstream>
using namespace std;

int A[101][101];
int X[101];
int n;
char c[4][20] = {"mov","rosu", "verde", "galben"};

int valid(int k){
    for(int i = 1; i<k ; i++){
        if(A[i][k] == 1 && X[i] == X[k])
            return 0;
    }
    return 1;
}

int solutie(int k){
    for(int i=1; i<=4 ; i++){
        X[k] = i;
        if(valid(k))
            return i;
    }
    return 0;
}

void tipar(){
    for(int i = 1; i<=n ; i++){
        cout<<"tara "<< i<< " are culoarea "<< c[X[i]-1]<< endl;
    }
}

void back(){
    for(int i =1 ; i<=n ;i++){
        X[i] = solutie(i);
    }
    tipar();
}

ifstream f("arr");

int main() {

    f>>n;
    int t1,t2;
    while (f>>t1>>t2){
        A[t1][t2] = 1;
        A[t2][t1] = 1;
    }
    cout<<n<<endl;

    back();
    return 0;
}
