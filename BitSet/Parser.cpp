#include "Parser.h"

void Parser::parse(){
  size_t i = 0;
  std::string num = "";
  std::vector<std::string> tokens;
  bool flag = false;
  bool div = false;
  bool check_num = false;

  while(1){
    // Считываем число
    if(exp[i] >= '0' && exp[i] <= '9'){
      bool doub_point = false;
      while((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.'){
        num += exp[i];
        if(exp[i] == '.' && doub_point){
          throw std::string("Bad bumber");
        }
        if(exp[i] == '.' && !doub_point){
          doub_point = true;
        }
        i++;
      }
      i--;
      if(num == "0" && div){
        throw std::string("Division by zero!");
      }
      if(check_num){
        throw std::string("Two numbers cantract");
      }
      tokens.push_back(num);
      flag = true;
      check_num = true;
      doub_point = false;
      num = "";
    }

    // Считываем +
    else if(exp[i] == '+'){
      if(!check_num){
        throw std::string("Two operators contract");
      }
      tokens.push_back("+");
      check_num = false;
      flag = false;
    }
    // Считываем -
    else if(exp[i] == '-'){
      //Бинарный минус
      if(flag){
        if(!check_num){
          throw std::string("Two operators contract");
        }
        check_num = false;
        flag = false;
        tokens.push_back("-");
      }
      //Унарный минус
      else{
        tokens.push_back("m");
        flag = true;
      }
    }
    // Считываем *
    else if(exp[i] == '*'){
      if(!check_num){
        throw std::string("Two operators contract");
      }
      tokens.push_back("*");
      check_num = false;
      flag = false;
    }
    // Считываем /
    else if(exp[i] == '/'){
      tokens.push_back("/");
      if(!check_num){
        throw std::string("Two operators contract");
      }
      check_num = false;
      flag = false;
      div = true;
    }
    //Проверка конца строки
    else if(exp[i] == '\0'){
      break;
    }

    else if(exp[i] == ' ' || exp[i] == '\n' || exp[i] == '\t' || exp[i] == '\r'){}

    else{
      throw std::string("Unknown character in expression: ") + std::string(1,exp[i]);
    }
    i++;
  }

  if (tokens.empty()){
    throw std::string("No tokens found");
  }

  else if((tokens[tokens.size()-1][0] >= '0' && tokens[tokens.size()-1][0] <= '9') &&
            (tokens[0][0] >= '0' && tokens[0][0] <= '9')){
    parsed_str = tokens;
  }
  else{
    throw std::string("Operators on the edge");
  }
}

void Parser::print(){
  int i = 0;
  std::cout << "_________________________" << std::endl;
  std::cout << "Terms:" << std::endl;
  for(const auto& value: parsed_str) {
    if(value[0] == 'm')
      std::cout << i << ". " << "unary -" << std::endl;
    else
      std::cout << i << ". " << value << std::endl;
    ++i;
  }
  std::cout << "Length of vector:" << get_len() << std::endl;
  std::cout << "_________________________" << std::endl;

}
