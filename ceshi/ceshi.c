#include <stdio.h>
// #include <string.h>
// /*int main()
// {

//     int a = 10;
// 	int b = a++;
//     //后置加加，先（让B）使用（a的原值），再a加加（加1） 
//      printf("a=%d b=%d\n", a, b);
// }*/





// /*int main()
// {
// 	char arr1[] = "bit";
// 	char arr2[] = "#########";
// 	strcpy(arr2, arr1);
// 	printf("%s\n", arr2);
//     //这里打印的是arr2但是结果确实‘bit’证明arr1的‘bit’被复制到arr2了
// 	return 0;
// }*/


// int main()
// {
// 	"abcdefg";//字符串
// 	"";//空字符串
// 	char arr1[] = "abc";//字符串用途：将字符串放到字符数组里面
// 	//"abc"-- 包含'a' 'b' 'c' '\0'//注意'\0'是字符串的结束标志（隐藏在字符串末尾）
// 	//数据在计算机储存时储存二进制，而#$%等符号使用ASCLL编码
// 	//’0’的值-48(ascll码值）
//     //'a'的值-97
//     //特别注意：'\0'ascll码值是0
// 	printf("%s\n", arr1);//%s打印字符串
// 	printf("%d\n", strlen(arr1));//stelen函数--string length-计算字符串的长度
// }

// 传染算法
// s(n){
// 	if(n<0){
// 		return 0;
// 	}
// 	if(n<=5){
// 		return 1;
// 	}
// 	else{
// 		return s(n-1)+3*(s(n-5)-s(n-10));
// 	}
// }



// int main(){
// 	int n = 60;
// 	int sum;
// 	sum=s(n)-s(n-10);
// 	printf("%d",sum);
// 	return 0;
// }


//数列
// s(n){
// 	int i;
// 	if (n>0){
// 		s(n-1);

// 	}
// 	for(i=1;i<=n;i++){
// 		printf("%d",n);
// 	}
// 	printf("\n");

// }
// f(n){
// 	for(int i=1;i<=n;i++){
// 		printf("%d",n);
// 	}
// 	printf("\n");
// 	if (n>0){
// 		f(n-1);
// 	}

// }
// int main(){
// 	int n =10;
// 	s(n);
// 	f(n);

// }

// int main(){
//     int num = 520;
//     scanf("%d",&num);
//     printf("print(%d)",num);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 //表示最大作业数量
#define M 3 //表示最大盘块数
#define SIZE 1024 //表示每页大小

int num = 0;//表示当前作业数量
int sum = 0;//表示缺页次数
int temp = 0;//表示中间值

//表示盘块的结构体
struct d
{
    int d;//表示盘块是否已分配，“0”表示未分配，“1”代表已分配
    int n;//表示该盘块进入内存的顺序
}disk[M];

//表示作业的结构体
struct j{
    int f;//
    char name[10];//
    int size;//
    int n;//
}JOB[N];

//表示页表的结构体
struct p
{
    int f;
    int pnumber[100];//页号
    int bnumber[100];//该页所在的内存块号
    int io[100];//页表定义
}PAGE[N];

//盘块初始化
void init_disk(){
    int i;
    for(i=0;i<M;i++){
        disk[i].d=0;
        disk[i].n=i;
    }
}

//建立新作业
void Create_Pagi(){
    int temp,i,j;
    int k = 0;
    printf("请输入作业号、作业名及作业长度：");
    scanf("%d%s%d",&JOB[num].f,JOB[num].name,&JOB[num].size);
    temp=(int)(JOB[num].size/1024);
    if(JOB[num].size%1024!=0)
    temp = temp+1;
    JOB[num].n=temp;
    PAGE[num].f = JOB[num].f;
    for(i=0;i<JOB[num].n;i++){
        PAGE[num].pnumber[i]=i;
        PAGE[num].bnumber[i]=0;
        PAGE[num].io[i]=0;
    }
    num++;
    init_disk();
}

//作业调度，进入内存
void in_m(){
    int i,j,k=0;
    char name[10];
    printf("请输入要调度的作业名：");
    scanf("%s",name);
    printf("\n");
    for(i=0;i<N;i++){
        if(strcmp(JOB[i].name,name)==0){
            for(j=0;j<M;j++){
                if(disk[j].d==0&&k<3){
                    disk[j].d=1;
                    PAGE[i].bnumber[k]=j;
                    PAGE[i].io[k]=1;
                    k++;
                }
            }
            sum=sum+3;
            break;
        }
    }
}

