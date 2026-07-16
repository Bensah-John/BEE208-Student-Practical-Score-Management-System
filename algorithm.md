# Student Practical Score Management System

This document contains both the high-level **Project Algorithm** and the detailed **Pseudocode** implementation for the Student Practical Score Management System.

## 1. Project Algorithm

1. **Start.**
2. **Display Program Title:** Display the project welcome title: "STUDENT PRACTICAL SCORE MANAGEMENT SYSTEM".
3. **Ask for Class Size:** Prompt the user to enter the number of students `numStudents`.
4. **Create Student List:** Create a dynamic list (vector) of `StudentScore` objects sized to `numStudents`.
5. **Set Class Total to Zero:** Set `totalClassScore` = 0.0.
6. **Loop Through Each Student:**
    * **a.** Read the student's full name `studentName` using input stream handling.
    * **b.** Read the student's unique identifier `indexNumber`.
    * **c. Validate Score 1:**
        * **i.** Read `score1`.
        * **ii.** If `score1` is less than 0 or greater than 100, print an error message and repeat the input loop for score1.
    * **d. Validate Score 2:**
        * **i.** Read `score2`.
        * **ii.** If `score2` is less than 0 or greater than 100, print an error message and repeat the input loop for score2.
    * **e. Validate Score 3:**
        * **i.** Read `score3`.
        * **ii.** If `score3` is less than 0 or greater than 100, print an error message and repeat the input loop for score3.
    * **f. Calculate Performance Metrics:**
        * **i.** Calculate `totalScore` = `score1` + `score2` + `score3`.
        * **ii.** Calculate `averageScore` = `totalScore` / 3.0.
    * **g. Assign Remarks Based on Score:**
        * **i.** If `averageScore` >= 80, set `remark` = "Excellent".
        * **ii.** Else if `averageScore` >= 70, set `remark` = "Very Good".
        * **iii.** Else if `averageScore` >= 60, set `remark` = "Good".
        * **iv.** Else if `averageScore` >= 50, set `remark` = "Pass".
        * **v.** Else, set `remark` = "Needs Improvement".
    * **h. Update Class Total:** Add `averageScore` of current student to `totalClassScore`.
7. **Find the Overall Class Average:** Compute `classAverage` = `totalClassScore` / `numStudents`.

8. **Display Terminal Report:**
    * **a.** Print report header.
    * **b.** Loop through each record and display Name, Index, Total Score, Average Score, and Remark.
    * **c.** Display the overall `classAverage` formatted to 2 decimal places.
9. **Save Report to File:**
    * **a.** Attempt to open file "practical_scores.txt" in output stream mode.
    * **b.** If file open is successful:
        * **i.** Write formatted score report containing all student records and the final class average to the file.
        * **ii.** Close the file stream.
        * **iii.** Display confirmation message: "Report successfully saved to 'practical_scores.txt'".
    * **c.** Else (if file stream failed to open):
        * **i.** Print error message: "Error: Unable to save report to file.".
10. **Exit the Program:** Display a goodbye message and exit the program.
11. **Stop.**