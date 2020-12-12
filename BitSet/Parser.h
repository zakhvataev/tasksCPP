#include <string>
#include <vector>
#include <iostream>

class Parser{
private:
  const std::string exp = "";
  std::vector<std::string> parsed_str = {};
public:
  Parser(const std::string &str) : exp(str){}

  void parse();

  void print();

  const size_t get_len() const {return parsed_str.size();}

  const std::vector<std::string> get() const {return parsed_str;}

};
