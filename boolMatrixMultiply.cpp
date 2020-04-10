#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > boolMatrixMultiply(vector< vector<int> > x, vector< vector<int> > y);
vector< vector<int> > boolPowerMatrix(vector< vector<int> > x, int r);

int main(int argc, char* argv[]){

    vector< vector<int> > a {{0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1}, {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}};

    int n = a.size();
    int m = a[0].size();

    vector< vector<int> > a2 (n, vector<int> (m, 0));
    cout<<"Before multiplying: "<<endl;
    for (int i = 0; i < a.size(); i++) { 
        for (int j = 0; j < a[i].size(); j++){ 
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // a2 = boolMatrixMultiply(a, a);
    a2 = boolPowerMatrix(a, 4);

    cout<<"After multiplying: "<<endl;
    for (int i = 0; i < a2.size(); i++) { 
        for (int j = 0; j < a2[i].size(); j++){ 
            cout << a2[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

vector< vector<int> > boolMatrixMultiply(vector< vector<int> > x, vector< vector<int> > y){
    int i, j, k;
    int n = x.size();
    int m = x[0].size();

    vector< vector<int> > result(n, vector<int> (m, 0));

    if (x[0].size() != y.size()){
        cout<<"Unable to multiply matrices. Sizes not equal."<<endl;
        return x;
    }

    for (i = 0; i < x.size(); i++){
        for (j = 0; j < y[0].size(); j++){
            for (k = 0; k < y.size(); k++){
                result[i][j] = result[i][j] | (x[i][k] & y[k][j]);
            }
        }
    }
    return result;
}

vector< vector<int> > boolPowerMatrix(vector< vector<int> > A, int r){
    vector< vector<int> > a = A;
    int size = A.size();
    int n = A.size();
    int m = A[0].size();
    vector< vector<int> > b(n, vector<int> (m, 0));

    for (int i = 0; i < size; i++) {//set up the identity matrix. If row == col, then =1. Else =0.
        for (int j = 0; j < size; j++){
            if(i==j) {
            b[i][j] = 1;
            }
        }
    }

    while (r > 0){
        if (r % 2 == 1){
            b = boolMatrixMultiply(b, a);
        }
        a = boolMatrixMultiply(a, a);
        r = r / 2;
    }
    return b;
}