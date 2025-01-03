#pragma once

template <typename ListType>
ListType maxValue(ListType list[], unsigned int size);
template <typename ListType>
ListType maxValue(ListType list[][3], unsigned int size);
template <typename ListType>
ListType maxValue(ListType list[][2][2], unsigned int size);
int maxValue(int a, int b);
int maxValue(int a, int b, int c);