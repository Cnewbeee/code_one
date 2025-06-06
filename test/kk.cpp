#include <iostream>
using namespace std;

//颜色类 
class Color {
	public:
		Color(int n,int **a,int *x,int sum);
		bool ifOk(int node);
		void Dfs(int node);
		int n;		//顶点数
		int m;		//可用颜色数
		int **a;	//邻接矩阵
		int *x;		//解向量
		int sum;	//可着色方案数
};

//构造函数 
Color::Color(int n,int **a,int *x,int sum){
	this->n=n;
	this->a=a;
	this->x=x;
	this->sum=sum;		
}

//判断顶点node是否可以涂色 
bool Color::ifOk(int node) {
	for (int i = 1; i <= n; i++) 
		if ((a[node-1][i-1] == 1) && x[node] == x[i])
			return false;
	return true;
}

//深度优先搜索 
void Color::Dfs(int node) {
	//当访问到叶子结点，则找到一种可着色方案 sum++
	if (node > n) {
		sum++;
		//输出该涂色方案 
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << endl;
	}
	//递归 
	else {
		for (int i = 1; i <= m; i++) {
			x[node] = i;
			if (ifOk(node))
				Dfs(node + 1);
			x[node] = 0;
		}
	}
}

int main() {
	//初始化邻接矩阵 
	int** graph=new int*[13];
	for(int i=0;i<13;i++)
		graph[i]=new int[13];
	for (int i = 0;i < 13;i++)
		for (int j = 0;j < 13;j++)
			cin >> graph[i][j];
	
	//初始化解向量 
	int* p=new int[14];
	for(int i=0;i<14;i++)
		p[i]=0;
	
	//初始化颜色类 
	Color color(13,graph,p,0);
	
	//涂色 
	int k=0;
	while(true){
		k++;
		color.m=k;
		color.Dfs(1);
		if(color.sum!=0)
			break;
	}
	
	//输出最小颜色数和涂色方案数 
	cout<<"最小颜色数m为："<<k<<endl; 
	cout<<"可行的涂色方案数为："<<color.sum;
}
