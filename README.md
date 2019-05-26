# Stable-Marriage-Problem
Stable Marriage by Using Gale-Shapley Algorithm C++
1 Project goals
This project aims to solve the Stable Marriage Algorithm, using the Gale-Shapley Deferred Accep-
tance Algorithm.

1.1 The Stable Marriage Problem
The problem we want to solve is called the Stable Marriage Problem, and is described by Wikipedia1
as follows:
Given n men and n women, where each person has ranked all members of the opposite
sex in order of preference, marry the men and women together such that there are no
two people of opposite sex who would both rather have each other than their current
partners. When there are no such pairs of people, the set of marriages is deemed stable.
This problem has had many extensions, such as the matching of pairs regardless of sex (Stable
Roommates Problem), matching when one side has multiple spots available (like college admis-
sions).
While naive brute-force solving of this problem requires a O(n!) time, more ecient solutions
exist. Whether for the original or the extensions, they all rely on the same principle of \deferred
acceptance": assign temporary matches that can be overruled if there is a better match.

1.2 The Gale-Shapley Deferred Acceptance Algorithm
Based on the principle of temporary engagements, the Gale-Shapley (GS) algorithm works as
follows in several rounds until everyone is engaged.
At each round, all unengaged men propose to the woman they prefer and they haven't proposed to
yet. The woman refuses if she is already engaged to someone she prefers. Otherwise, she answers
\maybe" and they are (temporarily) engaged. Of course by accepting a proposal, she may need
to break a previous engagement, and in that case the ex-ance becomes unengaged. Temporary
engagements become nal when everybody is engaged.
For example, if we have three men Alfred, Bernard, and Charles, and three women Diana, Elizabeth
and Fiona. They will be abbreviated as A, B, C, D, E, and F hereafter. The preference orders
are as follows:
Alfred : E,D,F
Bernard : D,E,F
Charles : E,F,D

Diana : A,B,C
Elizabeth : C,B,A
Fiona : C,A,B
