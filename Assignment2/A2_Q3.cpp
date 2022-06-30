#include <iostream>
#include <cmath>
using namespace std;
int determinant(int**,int);
void display(int **arr,int row,int col){
    cout<<"The Matrix is"<<endl;
    for(int i=0;i< row;i++){
        for(int j=0;j<col;j++){
            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<endl;
    }
}
void multiplication(int **arr,int **brr,int row,int col){
    int **crr = new int*[row];
    for(int i=0;i<row;i++){
        *(crr+i) = new int [col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            *(*(crr+i)+j)=0;
            for(int k=0;k<col;k++)
            *(*(crr+i)+j) += (*(*(arr+i)+k) * *(*(brr+k)+j));
        }
    }
    cout<<"MULTIPLIED MATIX:"<<endl;
    display(crr,row,col);
}

void minorM(int **arr,int **temp,int row,int col,int n){
    int temp_i=0,temp_j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=row &&  j!=col){
                *(*(temp+temp_i)+temp_j++) = *(*(arr+i)+j);
            }
            if(temp_j==n-1){
                temp_i++;
                temp_j=0;
            }
        }
    }
}
int **adjoint(int **arr,int n){
    int** adj = new int*[n];
    for(int i=0;i<n;i++)
        {
            *(adj+i) = new int[n];
        }
    int **temp = new int* [n];
    for(int i=0;i<n;i++)
        *(temp+i) = new int[n];    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            minorM(arr,temp,i,j,n);
            *(*(adj+j)+i) = pow(-1,i+j)*determinant(temp,n-1);
        }
        
    }
    return adj;
}
int determinant(int **arr,int n)
{
    if(n==1)
        return *(*(arr+0)+0);
    int **temp = new int* [n] ;
    for(int i=0;i<n;i++)
        *(temp+i) = new int[n];
    int ans=0;
    for(int k=0;k<n;k++){
        minorM(arr,temp,0,k,n);
        ans += pow(-1,k)*(*(*(arr+0)+k))*determinant(temp,n-1);
        //delete(temp);
    }    
    return ans;
}
void inverse(int **arr,int n){
    int d=determinant(arr,n);
    if(d==0){
        cout<<" INVERSE DOES NOT EXIST!!!!!  "<<endl;
    }
    else{
        int **adj = adjoint(arr,n);
        cout<<"INVERSE Matrix is: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x = *(*(adj+i)+j);
                cout<<x/float(d)<<" ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    int row1,col1;
    cout<<"Enter the 1st Matrix size of row && col"<<endl;
    cin>>row1>>col1;
    cout<<"Enter Matrix Elements:"<<endl;
    int **arr = new int* [row1];
    for(int i=0 ; i<row1 ;i++)
    {   *(arr+i) = new int [col1];
        for(int j=0;j<col1;j++){
            cin>>*(*(arr+i)+j);
        }
    }
    int row2,col2;
    cout<<"Enter the 2nd Matrix size of row && col"<<endl;
    cin>>row2>>col2;
    cout<<"Enter Matrix Elements:"<<endl;
    int **brr = new int* [row2];
    for(int i=0 ; i<row2 ;i++)
    {   *(brr+i) = new int [col2];
        for(int j=0;j<col2;j++){
            cin>>*(*(brr+i)+j);
        }
    }
    display(arr,row1,col1);
    display(brr,row2,col2);
    if(row2!=col1){
        cout<<"multiplication does not exist"<<endl;
    }
    else{
        cout<<"Multiplation Exist"<<endl;
        multiplication(arr,brr,row1,col2);
    }
    if(row1!=col1 || row2!=col2){
        cout<<"determinant does not exist: "<<endl;
        cout<<"inverse does not exist:"<<endl;
        return 0;
    }
    cout<<"determinant of 1st Matrix is:"<<determinant(arr,row1)<<endl;
    cout<<"determinant of 2nd Matrix is:"<<determinant(brr,row2)<<endl;
    inverse(arr,row1);
    inverse(brr,row2);
    return 0;
}