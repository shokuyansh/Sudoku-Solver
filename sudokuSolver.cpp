#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isValid(int arr[][9],int r,int c,int k){
	for (int i = 0; i < 9; i++) {
        if (arr[r][i] == k) 
        	return false; 
        if (arr[i][c] == k) 
        	return false; 
        if (arr[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == k) 
        	return false; 
    }
    return true;
}
bool solve(int arr[][9],int r,int c){
	if(r==9)
		return true;
	if(c==9)
		return solve(arr,r+1,0);
	else if(arr[r][c]>=1&&arr[r][c]<=9)
		return solve(arr,r,c+1);
	else{
		for(int k=1;k<=9;k++){
			if(isValid(arr,r,c,k)==true){
                        arr[r][c]=k;
                        if(solve(arr,r,c+1))
                                return true;
                        arr[r][c]=0;
                        
			}
		}
		return false;
		
	}
}


int main(){
	int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
	if(solve(sudoku,0,0)){
		cout<<"Sudoku Solved: \n";
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<sudoku[i][j]<<" ";
			}
			cout<<"\n";
		}                                      	                                              
	 }
	
	return 0;
}

