## Reflection 2
Daniel Bishop

### Sprint Reflection
In sprint 2, each team member was assigned a module to develop on their own branch. We set a tentative due date for these modules at half way through the sprint, but this proved to be overly optimistic as noone had finished by that time. We spent the rest of the sprint finishing our own modules. On the upside, in sprint 1 I reflected that it felt that work was divided unevenly among team members, but in this sprint everything felt balanced. By the end of the sprint we had each completed our modules, and decided to use sprint 3 solely for integration and bugfixing.

Another thing we worked at improving in this sprint was our reading comprehension. In the first sprint we were quizzed on material that we had not completely read about. This time, we put a little more pressure on everyone to do a comprehensive reading. It helped that we were just reading TOS chapters instead of doing HFC exercises.

I feel like I learned a lot in this sprint, since I got to sit down and write a lot of code myself. In particular, I learned how to do some multithreading in C, which I found to be rather interesting and complicated.

### HFC Exercises
In sprint 2 my team did not do HFC exercises, we only did TOS readings.

### TOS Readings
In sprint 2 my team read chapters 1 through 4.
[reading question answers](../reading_questions/thinkos.md)

### Exam Question and Solution
This question is based on TOS chapter 4.

In terms of memory location, what is the difference between 
'''
char *str = "abc";
'''
and 
'''
static char *str = "abc";
'''

Answer: 
The first char pointer points to a string literal in static memory. The pointer itself lives in the stack. The second char pointer also points to a string literal in static memory, but the pointer itself is also in static memory due to the static keyword.
