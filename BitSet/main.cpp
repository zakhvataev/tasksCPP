#include "tree_exp.h"
#include "Parser.h"

void test(const std::string expr){
  std::cout<<"_________________________"<<std::endl;
  std::cout << "Raw string: \"" << expr << "\"" << std::endl;
  Parser p(expr);
  p.parse();
  p.print();
  Node *head = make_tree(p.get(), 0, p.get_len() - 1);
  std::cout << "Recursion print:" << std::endl;
  std::cout << head -> print_term() << std::endl;
  std::cout<<"_________________________"<<std::endl;
  std::cout << "Answer of Tree: " << head -> Evaluate() << std::endl;
  std::cout<<"_________________________"<<std::endl;
  delete head;
}

int main(){
  try{
    test("1 - -2*4+-5");
    test("1-2+3.08540+24-7*2/8+-4.2222");
  }
  catch(const std::string ex){
      std::cerr << ex << std::endl;
  }

  return 0;
}
