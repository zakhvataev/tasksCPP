#include "BitSet.h"
#include <iomanip>


int main(){
  try{
    BitSet b1("1100101010");
    BitSet b2("0101010101");
    BitSet b3("1110100101");

    std::cout<<"b1: "<< b1 <<std::endl;
    std::cout<<"b2: "<< b2 <<std::endl;

    std::cout<<"b1 AND b2: "<<(b1 & b2)<<std::endl;
    std::cout<<"b1 OR b2: "<< (b1 | b2)<<std::endl;
    std::cout<<"b1 XOR b2: "<<(b1 ^ b2)<<std::endl;
    std::cout<<"NOT b1: "<<(~b1)<<std::endl;

    std::cout<<"b1 == b2: ";
    std::cout<<std::boolalpha << (b1==b2) << std::endl;
    std::cout<<"b1 != b2: ";
    std::cout<<std::boolalpha << (b1!=b2) << std::endl;
    std::cout<<"b1 < b2: ";
    std::cout<<std::boolalpha << (b1<b2) << std::endl;
    std::cout<<"b1 <= b2: ";
    std::cout<<std::boolalpha << (b1<=b2) << std::endl;
    std::cout<<"b1 > b2: ";
    std::cout<<std::boolalpha << (b1>b2) << std::endl;
    std::cout<<"b1 >= b2: ";
    std::cout<<std::boolalpha << (b1>=b2) << std::endl;
    std::cout<<"\nHere we use [] to out bitset b3\n";
    for(size_t i = 0; i < b3.get_size(); ++i){
      std::cout << b3[i];
    }

    b1 = b3;
    std::cout<<"\n\nb1 = b3: \nb1: " << b1 << "b3: " << b3 << std::endl;

    std::cout<<"b1(6): "<< (b1(6)) << std::endl;
    b3 = (b1>>3);
    std::cout<<b3<<'\n';
  }
  catch(const char *ex){
    std::cerr << ex << std::endl;
  }

  // Раскомментируйте, чтобы проверить ввод
  // std::cin >> b1;
  // std::cout <<"\n"<<b1;
  return 0;
}
