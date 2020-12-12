#include "BitSet.h"

//Конструктор
BitSet :: BitSet(const std::string s){
  size = s.length();
  bs = new uint64_t[size];
  for(size_t i = 0; i < size; ++i){
    if(s[i] - '0' == 0){
      bs[i] = 0;
    }
    else if(s[i] - '0' == 1){
      bs[i] = 1;
    }
    else{
      throw "BitSet must contain only 0 and 1";
    }
  }
}

//Оператор копирования
BitSet ::BitSet(const BitSet &copy){
  try{
    size = copy.size;
    bs = new uint64_t[size];
  }
  catch(std::bad_alloc& ba){
    std::cerr << ba.what() << std::endl;
  }
  for(size_t i = 0; i < size; ++i){
    bs[i] = copy.bs[i];
  }
}

//Оператор присваивания
BitSet& BitSet :: operator=(const BitSet &right){
  delete []bs;
  try{
    size = right.size;
    bs = new uint64_t[size];
  }
  catch(std::bad_alloc& ba){
    std::cerr << ba.what() << std::endl;
  }
  if(&right != this){
    for(size_t i = 0; i < size; ++i){
      bs[i] = right.bs[i];
    }
  }
  return *this;
}

uint64_t BitSet :: operator[](const size_t index)const{
  if(index > size){
    throw "op []: Out of range";
  }
  return bs[index];
}
uint64_t& BitSet :: operator[](const size_t index){
  if(index > size){
    throw "op []: Out of range";
  }
  return bs[index];
}

uint64_t BitSet :: operator()(const size_t shift)const{
  if(shift > size){
    throw "op (): Out of range";
  }
  return bs[shift];
}

uint64_t& BitSet :: operator()(const size_t shift){
  if(shift > size){
    throw "op (): Out of range";
  }

  return bs[shift];
}

BitSet BitSet :: operator&(const BitSet& right)const{
  if(size != right.size){
    throw "op &: Different lengths";
  }
  BitSet res(*this);

  for(size_t i = 0; i < size; ++i){
    res[i] = bs[i] & right[i];
  }
  return res;
}

BitSet& BitSet :: operator&=(const BitSet& right){
  if(size != right.size){
    throw "op &=: Different lengths";
  }

  for(size_t i = 0; i < size; ++i){
    bs[i] &= right[i];
  }
  return *this;
}

BitSet BitSet :: operator|(const BitSet& right)const{
  if(size != right.size){
    throw "op |: Different lengths";
  }
  BitSet res(*this);

  for(size_t i = 0; i < size; ++i){
    res[i] = bs[i] | right[i];
  }
  return res;
}

BitSet& BitSet :: operator|=(const BitSet& right){
  if(size != right.size){
    throw "op |=: Different lengths";
  }

  for(size_t i = 0; i < size; ++i){
    bs[i] |= right[i];
  }
  return *this;
}

BitSet BitSet :: operator^(const BitSet& right)const{
  if(size != right.size){
    throw "op ^: Different lengths";
  }
  BitSet res(*this);

  for(size_t i = 0; i < size; ++i){
    res[i] = bs[i] ^ right[i];
  }
  return res;
}

BitSet& BitSet :: operator^=(const BitSet& right){
  if(size != right.size){
    throw "op ^=: Different lengths";
  }

  for(size_t i = 0; i < size; ++i){
    bs[i] ^= right[i];
  }
  return *this;
}

BitSet BitSet :: operator~()const{
  BitSet res(*this);
  for(size_t i = 0; i < size; ++i){
    if(res[i] == 1){
      res[i] = 0;
    }
    else{
      res[i] = 1;
    }
  }
  return res;
}

BitSet BitSet :: operator>>(const size_t& shift)const{
  if(shift > size){
      throw "op >>: shift > size";
  }

  uint64_t *mass;
  try{
    mass = new uint64_t[size-shift];
  }
  catch(std::bad_alloc& ba){
    std::cerr << ba.what() << std::endl;
  }
  BitSet res(*this);
  
  for(size_t i = 0; i < size - shift; ++i){
    mass[i] = res[i];
  }
  for(size_t i = 0; i < size; ++i){
    if(i < shift){
      res[i] = 0;
    }
    else{
      res[i] = mass[i-shift];
    }
  }

  delete [] mass;

  return res;
}

