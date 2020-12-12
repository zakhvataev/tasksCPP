#include <iostream>
#include <vector>
#include <string>

/* Базовый класс для узла дерева выражения. */
class Node {

public:
  /* Метод служит для вычисления значения составленного дерева выражения.
     Этот метод вызывается рекурсивно от корня к листьям. */
  virtual double Evaluate() const = 0;
  virtual std::string print_term() const = 0;
  virtual ~Node() {
  }
};

// Предполагаем, что в качестве

class Value : public Node {
 private:
  double value = 0;
 public:
  Value(double value){
    this -> value = value;
  }
  /* Этот метод возвращает само число, записанное в узле дерева. */
  double Evaluate() const override{
    return this -> value;
  }

  std::string print_term() const override{return std::to_string(this->value);}

};


class BinaryOperation : public Node {
protected:
  Node* left = NULL;
  Node* right = NULL;
 public:
   BinaryOperation& operator=(const BinaryOperation&) = delete;
   BinaryOperation(const BinaryOperation&) = delete;
   BinaryOperation(Node* left, Node* right){
    this -> left = left;
    this -> right = right;
  }
  ~BinaryOperation(){
    delete left;
    delete right;
  }
};

class UnaryOperation : public Node {
 protected:
  Node* argument = NULL;
 public:
  UnaryOperation& operator=(const UnaryOperation&) = delete;
  UnaryOperation(const UnaryOperation&) = delete;
  UnaryOperation(Node* argument){
    this -> argument = argument;
  }
  ~UnaryOperation(){
    delete argument;
  }
};

class Addition : public BinaryOperation {
 public:
  Addition(Node* left, Node* right) : BinaryOperation(left, right){}

  /* Метод возвращает результат операции сложения для своих аргументов. */
  double Evaluate() const override{
    return (left -> Evaluate() + right -> Evaluate());
  }

  std::string print_term() const override{
    return left -> print_term() + "+" + right -> print_term();
  }

};

class Subtraction : public BinaryOperation {
 public:
  Subtraction(Node* left, Node* right) : BinaryOperation(left, right){}

  /* Метод возвращает результат операции вычитания для своих аргументов. */
  double Evaluate() const override{
    return (left -> Evaluate() - right -> Evaluate());
  }

  std::string print_term() const override{
    return left -> print_term() + "-" + right -> print_term();
  }
};

class Multiplication : public BinaryOperation {
 public:
  Multiplication(Node* left, Node* right) : BinaryOperation(left, right){}

  /* Метод возвращает результат операции умножения для своих аргументов. */
  double Evaluate() const override{
    return (left -> Evaluate() * right -> Evaluate());
  }

  std::string print_term() const override{
    return left -> print_term() + "*" + right -> print_term();
  }
};

class Division : public BinaryOperation {
 public:
  Division(Node* left, Node* right) : BinaryOperation(left, right){}

  /* Метод возвращает результат операции деления для своих аргументов. */
  double Evaluate() const override{
    return (left -> Evaluate() / right -> Evaluate());
  }

  std::string print_term() const override{
    return left -> print_term() + "/" + right -> print_term();
  }
};

class Negation : public UnaryOperation {
 public:
  Negation(Node* argument) : UnaryOperation(argument){}

  /* Метод возвращает результат операции унарный минус для своего аргумента. */
  double Evaluate() const override{
    return -(argument -> Evaluate());
  }

  std::string print_term() const override{
    return "(-" + argument -> print_term() + ")";
  }
};

int get_priority(char);

Node* make_tree(std::vector<std::string>, size_t, size_t);
