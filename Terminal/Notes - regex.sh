# regex101.com

# ---------- ECMAScript
# special characters, to match them one needs to escape them (e.g. \^); all other characters match themselves;
^ $     # anchors; match the position (immediately following/of) a line termination char; ^test$ -> matches exactly "test\n"
.       # wildcard; matches any one char;
|       # alternation; a|b -> matches a or b
()      # capture groups; (.)(ab|cd)(.) on 1cd4 returns these groups 1cd4, 1, cd, 4;
(?: X)  # does not capture the group; X is a pattern
(?= X)  # lookahead; is true if pattern occurs, but is zero-width (match pointer doesn’t advance); X is a pattern
(?! X)  # lookahead; is true if a pattern does not match,but is zero-width; X is a pattern;
        # ^(?!Volcano)[A-Za-z]+     ...line beginning, any single word that doesn’t start with “Volcano”

# repeatitions are greedy: find the longest match while still matching the remainder of the regular expression; to make them non-greedy
# add ? beghind; e.g. on "aaabbb" (a+)(ab)*(b+) gives "aaa" "" "bbb", (a+?)(ab)*(b+) gives "aa" "ab" "bb"
*       # repetition; matches the preceeding part zero or more times; a*b matches b, ab, aab, ...
+       # repetition; matches the preceeding part one or more times; a+b matches ab, aab, ...
?       # repetition; matches the preceeding part zero or one times; a?b matches b, ab
{}      # bounded repeat; a{n}, a{n, }, a{n, m} matches a repeated n times, n or more times, between [n, m]-times, not [n,m)!
{n}     # n occurrences of the previous char or expression
{n,m}   # from n to m occurrences of the previous char or expression
{n,}    # at least n occurrences of the previous char or expression
{,m}    # up to m occurrences of the previous char or expression

[]      # or; ab[cde] matches "abc", "abd", "abe"; ^ plays a role of negation: ab[^cde] matches "abp" etc. but not any of "abc", "abd", "abe"
        # [a-zA-Z] matches any of the standard letters; [0-9] matches any number

\b      # match a word boundary
\B      # match anything but \b
\n      # back reference; refs n-th caputred group n > 0

\*      # an asterisk “*”
\.      # a period “.”
\?      # a question mark
\n      # a newline
\t      # a tab

# RE    Expansion       Match
# \d    [0-9]           any digit
# \w    [a-zA-Z0-9_]    any alphanumeric/underscore
# \W    [ˆ\w]           a non-alphanumeric
# \s    [␣\r\t\n\f]     whitespace (space, tab)
# \S    [ˆ\s]           non-whitespace

# ----- Operator Precedence (High to Low)
# Parenthesis ()
# Counters * + ? {}
# Sequences and anchors the ^my end$
# Disjunction |
