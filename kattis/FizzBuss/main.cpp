#include "string"
#include "iostream"

int main() {
   int x,y,num;
   std::cin >> x;
   std::cin >> y;
   std::cin >> num;

   for (int i = 1; i <= num; i++) {
       if (i%x==0 && i%y==0) {
           std::cout << "FizzBuzz" << std::endl;
       } else if (i%x==0) {
           std::cout << "Fizz" << std::endl;
       } else if (i%y==0) {
           std::cout << "Buzz" << std::endl;
       } else {
           std::cout << i << std::endl;
       }
   }
   return 0;


}