void lack_pagi(){
    int i,j,index;//表示下标
    int address;//表示要访问的地址
    int t1,t2;//t1表示页号，t2表示页内偏移
    int flag=0; //是否找到文件的标志
    char name[10];
    printf("请输入要执行的文件名：\n");
    scanf("%s",name);
    for(i=0;i<N;i++){
        if(strcmp(JOB[i].name,name)==0){
            printf("请输入要执行的命令地址：\n");
            scanf("%d",&address);
            printf("\n");
            if(address<JOB[i].size){
                flag=1;
                t1=(int)(address/1024);
                t2=address%1024;
            }
            for(j=0;j<M;j++){
                if(disk[j].n<=temp){
                    temp=disk[j].n;
                    index=j;
                }
            }
            if(t2!=0){//判断所访问地址是否存在偏移量，如果有，则其所在的页编号为t1，否则页编号为t1-1
                PAGE[i].bnumber[t1]=index;
                PAGE[i].io[t1]=1;
                disk[index].n=sum+1;
                for(int i1=0;i1<100;i1++){//修改换出页的页表内容
                    if(PAGE[i].bnumber[i1]==index){
                        PAGE[i].bnumber[i1]=0;
                        PAGE[i].io[i1]=0;
                        break;
                    }
                }
            }
            else{
                PAGE[i].bnumber[t1-1]=index;
                PAGE[i].io[t1-1]=1;
                disk[index].n=sum+1;
                for(int i1=0;i1<100;i1++){
                    if(PAGE[i].bnumber[i1]==index){
                        PAGE[i].bnumber[i1]=0;
                        PAGE[i].io[i1]=0;
                        break;
                    }
                }
            }
        }
    }
    if(flag==0){
        printf("无此作业！\n");
    }
}


//回收作业，释放内存
void Revoke_Pagi(){
    int i,j;
    int k;//表示页编号和块号
    int flag=0;//表示是否找到文件
    char name[10];
    printf("请输入要删除的作业名：");
    scanf("%s",name);
    for(int i=0;i<N;i++){
        if(strcmp(JOB[i].name,name)==0){
            for(k=0;k<JOB[i].n;k++){
                disk[PAGE[i].bnumber[k]].d=0;
                PAGE[i].bnumber[k]=0;
                PAGE[i].pnumber[k]=0;
                PAGE[i].io[k]=0;
            }
            JOB[i].f=0;
            JOB[i].n=0;
            memset(JOB[i].name,'\0',sizeof(JOB[i].name));//将删除的作业名置空
            JOB[i].size=0;
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("无此作业！\n");
    }
}

//显示页表
void Show_page(char name[10]){
    int i,j;
    printf("页表如下：\n");
    printf("作业号 \t 页号 \t 块号 \t 是否在内存 \n");
    for(i=0;i<N;i++){
        if(strcmp(JOB[i].name,name)==0){
            for(j=0;j<JOB[i].n;j++){
                printf("%d\t%d\t%d\t%d\n",PAGE[i].f,PAGE[i].pnumber[j],PAGE[i].bnumber[j],PAGE[i].io[j]);
            }
        }
    }
}

//查看作业
void Look_Pagi(){
    int i,j,flag=0;
    char name[10];
    printf("请输入要查询的作业名：");
    scanf("%s",name);//输入查看的作业名
    printf("\n");
    for(i=0;i<N;i++){
        if(strcmp(JOB[i].name,name)==0)//查找有无要查看的作业
        {
            printf("作业名称 \t 作业长度 \t 所用物理块 \n");
            printf("%s\t\t",JOB[i].name);
            printf("%d\t\t",JOB[i].size);
            for(j=0;j<JOB[i].n;j++){
                printf("%d",PAGE[i].bnumber[j]);
            }
            printf("\n");
            flag=1;
            printf("\n");
            Show_page(name);
        }
    }
    if(flag==0){
        printf("要查询的作业不存在。\n");
    }
    printf("\n");
}

//显示内存块使用情况
void Show_Pagi(){
    printf("内存物理块分配情况 \n");
    for(int i=0;i<M;i++){
        printf("%d\t",disk[i].d);
        if(i%10==9){
            printf("\n");
        }
    }
    printf("\n\n");
}


int main(){
    int i = 0;
    do{
        printf("\t\t欢迎使用计本分页存储管理系统\n");
        printf("\t\t**************************\n");
        printf("\t\t*1.添加作业*\n");
        printf("\t\t*2.回收作业*\n");
        printf("\t\t*3.作业调度*\n");
        printf("\t\t*4.内存占用情况*\n");
        printf("\t\t*5.查看作业*\n");
        printf("\t\t*6.缺页中断*\n");
        printf("\t\t*0.退出程序*\n");
        printf("\t\t**************************\n");
        printf("请输入选项：");
        scanf("%d",&i);
        printf("\n");
        switch(i){
        case 1:
        Create_Pagi(); 
            break;
        case 2:
        Revoke_Pagi;
        break;
        case 3:
        in_m();
        break;
        case 4:
        Show_Pagi();
        break;
        case 5:
        Look_Pagi();
        break;
        case 6:
        lack_pagi();
        break;
        case 0:
        exit(0);
        default:
        printf("输入错误\n");
            break;
        }
    }while(i!=0);
    return 0;
}