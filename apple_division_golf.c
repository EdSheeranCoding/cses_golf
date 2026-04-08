a[20],n,i,m,x;long long s,b=1LL<<62;
main(){for(scanf("%d",&n);i<n;)scanf("%d",a+i),s+=a[i++];for(m=1<<n;m--;){for(x=i=0;i<n;i++)x+=(m>>i&1)*a[i];x=s-2*x;if(x<0)x=-x;if(b>x)b=x;}printf("%lld",b);}