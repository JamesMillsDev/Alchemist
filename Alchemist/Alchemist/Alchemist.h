#pragma once

typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ullong;
typedef long long llong;

#ifdef DLL_EXPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#include <concepts>

template<class T, class U>
concept derived = std::is_base_of_v<T, U>;

#include <string>

using std::string;