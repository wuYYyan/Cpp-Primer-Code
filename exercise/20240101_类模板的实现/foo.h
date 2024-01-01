#ifndef __FOO_H__
#define __FOO_H__

template <typename T>
class Foo {
    public:
        static T max(const T lhs, const T rhs);
};

template <typename T>
T Foo<T>::max(const T lhs, const T rhs) {
    return lhs > rhs ? lhs : rhs;
}

#endif