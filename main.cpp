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
            mapping[args[i]] = rest.substr(start, j - start);
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

    // for (auto [k, v] : mapping) fmt::print("{}: {}\n", k, v);
    // fmt::print("➡️ {}\n", final_sub);

    if (std::ranges::all_of(final_sub, _phi(::ispunct, _or_, ::islower))) return final_sub;

    if (islower(final_sub.front())) {
        auto const i   = final_sub.find('(');
        auto const end = remove_parens(final_sub.substr(i, final_sub.size()), 0);
        return final_sub.substr(0, i) + translate(end);
    }

    return translate(final_sub);
}

auto generate_combinator_spellings() {
    auto translations = std::map<std::string, std::set<std::string>>{};
    auto const source = "BBSSKKCC"s;

    for (size_t i = 2; i <= 5; ++i) {
        auto mask = std::string(i, '1') + std::string(source.size() - i, '0');

        while (std::prev_permutation(mask.begin(), mask.end())) {
            // TODO: When GCC 13 comes out, replace this with
            // auto const s = mask
            //     | std::views::zip(source) <- C++23 (GCC 13)
            //     | std::views::filter([](auto t) { return std::get<0>(t) == '1;' })
            //     | std::ranges::to<std::string>(); <- C++23 (GCC 13)
            auto const s = std::inner_product(
              mask.begin(),
              mask.end(),
              source.begin(),
              ""s,
              [](auto acc, auto p) {
                  auto [keep, value] = p;
                  return keep ? acc + value : acc;
              },
              [](auto flag, auto value) {
                  return std::pair{flag == '1', value};
              });
            translations[translate(s)].insert(s);
        }
    }

    for (auto [k, v] : translations) { fmt::print("{}: {} {}\n", k, v.size(), v); }
}

auto unit_test(std::string combinator, std::string_view input, std::string_view expected) {
    auto const result  = translate(input);
    auto const correct = result == expected;
    fmt::print("{}: {} {} {} {}\n", (correct ? "✅" : "❌"), combinator, input, expected, result);
}

auto main() -> int {
    fmt::print("Hello YouTube!\n");

    unit_test("I", "SKK", "a");
    unit_test("B", "S(KS)K", "a(bc)");
    unit_test("B₁", "BBB", "a(bcd)");
    unit_test("B₂", "B(BBB)B", "a(bcde)");
    unit_test("W", "C(BMR)", "abb");
    unit_test("C", "S(BBS)(KK)", "acb");
    unit_test("D", "BB", "ab(cd)");

    generate_combinator_spellings();

    return 0;
}
