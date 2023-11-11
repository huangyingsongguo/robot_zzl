#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int nandu,tishu;
	cout<<"请输入题数："; 
	cin>>tishu;
	cout<<"请输入难度(1为100以内，2为1000以内，3为10000以内)：";
	cin>>nandu;
	int a[tishu],b[tishu],c[tishu],d[tishu];
	int x,y=0,z,w;
	if(nandu==1){
		w=100;
	}
	if(nandu==2) w=1000;
	if(nandu==3) w=10000;
	srand((unsigned)time(NULL));
	for(int i=0;i<tishu;i++){
		a[i]=rand()%w;
		b[i]=rand()%w;
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
	for(int i=0;i<tishu;i++){
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







