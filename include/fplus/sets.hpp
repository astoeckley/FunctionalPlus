// Copyright 2015, Tobias Hermann and the FunctionalPlus contributors.
// https://github.com/Dobiasd/FunctionalPlus
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "fplus/container_common.hpp"

#include <algorithm>
#include <set>
#include <unordered_set>

namespace fplus
{

// API search type: set_includes : (Set a, Set a) -> Bool
// Checks if every element of the second set is also present in the first set.
template <typename SetType>
bool set_includes(const SetType& set1, const SetType& set2)
{
    return std::includes(std::begin(set1), std::end(set1),
        std::begin(set2), std::end(set2));
}

// API search type: set_merge : (Set a, Set a) -> Set a
// Returns the union of two given sets.
template <typename SetType>
SetType set_merge(const SetType& set1, const SetType& set2)
{
    SetType result;
    auto itOut = internal::get_back_inserter(result);
    std::merge(std::begin(set1), std::end(set1),
        std::begin(set2), std::end(set2),
        itOut);
    return result;
}

// API search type: set_intersection : (Set a, Set a) -> Set a
// Returns the intersection of both sets.
template <typename SetType>
SetType set_intersection(const SetType& set1, const SetType& set2)
{
    SetType result;
    auto itOut = internal::get_back_inserter(result);
    std::set_intersection(std::begin(set1), std::end(set1),
        std::begin(set2), std::end(set2),
        itOut);
    return result;
}

// API search type: set_difference : (Set a, Set a) -> Set a
// Returns the elements in set1 that are not present in set2.
template <typename SetType>
SetType set_difference(const SetType& set1, const SetType& set2)
{
    SetType result;
    auto itOut = internal::get_back_inserter(result);
    std::set_difference(std::begin(set1), std::end(set1),
        std::begin(set2), std::end(set2),
        itOut);
    return result;
}

// API search type: set_symmetric_difference : (Set a, Set a) -> Set a
// Returns the symmetric difference of both sets.
template <typename SetType>
SetType set_symmetric_difference(const SetType& set1, const SetType& set2)
{
    SetType result;
    auto itOut = internal::get_back_inserter(result);
    std::set_symmetric_difference(std::begin(set1), std::end(set1),
        std::begin(set2), std::end(set2),
        itOut);
    return result;
}

// API search type: sets_intersection : [Set a] -> Set a
// Returns the intersection of the given sets.
template <typename ContainerIn,
    typename SetType = typename ContainerIn::value_type>
SetType sets_intersection(const ContainerIn& sets)
{
    return fold_left_1(set_intersection<SetType>, sets);
}

} // namespace fplus
