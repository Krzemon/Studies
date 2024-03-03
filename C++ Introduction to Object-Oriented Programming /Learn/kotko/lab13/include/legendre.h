#ifndef LEGENDRE
#define LEGENDRE

#include <cmath>
#include <utility>

class Legendre : public Polynomial{

public:
  Legendre(int n) : Polynomial(n){
    for(int i = n%2; i<=n; i+=2){
      coefs_[i] = (double)pow(-1, (n-i)/2) / (double)pow(2,n);
      coefs_[i] *= (double) std::tgamma(n+i+1);
      coefs_[i] /= (double) std::tgamma((n-i)/2 + 1);
      coefs_[i] /= (double) std::tgamma((n+i)/2 + 1);
      coefs_[i] /= (double) std::tgamma(i + 1);
    }
  }

  Legendre(const Legendre &p) : Polynomial(p.n_){
    for(int i = 0; i<=n_; i++){
      coefs_[i] = p.coefs_[i];
    }
  }

  Legendre(Legendre &&p) : Polynomial(std::move(p.n_)){
    n_ = std::move(p.n_);
    coefs_ = std::exchange(p.coefs_, nullptr);
  }

  Legendre operator =(Legendre &p){
    return this->operator=(p);
  }

  Legendre operator =(Legendre &&p){
    return this->operator=(std::move(p));
  }

};

#endif
