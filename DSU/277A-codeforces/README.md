# Learning Languages

Let's focus on the target of the employer, he needs every language used in the company to be linked to the other languages, and the make sure that all employees know at least 1 language.

1. Create set for each language, and a boolean array to track only the used languages.
2. If the emplyoee knows no languages, increament the ans.
3. If the employee know at least one langugae, mark the language True in the boolean array, add all the langugaes of this employee in a vector
4. Unify the languages in the vector, and repeat from step 2 on the next employee.
5. Finally, add on the ans variable the number of links we need to connect all the used languages by the employees (number of sets -1 )

Space complexity : `O(m)`
Time complexity : `O(n . m . (log* m))`

`m-> number of languages`

`n-> number of employees`
