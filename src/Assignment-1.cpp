#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int const SIZEX=4;
int const SIZEY=4;
int const LIMIT=15;

void populate(int arr[][SIZEX]) {

	for(int i=0;i<SIZEX;i++){
		for(int j=0;j<SIZEY;j++) {
			arr[i][j]=rand()%LIMIT;
		}
	}
}

int greatest(int arr[][SIZEX],int i,int j) {
	int great=arr[i][j];
	for(int k=i-1;k<=i+1;k++) {
		if(k<0||k>SIZEX-1)
			continue;
		for(int l=j-1;l<=j+1;l++) {
			if(l<0||l>SIZEY-1)
				continue;
			if(great<arr[k][l])
				great=arr[k][l];
		}
	}
	return great;
}

void dissolve(int arr[][SIZEY],int greatarr[SIZEX][SIZEY]) {


		for(int i=0;i<SIZEX;i++) {
			for(int j=0;j<SIZEY;j++) {
			greatarr[i][j]=greatest(arr,i,j);
			}
		}
}

void display(int arr[][SIZEY]) {
	cout<<endl;
	for(int i=0;i<SIZEX;i++) {
		for(int j=0;j<SIZEY;j++) {
			if(arr[i][j]/10==0)
				cout<<0<<arr[i][j]<<" ";
			else
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main() {
    	srand(time(NULL));
	int inputimage[SIZEX][SIZEY];
	int outputimage[SIZEX][SIZEY];
	populate(inputimage);
	cout<<"Input:";display(inputimage);
	dissolve(inputimage,outputimage);
	cout<<"Output: ";display(outputimage);
	return 0;
}

