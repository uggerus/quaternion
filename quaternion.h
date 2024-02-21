#include <type_traits>

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;



template<Arithmetic Scalar>
class quaternion {
  Scalar real, i, j, k;
public:
    constexpr quaternion(const Scalar& real ={}, const Scalar& i = {}, const Scalar& j = {}, const Scalar& k = {}):
    real{real}, i{i}, j{j}, k{k} {};
  constexpr quaternion( const quaternion& other ) = default;

  constexpr Scalar accessReal() const {
    return real;
  }
  constexpr void accessReal(Scalar z) {
    real = z;
  }

  constexpr Scalar accessI() const {
    return i;
  }
  constexpr void accessI(Scalar z) {
    i = z;
  }

  constexpr Scalar accessJ() const {
    return j;
  }
  constexpr void accessJ(Scalar z) {
    j = z;
  }

  constexpr Scalar accessK() const {
    return k;
  }
  constexpr void accessK(Scalar z) {
    k = z;
  }

  constexpr quaternion& operator=(const quaternion& z) {
    real = z.real;
    i = z.i;
    j = z.j;
    k = z.k;
    return *this;
  }

  constexpr quaternion& operator+=(const quaternion& z) {
    real += z.real;
    i += z.i;
    j += z.j;
    k += z.k;
    return *this;
  }
  
  constexpr quaternion& operator-=(const quaternion& z) {
    real -= z.real;
    i -= z.i;
    j -= z.j;
    k -= z.k;
    return *this;
  }
  constexpr quaternion& operator*=(const quaternion& z){
    real = real * z.real - i * z.i - j * z.j - k * z.k;
    i = real * z.i + i * z.real + j * z.k - k * j;
    j = real * z.j - i * z.k + j * z.real + k * z.i;
    k = real * z.k + i * z.j - j * z.i + k * z.real;
    return *this;
  }
  //constexpr quaternion& operator/=(const quaternion& z);

};

template< class T >
constexpr quaternion<T> operator+(const quaternion<T>& a, const quaternion<T>& b) {
  return a+=b;
}

template< class T >
constexpr quaternion<T> operator-(const quaternion<T>& a, const quaternion<T>& b) {
  return a-=b;
}

template< class T >
constexpr quaternion<T> operator*(const quaternion<T>& a, const quaternion<T>& b) {
  return a*=b;
}

//constexpr quaternion<T> operator/(const quaternion<T>& a, const quaternion<T>& b) {
//  return a/=b;
//}

template< class T >
constexpr bool operator==(const quaternion<T>& a, const quaternion<T>& b) {
  return a.accessReal() == b.accessReal() &&
    a.accessI() == b.accessI() &&
    a.accessJ() == b.accessJ() &&
    a.accessK() == b.accessK();
}

template< class T >
constexpr bool operator!=(const quaternion<T>& a, const quaternion<T>& b) {
  return !(a==b);
}

template<class T>
constexpr quaternion<T> conjugate(const quaternion<T>& x) {
  return {x.accessReal(), x.accessI() * -1, x.accessJ() * -1, x.accessK() * -1};
}

//template< class T>
//constexpr T norm(const quaternion<T>& x) {


//}
