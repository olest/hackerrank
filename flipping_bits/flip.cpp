#include<cassert>

long flipBits(long n) {
    long mask = (1l << 16) - 1;
    return ~n & mask;
}

int main() {
    assert(flipBits(9)==4294967286);

}
