h(d,f,t,v){d&&(h(d-1,f,v,t),printf("%d %d\n",f,t),h(d-1,v,t,f));}
main(n){scanf("%d",&n);printf("%d\n",(1<<n)-1);h(n,1,3,2);}