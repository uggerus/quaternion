#include type_traits

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;



template<Arithmetic Scalar>
class quaternion {
 public:
  quaternion(const Scalar& real ={}, const Scalar& i = {}, const Scalar& j = {}, const Scalar& k = {});
  



  




};
