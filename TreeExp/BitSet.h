#include <iostream>
#include <cstdint>

class BitSet{
private:
  uint64_t size = 1;
  uint64_t *bs = NULL; //here we save our bits
public:
  BitSet(const std::string s = "0");
  BitSet(const BitSet &copy);

  BitSet& operator=(const BitSet &right);

  //Логические операторы
  BitSet operator&(const BitSet& right)const;
  BitSet& operator&=(const BitSet& right);
  BitSet operator|(const BitSet& right)const;
  BitSet& operator|=(const BitSet& right);
  BitSet operator^(const BitSet& right)const;
  BitSet& operator^=(const BitSet& right);
  BitSet operator~()const;

  //Операторы смещения
  BitSet operator>>(const size_t& shift)const;
  BitSet& operator>>=(const size_t& shift);
  BitSet operator<<(const size_t& shift)const;
  BitSet& operator<<=(const size_t& shift);

  //Чтение бита из массива
  uint64_t operator[](const size_t index)const;
  //Запись бита в массив
  uint64_t& operator[](const size_t index);

  //Оператор заполняет 0ми все до смещения, 1ми посл
  uint64_t  operator()(const size_t shift)const;
  uint64_t& operator()(const size_t shift);

  //Операторы сравнения
  friend bool operator==(const BitSet&, const BitSet&);
  friend bool operator!=(const BitSet&, const BitSet&);
  friend bool operator <(const BitSet&, const BitSet&);
  friend bool operator<=(const BitSet&, const BitSet&);
  friend bool operator >(const BitSet&, const BitSet&);
  friend bool operator>=(const BitSet&, const BitSet&);

  //Ввод и вывод
  friend std::ostream& operator<< (std::ostream &out, const BitSet &bits);
  friend std::istream& operator>> (std::istream &out, BitSet &bits);

  uint64_t get_size(){return size;}

  ~BitSet(){delete []bs;}
};
