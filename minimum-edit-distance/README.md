# Minimum Edit Distance / Levenshtein Distance

Given two strings, output the number of inserts / deletes / substitutions needed to make the strings match.

Given "intention" and "execution", output 8.

Inserting and deleting costs 1, substitutes cost 2.

```text
i n t e * n t i o n
| | | | | | | | | | 
* e x e c u t i o n
^ ^ ^   ^ ^ 
d s s   i s
e u u   n u
l b b   s b
e s s   e s
t t t   r t
e i i   t i
  t t     t
  u u     u
  t t     t
  e e     e
```
