#pragma once

#include <utility>

template<class T>
using copy_assignment_t = decltype(std::declval<T&>() = std::declval<T const&>());

template<class T, class = void>
struct is_copy_assignable : std::false_type {};

template<class T>
struct is_copy_assignable<T, std::void_t<copy_assignment_t<T>>> 
    : std::is_same<copy_assignment_t<T>, T&> {};
