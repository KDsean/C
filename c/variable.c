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