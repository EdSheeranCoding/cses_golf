main(){long n;scanf("%ld",&n);while(n>1){printf("%ld ",n);n=n%2?3*n+1:n>>1;}puts("1");}
