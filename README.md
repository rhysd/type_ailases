# Remove `typename ::type` from type\_traits

### Before

```cpp
    template <
                class... Args,
                class ElemType =
                    typename std::decay<
                        typename std::common_type<Args...>::type
                    >::type
             >
    inline constexpr
    typename std::enable_if<
        (sizeof...(Args) > 0),
        std::array<ElemType, sizeof...(Args)>
    >::type
    make_array(Args &&... args)
    {
        return {{ std::forward<ElemType>(args)... }};
    }
```

###After

```cpp
    template <
                class... Args,
                class ElemType =
                    aliases::decay< aliases::common_type<Args...> >
             >
    inline constexpr
    aliases::enable_if<
        (sizeof...(Args) > 0),
        std::array<ElemType, sizeof...(Args)>
    >
    make_array(Args &&... args)
    {
        return {{ std::forward<ElemType>(args)... }};
    }
```

### Requirements

A compiler must implements Template Aliases, a C++11 feature.

- clang 3.0 or later
- gcc 4.7 or later
- VC++ not implemented yet
