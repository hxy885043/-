/*
	POJ(2236)-无线网络
	题目描述：由于地震多台电脑损坏，且网络中断。在修复网络的过程中，维修者可以进行两种操作，一是维修电脑，
	二是测试两台电脑之间是否可以联网。若两台已修好电脑之间的距离小于d，则可认为这两台电脑可以进行联网，同时，若
	A与B可以联网，B与C可以联网，则A与C可以联网。
	输入：给出一系列电脑坐标及维修员的操作
	输出：测试两台电脑是否联网成功
	算法：并查集
*/

// iostream是C++的输入输入，cstdio是C的输入输出，内容在std中
#include <iostream>
#include <cstdio>

using namespace std;

// n表示电脑台数，d表示最大联网距离
// x,y数组表示电脑坐标
// fa数组：每个元素的父节点
// fxd数组：每个元素是否都进行合并过
int n,d;
int x[1010], y[1010];
int fa[1010];
bool fxd[1010];

// 判断A电脑与B电脑是否联网
// 若两坐标距离小于等于d，则返回true，否则false
bool close(int a, int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=d*d;
}

// 找到A电脑的父节点
int find(int a){
	if(fa[a] != a){
		fa[a] = find(fa[a]);
	}
	return fa[a];
}

// A电脑与B电脑合并，即把b节点的父节点（b所在子集）赋值给a父节点的父节点（a所在子集）
void merge(int a, int b){
	fa[find(a)] = find(b);
}


int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		// 并查集：初始化元素，每个元素为一个集合，其父节点为它自己
		fa[i] = i;
	}

    // op数组表示操作
	char op[5];
	int a,b;
	while(scanf("%s", op)!=EOF){
		// 将维修好的电脑合并到子集中去
		if(op[0] == 'O'){
			scanf("%d", &a);
			// 判断是否已经进行合并
			if(!fxd[a]){
				fxd[a] = true;
				// 遍历所有节点，判断是否需要进行合并
				for (b=1;b<=n;++b){
					if(!fxd[b]) continue;
					if(find(a) == find(b)) continue;
					if(close(a, b)){
						merge(a, b);
					}
				}
			}
		}
		else{
			scanf("%d%d", &a, &b);
			if(find(a) == find(b)){
				printf("SUCCESS\n");
			}
			else{
				printf("FAIL\n");
			}
		}

	}
	return 0;
}