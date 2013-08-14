#if !defined ITERATOR_TRAITS_ALIASES_HPP_INCLUDED
#define      ITERATOR_TRAITS_ALIASES_HPP_INCLUDED

#include <iterator_traits.hpp>

namespace aliases {

template<class I>
using iterator_traits_value_type = typename iterator_traits<I>::value_type;

template<class I>
using iterator_traits_reference = typename iterator_traits<I>::reference;

template<class I>
using iterator_traits_pointer = typename iterator_traits<I>::pointer;

template<class I>
using iterator_traits_difference_type = typename iterator_traits<I>::difference_type;

template<class I>
using iterator_traits_category = typename iterator_traits<I>::iterator_category;

} // namespace aliases

#endif    // ITERATOR_TRAITS_ALIASES_HPP_INCLUDED