BitSet& BitSet :: operator>>=(const size_t& shift){
  if(shift > size){
    throw "op >>=: shift > size";
  }
  uint64_t *mass;

  try{
    mass = new uint64_t[size-shift];
  }
  catch(std::bad_alloc& ba){
    std::cerr << ba.what() << std::endl;
  }

  for(size_t i = 0; i < size - shift; ++i){
    mass[i] = bs[i];
  }
  for(size_t i = 0; i < size; ++i){
    if(i < shift){
      bs[i] = 0;
    }
    else{
      bs[i] = mass[i-shift];
    }
  }
  delete [] mass;
  return *this;
}

BitSet BitSet :: operator<<(const size_t& shift)const{
  if(shift > size){
    throw "op <<: shift > size";
  }
  uint64_t *mass;
  try{
    mass = new uint64_t[size-shift];
  }
  catch(std::bad_alloc& ba){
    std::cerr << ba.what() << std::endl;
  }

  BitSet res(*this);

  for(size_t i = shift; i < size; ++i){
    mass[i-shift] = res[i];
  }
  for(size_t i = 0; i < size; ++i){
    if(i < size - shift){
      res[i] = mass[i];
    }
    else{
      res[i] = 0;
    }
  }

  delete [] mass;
  return res;
}

BitSet& BitSet :: operator<<=(const size_t& shift){
  if(shift > size){
    throw "op <<=: shift > size";
  }

  uint64_t *mass;
  try{
    mass = new uint64_t[size-shift];
  }
  catch(std::bad_alloc& ba){
    std::cerr << ba.what() << std::endl;
  }

  for(size_t i = shift; i < size; ++i){
    mass[i-shift] = bs[i];
  }
  for(size_t i = 0; i < size; ++i){
    if(i < size - shift){
      bs[i] = mass[i];
    }
    else{
      bs[i] = 0;
    }
  }
  delete [] mass;
  return *this;
}

bool operator==(const BitSet &bits1, const BitSet &bits2){
  if(bits1.size != bits2.size){
    return false;
  }

  for(size_t i = 0; i < bits1.size; ++i){
    if(bits1[i] != bits2[i]){
      return false;
    }
  }
  return true;
}

bool operator!=(const BitSet &bits1, const BitSet &bits2){
  if(bits1.size != bits2.size){
    return true;
  }

  for(size_t i = 0; i < bits1.size; ++i){
    if(bits1[i] != bits2[i]){
      return true;
    }
  }
  return false;
}

bool operator<(const BitSet &bits1, const BitSet &bits2){
  if(bits1.size < bits2.size){return true;}

  else if(bits1.size >= bits2.size){return false;}

  else{
    for(size_t i = 0; i < bits1.size; ++i){
      if(bits1[i] < bits2[i]){
        return true;
      }
      if(bits1[i] > bits2[i]){
        return false;
      }
    }
  }
  return false;
}

bool operator<=(const BitSet &bits1, const BitSet &bits2){
  if(bits1.size < bits2.size){return true;}

  else if(bits1.size > bits2.size){return false;}

  else{
    for(size_t i = 0; i < bits1.size; ++i){
      if(bits1[i] < bits2[i]){
        return true;
      }
      if(bits1[i] > bits2[i]){
        return false;
      }
    }
  }
  return true;
}

bool operator>(const BitSet &bits1, const BitSet &bits2){
  if(bits1.size > bits2.size){return true;}

  else if(bits1.size <= bits2.size){return false;}

  else{
    for(size_t i = 0; i < bits1.size; ++i){
      if(bits1[i] > bits2[i]){
        return true;
      }
      if(bits1[i] < bits2[i]){
        return false;
      }
    }
  }
  return false;
}

bool operator>=(const BitSet &bits1, const BitSet &bits2){
  if(bits1.size > bits2.size){return true;}

  else if(bits1.size < bits2.size){return false;}

  else{
    for(size_t i = 0; i < bits1.size; ++i){
      if(bits1[i] > bits2[i]){
        return true;
      }
      if(bits1[i] < bits2[i]){
        return false;
      }
    }
  }
  return true;
}


std::ostream& operator<< (std::ostream &out, const BitSet &bits){

  out<<"BITSET = [";

  for(size_t i = 0; i < bits.size; ++i){

     out << bits.bs[i];
  }
     out<<"]\n";

  return out;
}

std::istream& operator>> (std::istream &in, BitSet &bits){
  uint64_t new_size;
  std::cout<<"You want to create new BitSet\nEnter the size: ";
  in>>new_size;
  try{  
    bits.size = new_size;
    bits.bs = new uint64_t[bits.size];
  }
  catch(std::bad_alloc& ba){
    std::cerr << ba.what() << std::endl;
  }

  delete [] bits.bs;

  std::cout<<"Enter BitSet, using space: ";

  for(size_t i = 0; i < bits.size; ++i){
    in >> bits.bs[i];
  }

  return in;
}
