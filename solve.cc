#include <iostream>
#include <vector>

void process(std::vector<int>& ring, int skip_pattern) {
    auto it = ring.begin();
    while (ring.size() > 1) {
        int skip = (skip_pattern % 2) + 2;
        skip_pattern /= 2;

        for (int a = 1; a < skip; a++) {
            if (++it == ring.end()) {
                it = ring.begin();
            }
        }
        // std::cout << *it << ", ";
        it = ring.erase(it);
        if (it == ring.end()) {
            it = ring.begin();
        }
    }
    // std::cout << std::endl;
}

int main(int argc, const char* argv[]) {
    constexpr int people = 20;
    std::vector<int> results(people, 0);

    const int pattern_count = 1 << (people - 1);
    for (int skip_pattern = 0; skip_pattern < pattern_count; ++skip_pattern) {
        std::vector<int> ring;
        for (int i = 1; i <= people; ++i) {
            ring.push_back(i);
        }
        process(ring, skip_pattern);
        results[*ring.begin() - 1]++;
    }

    int total = 0;
    int max = -1;
    for (int i = 0; i < people; ++i) {
        int r = results[i];
        if (r > max) max = r;
        total += r;
        std::cout << "result of " << (i + 1) << ": " << r << std::endl;
    }

    std::cout << "max is " << max << std::endl;
    std::cout << "total is " << total << std::endl;
}
