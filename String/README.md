[13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/ "13. Roman to Integer") <br>
This is the easy question, but I included it to solve before the next medium question. Store what each literal corresponding to in integer form and iterate over the roman string and add each literal's value to the final answer. The only trick is that if a literal value was smaller than the value of the next literal, use subtraction instead and don't count the next literal as it's already processed with the current one.
<br>

[12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/ "12. Integer to Roman") <br>
This time, we reverse the map, meaning that we store what each integer represent in the roman form, and we also include the special numbers that starts with 4 and 9. We split the num into thousands, hundreds, tens, and units to process each part independently. We will start from high to low and see how many literals can add up to be equal to the current part.
<br>