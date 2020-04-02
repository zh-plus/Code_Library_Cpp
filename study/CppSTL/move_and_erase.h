//
// Created by 10578 on 4/2/2020.
//

#ifndef CODE_LIBRARY_MOVE_AND_ERASE_H
#define CODE_LIBRARY_MOVE_AND_ERASE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <iterator>

namespace detail {
    struct vector_like_tag {
    };
    struct list_like_tag {
    };
    struct associative_tag {
    };

    template<typename C>
    struct container_traits;

    template<typename T, typename A>
    struct container_traits<std::vector<T, A>> {
        typedef vector_like_tag category;
    };

    template<typename T, typename A>
    struct container_traits<std::deque<T, A>> {
        typedef vector_like_tag category;
    };

    template<typename T, typename A>
    struct container_traits<std::list<T, A>> {
        typedef list_like_tag category;
    };

    template<typename T, typename A>
    struct container_traits<std::forward_list<T, A>> {
        typedef list_like_tag category;
    };

    template<typename T, typename C, typename A>
    struct container_traits<std::set<T, C, A>> {
        typedef associative_tag category;
    };

    template<typename T, typename C, typename A>
    struct container_traits<std::multiset<T, C, A>> {
        typedef associative_tag category;
    };

    template<typename T, typename C, typename A>
    struct container_traits<std::unordered_set<T, C, A>> {
        typedef associative_tag category;
    };

    template<typename K, typename V, typename C, typename A>
    struct container_traits<std::map<K, V, C, A>> {
        typedef associative_tag category;
    };

    template<typename K, typename V, typename C, typename A>
    struct container_traits<std::multimap<K, V, C, A>> {
        typedef associative_tag category;
    };

    template<typename K, typename V, typename C, typename A>
    struct container_traits<std::unordered_map<K, V, C, A>> {
        typedef associative_tag category;
    };

    template<typename Container, typename X>
    void erase_helper(Container &c, const X &x, vector_like_tag) {
        c.erase(std::remove(std::begin(c), std::end(c), x), std::end(c));
    }

    template<typename Container, typename Pred>
    void erase_if_helper(Container &c, Pred p, vector_like_tag) {
        c.erase(std::remove_if(std::begin(c), std::end(c), p), std::end(c));
    }

    template<typename Container, typename X>
    void erase_helper(Container &c, const X &x, list_like_tag) {
        c.remove(x);
    }

    template<typename Container, typename Pred>
    void erase_if_helper(Container &c, Pred p, list_like_tag) {
        c.remove_if(p);
    }

    template<typename Container, typename X>
    void erase_helper(Container &c, const X &x, associative_tag) {
        c.erase(x);
    }

    template<typename Container, typename Pred>
    void erase_if_helper(Container &c, Pred p, associative_tag) {
        for (auto i = std::begin(c); i != std::end(c);) {
            if (p(*i)) {
                c.erase(i++);
            } else {
                ++i;
            }
        }
    }
}

template<typename Container, typename X>
void erase(Container &c, const X &x) {
    detail::erase_helper(c, x, typename detail::container_traits<Container>::category{});
}

template<typename Container, typename Pred>
void erase_if(Container &c, Pred p) {
    detail::erase_if_helper(c, p, typename detail::container_traits<Container>::category{});
}

template<typename Container>
void print(const Container &c) {
    copy(std::begin(c), std::end(c), ostream_iterator<typename Container::value_type>(std::cout, " "));
    cout << std::endl;
}

#endif //CODE_LIBRARY_MOVE_AND_ERASE_H
