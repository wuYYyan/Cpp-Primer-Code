#include "foo.h"

template int Foo<int>::max(const int lhs, const int rhs);
template double Foo<double>::max(const double lhs, const double rhs);