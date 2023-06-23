#include "../template/template.hpp"

namespace lib {

struct Dice {
    int up = 0, front = 1, right = 2, left = 3, back = 4, down = 5;

    Dice() = default;

    void set_val(const std::vector<int> &_val) {
        assert(int(_val.size()) == 6);
        val = _val;
    }

    // y++
    void rollN() {
        int buff = down;
        down = back;
        back = up;
        up = front;
        front = buff;
    }

    // y--
    void rollS() {
        int buff = down;
        down = front;
        front = up;
        up = back;
        back = buff;
    }

    // x++
    void rollE() {
        int buff = down;
        down = right;
        right = up;
        up = left;
        left = buff;
    }

    // x--
    void rollW() {
        int buff = down;
        down = left;
        left = up;
        up = right;
        right = buff;
    }

    // 右回転(時計回り)
    void rollR() {
        int buff = right;
        right = back;
        back = left;
        left = front;
        front = buff;
    }

    // 左回転(反時計回り)
    void rollL() {
        int buff = left;
        left = back;
        back = right;
        right = front;
        front = buff;
    }

    void roll(char c) {
        if (c == 'N')
            rollN();
        else if (c == 'S')
            rollS();
        else if (c == 'E')
            rollE();
        else if (c == 'W')
            rollW();
        else if (c == 'R')
            rollR();
        else if (c == 'L')
            rollL();
        else
            assert(0);
    }

    int top_val() const {
        return val[up];
    }

    int right_val() const {
        return val[right];
    }

    int left_val() const {
        return val[left];
    }

    int front_val() const {
        return val[front];
    }

    int back_val() const {
        return val[back];
    }

    int down_val() const {
        return val[down];
    }

    std::vector<int> now() const {
        std::vector<int> ret(6);
        ret[0] = top_val();
        ret[1] = front_val();
        ret[2] = right_val();
        ret[3] = left_val();
        ret[4] = back_val();
        ret[5] = down_val();
        return ret;
    }

    std::vector<Dice> makeDice() const {
        std::vector<Dice> ret;
        for (int i = 0; i < 6; i++) {
            Dice d(*this);
            if (i == 1) d.rollN();
            if (i == 2) d.rollS();
            if (i == 3) {
                d.rollS();
                d.rollS();
            }
            if (i == 4) d.rollL();
            if (i == 5) d.rollR();
            for (int j = 0; j < 4; j++) {
                ret.emplace_back(d);
                d.rollE();
            }
        }
        return ret;
    }

    std::vector<int> val = {0, 1, 2, 3, 4, 5};
};

}