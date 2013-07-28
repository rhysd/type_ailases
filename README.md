## Remove `typename ::type` from type\_traits

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

### License

Distributed under MIT license.

  Copyright (c) 2013 rhysd

  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the
  "Software"), to deal in the Software without restriction, including
  without limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so, subject to
  the following conditions:
  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


