#pragma once

#include "../template/template.hpp"

namespace lib {

typedef std::string::const_iterator State;

// *begin == expectedの判定
bool expect(State &begin, char expected) {
    if (*begin == expected) {
        return true;
    } else {
        return false;
    }
}

// beginがexpectedを指していたらbeginを一つ進める。
void consume(State &begin, char expected) {
    if (*begin == expected) {
        begin++;
    } else {
        assert(0);
    }
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

}  // namespace lib