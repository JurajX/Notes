# regex101.com

# ---------- ECMAScript
#  special characters, to match them one needs to escape them (e.g. \^); all other characters match themselves;
^ $     #  anchors; matche the position (immediately following/of) a line termination char; ^test$ -> matches exactly "test\n"
.       #  wildcard; matches any one char;
|       #  alternation; a|b -> matches a or b
()      #  capture groups; (.)(ab|cd)(.) on 1cd4 returns these groups 1cd4, 1, cd, 4;

#  repeatitions are greedy: find the longest match while still matching the remainder of the regular expression; to make them non-greedy
#  add ? beghind; e.g. on "aaabbb" (a+)(ab)*(b+) gives "aaa" "" "bbb", (a+?)(ab)*(b+) gives "aa" "ab" "bb"
*       #  repetition; matches the preceeding part zero or more times; a*b matches b, ab, aab, ...
+       #  repetition; matches the preceeding part one or more times; a+b matches ab, aab, ...
?       #  repetition; matches the preceeding part zero or one times; a?b matches b, ab
{}      #  bounded repeat; a{n}, a{n, }, a{n, m} matches a repeated n times, n or more times, between [n, m]-times, not [n,m)!

[]      #  or; ab[cde] matches "abc", "abd", "abe"; ^ plays a role of negation: ab[^cde] matches "abp" etc. but not any of "abc", "abd", "abe"
        #  [a-zA-Z] matches any of the standard letters; [0-9] matches any number

\b      #  match a word boundary
\B      #  match anything but \b
\n      #  back reference; refs n-th caputred group n > 0
