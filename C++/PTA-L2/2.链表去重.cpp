#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef struct Node
{
	int key;
	int nextid;
}node;
int main()
{
	node no[100000];//存放原始链表 
	int n,r1=0,r2=0,id,h1;
	int key[100000]={0},nextid[100000],nextid1[100000];//key数组表示是否遇到过此key绝对值，nextid存放去重后ID，nextid1存放去掉的ID 
	cin>>h1>>n;
	for(int i=0;i<n;i++)
	{
		cin>>id;
		cin>>no[id].key>>no[id].nextid;
	}
	while(h1!=-1)//遍历链表 
	{
		if(key[abs(no[h1].key)])//如果key绝对值遇到过，将当前ID放入数组nextid1中 
		{
			nextid1[r2++]=h1;
			nextid1[r2]=-1;//使存放当前ID的下一个数组元素等于-1，为输出准备 
			h1=no[h1].nextid;//改变h1使得链表向后遍历 
		}
		else//否则将ID放入数组nextid中 
		{
			key[abs(no[h1].key)]=1;
			nextid[r1++]=h1;
			nextid[r1]=-1;
			h1=no[h1].nextid;
		}
	}
	for(int i=0;i<r1;i++)//遍历输出key值去重后的链表 
	{
		if(nextid[i+1]!=-1)
			cout<<setw(5)<<setfill('0')<<nextid[i]<<" "<<no[nextid[i]].key<<" "<<setw(5)<<setfill('0')<<nextid[i+1]<<endl ;
		else//如果nextid[i+1]==-1，则在输出它的时候不需要强制输出五位
			cout<<setw(5)<<setfill('0')<<nextid[i]<<" "<<no[nextid[i]].key<<" "<<nextid[i+1]<<endl ;
	}
	for(int i=0;i<r2;i++)//遍历输出去掉的链表 
	{
		if(nextid1[i+1]!=-1)
			cout<<setw(5)<<setfill('0')<<nextid1[i]<<" "<<no[nextid1[i]].key<<" "<<setw(5)<<setfill('0')<<nextid1[i+1]<<endl ;
		else
			cout<<setw(5)<<setfill('0')<<nextid1[i]<<" "<<no[nextid1[i]].key<<" "<<nextid1[i+1]<<endl ;
	}
 	return 0;
}
