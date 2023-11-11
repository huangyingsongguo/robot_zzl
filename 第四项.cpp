#include<iostream>
#include<cstdlib>
#include<windows.h> 
#include<cstdlib>
#include<ctime>
using namespace std;
void fun(){
	int nandu,tishu;
	cout<<"请输入题数："; 
	cin>>tishu;
	cout<<"请输入难度(1为100以内，2为1000以内，3为10000以内)：";
	cin>>nandu;
	int a[tishu],b[tishu],c[tishu],d[tishu];
	double e[tishu];
	int x,y=0,z,w;
	double time1;
	LARGE_INTEGER t1,t2,tc;
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
			
            QueryPerformanceFrequency(&tc);
            QueryPerformanceCounter(&t1);
			cin>>t;
			QueryPerformanceCounter(&t2);
            time1=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
            e[i]=time1;
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
		
            QueryPerformanceFrequency(&tc);
            QueryPerformanceCounter(&t1);
			cin>>t;
			QueryPerformanceCounter(&t2);
            time1=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
            e[i]=time1;
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
	double avg=0,min=e[0];
	for(int i=0;i<tishu;i++){
		avg=avg+e[i];
		if(e[i]>e[i+1]&&i<tishu-1) min=e[i+1];
	}
	avg=avg/tishu;
	cout<<"平均用时:"<<avg<<"s"<<" "<<"最短用时:"<<min<<"s";
}
int main(){
    fun();
	return 0;
}







