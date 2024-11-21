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
s(n){
	int i;
	if (n>0){
		s(n-1);

	}
	for(i=1;i<=n;i++){
		printf("%d",n);
	}
	printf("\n");

}
f(n){
	for(int i=1;i<=n;i++){
		printf("%d",n);
	}
	printf("\n");
	if (n>0){
		f(n-1);
	}

}
int main(){
	int n =10;
	s(n);
	f(n);

}
