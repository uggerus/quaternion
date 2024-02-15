#include <type_traits>

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;



template<Arithmetic Scalar>
class quaternion {
public:
  constexpr quaternion(const Scalar& real ={}, const Scalar& i = {}, const Scalar& j = {}, const Scalar& k = {});
  constexpr quaternion( const quaternion& other ) = default;

  constexpr Scalar real() const {
    return real;
  }
  constexpr void real(Scalar z) {
    real = z;
  }

  constexpr Scalar i() const {
    return i;
  }
  constexpr void i(Scalar z) {
    i = z;
  }

  constexpr Scalar j() const {
    return j;
  }
  constexpr void j(Scalar z) {
    j = z;
  }

  constexpr Scalar k() const {
    return k;
  }
  constexpr void k(Scalar z) {
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
  constexpr quaternion& operator/=(const quaternion& z);

};
