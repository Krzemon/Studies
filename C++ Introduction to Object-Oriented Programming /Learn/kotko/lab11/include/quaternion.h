#ifndef H_QUATERNION
#define H_QUATERNION

#include <utility>
#include <iostream>

class Quaternion{
private:
  const int D = 3;
  const char* Dc = "ijk";
  double S;
  double *V;

public:
  Quaternion() : S(0), V(new double[D]{0}) {}
  Quaternion(double a, double x, double y, double z) :
      S(a), V(new double[D]{x,y,z}) {}

  ~Quaternion(){
    std::cout << "[-] destruktor" << std::endl;
    delete[] V;
  }

  Quaternion(Quaternion &q){
    std::cout << "[-] kopiowanie" << std::endl;
    S = q.S;
    V = new double[D];
    for(int i = 0; i<D; i++){
      V[i] = q.V[i];
    }
  }
  Quaternion(Quaternion &&q){
    std::cout << "[-] przenoszenie" << std::endl;
    S = std::move(q.S);
    V = std::exchange(q.V, new double[D]);
  }


  Quaternion& operator=(const Quaternion &q){
    std::cout << "[-] przepisanie" << std::endl;
    if(this == &q){
      return *this;
    }
    this->S = q.S;
    for(int i = 0; i<D; i++){
      this->V[i] = q.V[i];
    }
    return *this;
  }

  Quaternion& operator=(Quaternion &&q){
    std::cout << "[-] przepisanie 2" << std::endl;
    if(this == &q){
      return *this;
    }

    std::swap(this->S, q.S);
    std::swap(this->V, q.V);
    return *this;
  }

  Quaternion& operator+=(const Quaternion &q){
    S += q.S;
    for(int i = 0; i<D; i++){
      V[i] += q.V[i];
    }
    return *this;
  }

  void print(){
    std::cout << S << " + ";
    for(int i = 0; i<D; i++){
      std::cout << V[i] << Dc[i];
      if(i<D-1)  std::cout << " + ";
    }
    std::cout << std::endl;
  }
};

inline Quaternion operator+(const Quaternion &a, const Quaternion &b){
  Quaternion ret;
  ret += a;
  ret += b;
  return ret;
}

#endif
