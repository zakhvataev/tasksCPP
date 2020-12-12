#include "tree_exp.h"

//Получение приоритетов операций
int get_priority(char c){
  switch (c){
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case 'm':
      return 3;
      default:
          break;

  }
  return 100;
}

//Составление дерева выражения без унарной(пока что)
// first - левая граница вектора = 0 изначально
// last - правая граница вектора = len(vector)-1 изначально
Node *make_tree(std::vector<std::string> terms, size_t first, size_t last){
  int priority;
  size_t k;

  //Создаем лист - число
  //Сюда попадем только при условии числа
  if(first == last){
    Node *val = new Value(atof(terms[first].c_str()));
    return val;
  }

  Node *op;
  int min_priority = 100;

  // Ищем последнюю операцию, с наименьшим приоритетом
  for(size_t i = first; i < last; ++i){
    priority = get_priority(terms[i][0]);
    if(priority <= min_priority){
      min_priority = priority;
      k = i;
    }
  }

  // Создаем внутреннюю вершину - операцию
  if(terms[k][0] == '+'){
    op = new Addition(make_tree(terms, first, k-1), make_tree(terms, k+1,last));
  }
  if(terms[k][0] == '-'){
    op = new Subtraction(make_tree(terms, first, k-1), make_tree(terms, k+1,last));
  }
  if(terms[k][0] == '*'){
    op = new Multiplication(make_tree(terms, first, k-1), make_tree(terms, k+1,last));
  }
  if(terms[k][0] == '/'){
    op = new Division(make_tree(terms, first, k-1), make_tree(terms, k+1,last));
  }
  // Унарный минус при нашей логике построения всегда
  // попадает в правое поддерево
  if(terms[k][0] == 'm'){
    op = new Negation(make_tree(terms,k+1,last));
  }
  // Самым последним вернется указатель на корень дерева
  return op;
}
