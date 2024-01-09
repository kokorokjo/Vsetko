// Autor: Benjamin Swart
#include <bits/stdc++.h>

std::optional<std::string> solve(std::string message, std::vector<std::string> dictionary)
{
    std::size_t max_word_length = 0;

    for (std::string &word : dictionary)
        max_word_length = std::max(max_word_length, word.size());

    std::sort(dictionary.begin(), dictionary.end());

    std::vector<std::optional<std::size_t>> possible_from = {0};

    for (std::size_t i = 0; i < message.size(); i++)
    {
        std::optional<size_t> best_start;

        for (std::size_t length = 1; length <= max_word_length; length++)
        {
            if (length > i + 1)
                break;

            std::size_t start = i - (length - 1);

            if (!possible_from[start])
                continue;

            std::string word = message.substr(start, length);

            if (std::binary_search(dictionary.begin(), dictionary.end(), word))
                best_start = start;
        }

        possible_from.push_back(best_start);
    }

    if (!possible_from.back())
        return {};

    std::vector<bool> spaces(message.size());
    std::size_t end = *possible_from.back();

    while (end != 0)
    {
        spaces[end] = true;
        end = *possible_from[end];
    }

    std::string result;

    for (std::size_t i = 0; i < message.size(); i++)
    {
        if (spaces[i])
            result.push_back(' ');

        result.push_back(message[i]);
    }

    return result;
}

int main()
{
    std::uint64_t problem_count;
    std::cin >> problem_count;

    for (std::uint64_t p = 0; p < problem_count; p++)
    {
        std::uint64_t word_count;
        std::cin >> word_count;

        std::string message;
        std::cin >> message;

        std::vector<std::string> dictionary(word_count);

        for (std::uint64_t w = 0; w < word_count; w++)
            std::cin >> dictionary[w];

        std::optional<std::string> result = solve(message, dictionary);

        if (result)
        {
            std::cout << "ANO" << std::endl;
            std::cout << *result << std::endl;
        }
        else
        {
            std::cout << "NE" << std::endl;
        }
    }
}