#include <iostream>
#include <vector>
#include <algorithm>

struct TestShuffle
{
    long long int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;
};

void RandomElementTest(TestShuffle &t, long long int attemps)
{
    std::vector<int> digits({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    long long int i = 0;
    while (i != attemps)
    {
        i++;
        std::random_shuffle(digits.begin(), digits.end());
        switch (digits.front())
        {
        case 0:
            t.zero += 1;
            break;
        case 1:
            t.one += 1;
            break;
        case 2:
            t.two += 1;
            break;
        case 3:
            t.three += 1;
            break;
        case 4:
            t.four += 1;
            break;
        case 5:
            t.five += 1;
            break;
        case 6:
            t.six += 1;
            break;
        case 7:
            t.seven += 1;
            break;
        case 8:
            t.eight += 1;
            break;
        case 9:
            t.nine += 1;
            break;
        }
    }
}

int main()
{
    TestShuffle test;
    long long int total_tests = 1000;
    long long int shuffles_in_test = 1000;
    long long int total_shuffles = shuffles_in_test * total_tests;

    std::cout << "Total test: " << total_tests << "\n";
    std::cout << "Shuffles in one test: " << shuffles_in_test << "\n";
    std::cout << "Total shuffles: " << total_shuffles << "\n";

    for (int current_test = 0; current_test != total_tests; ++current_test)
    {
        RandomElementTest(test, shuffles_in_test);
    }

    std::cout << "Average chance of vector[0]: " << (test.zero / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[1]: " << (test.one / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[2]: " << (test.two / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[3]: " << (test.three / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[4]: " << (test.four / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[5]: " << (test.five / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[6]: " << (test.six / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[7]: " << (test.seven / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[8]: " << (test.eight / (double)total_shuffles) * 100.0 << "%\n";
    std::cout << "Average chance of vector[9]: " << (test.nine / (double)total_shuffles) * 100.0 << "%\n";
}