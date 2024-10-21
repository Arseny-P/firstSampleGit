#include <iostream>
#include <cmath>

int factorial(int i)
{
  if (i == 0) return 1;
  else return i * factorial(i - 1);
}

int main(){
    double x = 0;
    int n = 0;
    std::cout << "Please, write x: ";
    std::cin >> x;
    std::cout << "Please, write a count of adds: ";
    std::cin >> n;
    std::cout << std::endl;
    double res = 0;
    for(int i = 0; i < n; ++i){
        if(i%2==0) res += (std::pow(x, 2*i+1))/factorial(2*i + 1);
        else res -= (std::pow(x, 2*i+1))/factorial(2*i + 1);        
    }
    std::cout << res;

    return 0;
}