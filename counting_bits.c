long long n,a,k=1,m,r,c;
main(){for(scanf("%lld",&n),m=n+1;k<=n;k<<=1)r=m%(c=k<<1)-k,a+=m/c*k+(r>>63?0:r);printf("%lld",a);}