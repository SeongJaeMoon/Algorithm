
#include<iostream>
#include<math.h>
#include<String>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
//동적 계획법.
int memo[40] = {1,1,};

int fibonacci(int n){
   if ( n <= 1) return memo[n];
   else {
      if(memo[n] > 0) return memo[n];
   }
   return memo[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(void){
   int T; //testCase
   std::cout << "피보나치 수열 동적계획법 테스트" << endl;
   std::cin >> T;
   for(int i = 0 ; i < T ;i++){
      int temp = T;
      if (temp == 0) printf_s("1 0\n");
      else if(temp == 1) printf_S("0 1\n");
      else{
         fibonacci(temp);
         std::cout << memo[temp-2] << "" << memo[temp-1];
      }
   }
   return 0;
}
//재귀 함수.
int one, zero;

int fibonacci(int n){
   int result = 0;
   if(n == 0){
      zero++;
      return zero;
   }else if(n == 1){
      one++;
      return one;
   }else{
      return fibonacci(n-1)+fibonacci(n-2);
   }
}
int main(void){
   int T; //testCase
   sdt::cout << "피보나치 수열 재귀함수 테스트"
   std::cin >> T >> endl;
   if(T>40||T<0){
      cout << "테스트 케이스의 값은 40보다 작거나 0보다 커야합니다."<<endl;
   }else{
      for(int i = 0; i < T; i++){
      fibonacci(T);         
      std::cout << zero << "" << result;
      }   
   }
   return 0;
}