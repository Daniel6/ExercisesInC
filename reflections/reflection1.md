## Reflection 1
Daniel Bishop

### Sprint Reflection
In sprint 1 we followed through on some of the examples from Head First C, which proved to be somewhat valuable in learning C. In this way I accomplished my personal learning goal of learning more about C, though I will continue to try to learn more in sprint 2 of course. In sprint 1 I feel like some of the group members did not get a chance to do some of the cooler coding stuff. This is an issue which we talked about in the end of sprint retrospective, and then resolved by using our first sprint meeting to assign working tasks to each member. We followed eduScrum pretty well in our retrospective, we even made a +/delta board!

### HFC Exercises
In sprint 1 we did chapters 1, 2, 3, and 11.
[exercise 1](https://github.com/Daniel6/ExercisesInC/blob/master/exercises/ex01/hw1.c),
[exercise 2](https://github.com/Daniel6/ExercisesInC/blob/master/exercises/ex02/ex02.md),
[exercise 3](https://github.com/Daniel6/ExercisesInC/blob/master/exercises/ex03/tee.c),
[exercise 11](https://github.com/Daniel6/ExercisesInC/blob/master/exercises/ex11/ikkp-server.c)

### TOS Reading Questions
We did not do any Think OS stuff in sprint 1 and instead opted to do 4 chapters of TOS in sprint 2.

### Exam Question
The following code goes through all the random numbers until it gets a 10, and then exits successfuly. What is the biggest problem with this program?

[code](./randomnumbergenerator.c)

Solution:
There is a huge memory leak due to repeatedly malloc'ing without ever freeing those resources.
The random number generation not being random (or even working) is a secondary problem as the memory leak will starve the system of memory.
