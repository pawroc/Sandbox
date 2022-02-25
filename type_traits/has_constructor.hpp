#pragma once

#include <utility>

template<class T>
using copy_construct_t = decltype(T(std::declval<T const&>()));

template<class T, class = void>
struct is_copy_constructable : std::false_type {};

template<class T>
struct is_copy_constructable<T, std::void_t<copy_construct_t<T>>>
    : std::true_type {};

template<class T>
using construct_t = decltype(T());

template<class T, class = void>
struct is_constructable : std::false_type {};

template<class T>
struct is_constructable<T, std::void_t<construct_t<T>>>
    : std::true_type {};