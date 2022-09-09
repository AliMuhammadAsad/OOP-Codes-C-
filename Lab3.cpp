//Q1 - Vector Manipulation

#include<iostream>
using namespace std;

void print_vector(int size,int vector[]){
    for(int i = 0; i < size; i++){
        cout << vector[i] << " ";
    }
}

void input_vector(int size, int vector[]){
    int value;
    for (int i = 0; i < size; i++){
        cin >> value; vector[i] = value;
    }  
}

void add_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] + vector2[i];
    }
}

void subtract_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] - vector2[i];
    }
}

bool compare_vectors(int size, int vector1[], int vector2[]){
    bool flag = true;
    for (int i = 0; i < size; i++){
        if (vector1[i] != vector2[i]) {flag = false; break;}
    }
    return flag;
}

int main(){
    int size; cin >> size;
    bool flag;
    int vector1[size], vector2[size], vector3[size];
    input_vector(size, vector1); input_vector(size, vector2);
    char sign; cin >> sign;
    switch(sign){
        case '+':
            add_vectors(size, vector1, vector2, vector3);
            print_vector(size, vector3);
            break;
        case '-':
            subtract_vectors(size, vector1, vector2, vector3);
            print_vector(size, vector3);
            break;
        case '=':
            flag = compare_vectors(size, vector1, vector2);
            if(flag == true){
                cout << "EQUAL";
            }
            else {cout << "UNEQUAL";}
    }
    
    return 0;
}

//----------------------------------------------------------------------------------------//

//Q2 - Matrix Manipulation
// Enter your code here.
#include<iostream>
using namespace std;

void print_matrix(int row, int col, int size,int vector[]){
    for(int i = 0; i < col; i++){
        cout << vector[i] << " ";
    }
    cout <<endl;
    for(int i = col; i < size; i++){
        cout << vector[i] << " ";
    }
}

void input_matrix(int size, int vector[]){
    int value;
    for (int i = 0; i < size; i++){
        cin >> value; vector[i] = value;
    }  
}

void add_matrices(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] + vector2[i];
    }
}

void subtract_matrices(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] - vector2[i];
    }
}

int main(){
    int row, col, size; cin >> row >> col;
    size = row * col;
    // bool flag;
    int vector1[size], vector2[size], vector3[size];
    input_matrix(size, vector1); input_matrix(size, vector2);
    char sign; cin >> sign;
    switch(sign){
        case '+':
            add_matrices(size, vector1, vector2, vector3);
            print_matrix(row, col, size, vector3);
            break;
        case '-':
            subtract_matrices(size, vector1, vector2, vector3);
            print_matrix(row, col, size, vector3);
            break;
    }
}

//----------------------------------------------------------------------------------------//

//Q5 - Chronological Order
// Takes number of years, then consecutive years and outputs them in chronological order order using bubble sort

using namespace std;

void input_years(int yrs[], int num_yrs){
    int years; 
    for (int i = 0; i < num_yrs; i++){
        cin >> years;
        while(years < 0 || years > 9999){
            cout << "Year can be between 0 and 9999! Try Again!" << endl;
            cin >> years;
        }
        yrs[i] = years;
    }
}

void print_yrs_array(int yrs[], int num_yrs){
    cout << yrs[0];
    for(int i = 1; i < num_yrs; i++){
        cout << ", " << yrs[i];
    }
}

void chronological_order(int yrs[], int num_yrs){
    for(int i = 0; i < num_yrs - 1; i++){
        for(int j = 0; j < num_yrs - i -1; j++){
            if(yrs[j] > yrs[j+1]){
                int swapper = yrs[j]; yrs[j] = yrs[j + 1]; yrs[j + 1] = swapper;
            }
        }
    }
}

int main(){
    int num_yrs; cin >> num_yrs;
    while(num_yrs < 2){
        cout << "Need at least 2 years to sort! Try Again!"<<endl;
        cin >> num_yrs;
    }
    int yrs[num_yrs];
    input_years(yrs, num_yrs);
    cout << "The initial array is: "; print_yrs_array(yrs, num_yrs);
    chronological_order(yrs, num_yrs);
    
    cout << "\nThe sorted array is: "; print_yrs_array(yrs, num_yrs); 
}