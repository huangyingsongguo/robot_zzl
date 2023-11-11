#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int a[10],b[10],c[10],d[10];
	int x,y=0,z;
	srand((unsigned)time(NULL));
	for(int i=0;i<=9;i++){
		a[i]=rand()%100;
		b[i]=rand()%100;
		c[i]=rand()%2;
		if(c[i]==1){
			int t;
			cout<<a[i]<<"+"<<b[i]<<"=";
			cin>>t;
			if(t==a[i]+b[i]){
				x++;
				d[i]=0;
			} 
			else{
				 y++;
			    d[i]=1;
			}
		}
		if(c[i]==0){
			int t;
			if(a[i]<b[i]){
				z=a[i];
				a[i]=b[i];
				b[i]=z;
			}
			cout<<a[i]<<"-"<<b[i]<<"=";
			cin>>t;
			if(t==a[i]-b[i]){
				x++;
				d[i]=0;
			}
			else{
				 y++;
			    d[i]=1;
			}
		}
	}
	cout<<"正确数="<<x<<" "<<"错误数="<<y<<endl;
	for(int i=0;i<10;i++){
		if(c[i]==1&&d[i]==1){
		    int t=a[i]+b[i];
		    cout<<a[i]<<"+"<<b[i]<<"="<<t<<endl;
		}
		if(c[i]==0&&d[i]==1){
		    int t=a[i]-b[i];
		    cout<<a[i]<<"-"<<b[i]<<"="<<t<<endl;
		}
		
	}
}







