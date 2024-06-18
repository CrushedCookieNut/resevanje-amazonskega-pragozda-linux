#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP
#include <vector>

struct leaderboard {
    char ime[100];
    int tocke;
};

class ldb {
    public:
    std::vector<leaderboard> lestvica;
    void pridobiPodatke();
    void vpisiPodatke(char ime[], int tocke);
};

#endif