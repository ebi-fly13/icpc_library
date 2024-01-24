#pragma once

#include "../template/template.hpp"



typedef std::string::const_iterator State;

bool expect(State &begin, char expected) {
    return *begin == expected;
}

void consume(State &begin, char expected) {
    assert(*begin == expected);
    begin++;
}

bool isdigit(char c) {
    return '0' <= c && c <= '9';
}

bool isAlpha(char c) {
    return 'A' <= c && c <= 'Z';
}

bool isalpha(char c) {
    return 'a' <= c && c <= 'z';
}

