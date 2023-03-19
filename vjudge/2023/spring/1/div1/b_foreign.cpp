#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
 using  namespace std;
 int a[ 50 ],flag[ 50 ];
 int main(){
     int n ;
     while (~scanf( " %d " ,& n)){
          memset(flag, 0 , sizeof (flag));
          for ( int i= 0 ;i<n;i++ ){
             scanf( " %d " ,&a [i]);
              flag[i]= 1 ;
          }
          sort(a,a+ n);
          if (n<= 2 )printf( " 0\n " );
          else {
              int num= 0 ;
              for ( int i= 0 ;i<n;i++ ){
                  for ( int j= i+1 ;j<n;j++ ){
                      for( int k= j+1 ;k<n;k++ ){
                          if (flag[i]== 1 &&flag[j]== 1 &&flag[k]== 1 &&a[i] +a[j]>a[k]){
                              num++;flag[i]= 0 ; flag[j]= 0 ;flag[k]= 0 ;
                          }
                          else  continue ;
                      }
                  }
              }
              printf( "%d\n ",num);
          }
      }
      return  0 ;
 }