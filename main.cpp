#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <string_view>

#include <fmt/core.h>
#include <fmt/ranges.h>

#include <combinators.hpp>

using namespace combinators;

using namespace std::string_literals;
using namespace std::string_view_literals;

auto dictionary = std::map<char, std::string>  //
  {{'I', "a.a"},                               //
   {'K', "ab.a"},
   {'S', "abc.ac(bc)"},
   {'B', "abc.a(bc)"},
   {'C', "abc.acb"},
   {'R', "abc.bca"},
   {'M', "a.aa"}};

auto split(std::string s) -> std::pair<std::string, std::string> {
    auto const i = s.find(".");
    return {s.substr(0, i), s.substr(i + 1, s.size())};
}

auto find_end(size_t j, std::string_view s) -> size_t {
    int paren_count = 1.0;
    while (paren_count > 0) {
        ++j;
        if (s[j] == '(') ++paren_count;
        if (s[j] == ')') --paren_count;
    }
    return j;
}

auto remove_parens(std::string s, size_t start) -> std::string {
    // ASSERT first char is '(' a(bc)d)
    s.erase(s.begin() + start);
    auto const i = find_end(start, s);
    s.erase(s.begin() + i);
    return s;
}

using mapping_t = std::map<char, std::string>;

auto create_mapping(std::string args, std::string_view rest)
  -> std::pair<mapping_t, std::string_view> {
    auto mapping = mapping_t{};
    auto j       = 0uz;
    auto max     = [](auto a, auto b) { return std::max(a, b); };
    char letter  = std::accumulate(rest.cbegin(), rest.cend(), '`', max) + 1;

    for (size_t i = 0; i < args.size(); ++i) {
        if (j >= rest.size()) {
            mapping[args[i]] = letter;
            ++letter;
        } else if (rest[j] != '(') {
            mapping[args[i]] = rest.substr(j, 1);
            ++j;
        } else {
            auto const start = j;
            j                = find_end(j, rest) + 1;
            mapping[args[i]] = rest.substr(start, j);
        }
    }

    auto const left_over = j < rest.size() ? rest.substr(j, rest.size()) : ""sv;

    return {mapping, left_over};
}

auto initial_substitution(std::string_view pattern, mapping_t& mapping) -> std::string {
    return std::accumulate(pattern.begin(), pattern.end(), ""s, [&](auto acc, auto c) {
        return acc + ((c == '(' or c == ')') ? std::string{c} : mapping[c]);
    });
}

auto remove_all_parens(std::string sub) -> std::string {
    while (sub.front() == '(') { sub = remove_parens(sub, 0); }

    // double left paren
    auto dlp = [](auto& s) { return std::ranges::adjacent_find(s, _psi(_and_, _eq('('))); };

    auto it = dlp(sub);
    while (it != sub.end()) {
        sub = remove_parens(sub, std::distance(sub.begin(), it));
        it  = dlp(sub);
    }

    return sub;
}

auto translate(std::string_view spelling) -> std::string {
    if (not dictionary.contains(spelling.front()))
        return "Missing from dictionary: "s + spelling.front();

    auto const combinator      = spelling.front();
    auto const rest            = spelling.substr(1, spelling.size());
    auto const fn_abstract     = dictionary[combinator];
    auto const [args, pattern] = split(fn_abstract);

    auto [mapping, left_over] = create_mapping(args, rest);
    auto const init_sub       = initial_substitution(pattern, mapping) + std::string{left_over};
    auto const final_sub      = remove_all_parens(init_sub);

    // fmt::print("➡️ {}\n", sub);

    if (std::ranges::all_of(final_sub, _phi(::ispunct, _or_, ::islower))) return final_sub;

    if (islower(final_sub.front())) {
        auto const i   = final_sub.find('(');
        auto const end = remove_parens(final_sub.substr(i, final_sub.size()), 0);
        return final_sub.substr(0, i) + translate(end);
    }

    return translate(final_sub);
}

auto unit_test(char combinator, std::string_view input, std::string_view expected) {
    auto const result  = translate(input);
    auto const correct = result == expected;
    fmt::print("{}: {} {} {} {}\n", (correct ? "✅" : "❌"), combinator, input, expected, result);
}

auto main() -> int {
    fmt::print("Hello YouTube!\n");

    unit_test('I', "SKK", "a");
    unit_test('B', "S(KS)K", "a(bc)");
    unit_test('H', "BBB", "a(bcd)");       // H will be the B1
    unit_test('J', "B(BBB)B", "a(bcde)");  // J will be the B2
    // unit_test("S", "ac(bc)");
    // unit_test('W', "C(BMR)", "abb");
    unit_test('C', "S(BBS)(KK)", "acb");
    unit_test('D', "BB", "ab(cd)");

    // TODO: make this more sophisticated
    auto const source = "BBSSKKIICC"s;
    auto mask         = "1100000000"s;

    // auto translations = std::map<std::string, std::set<std::string>>{};

    // while (std::prev_permutation(mask.begin(), mask.end())) {
    //     auto s = ""s;
    //     for (int i = 0; i < mask.size(); ++i) {
    //         if (mask[i] == '1') s += source[i];
    //     }
    //     translations[translate(s)].insert(s);
    // }

    // for (auto [k, v] : translations) { fmt::print("{}: {} {}\n", k, v.size(), v); }
}
