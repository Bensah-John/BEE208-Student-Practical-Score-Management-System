# Student Practical Score Management System

## Pseudocode Specification

This document contains the pseudocode representation for the **Student Practical Score Management System**. The pseudocode outlines an object-oriented design featuring a `StudentScore` class that handles student data entry, score validation, calculation, remark assignment, display, and file persistence.


### Pseudocode

```text
START
    DISPLAY "STUDENT PRACTICAL SCORE MANAGEMENT SYSTEM"

    CLASS StudentScore
    PRIVATE
        CHARACTER: studentName
        CHARACTER: indexNumber
        REAL: score1, score2, score3
        REAL: totalScore, averageScore
        CHARACTER: remark

    PUBLIC
        METHOD setStudentDetails()
            OUTPUT "Enter student name: "
            INPUT studentName
            OUTPUT "Enter index number: "
            INPUT indexNumber
            
            REPEAT
                OUTPUT "Enter practical score 1 (0-100): "
                INPUT score1
            UNTIL validateScores(score1) == TRUE
            
            REPEAT
                OUTPUT "Enter practical score 2 (0-100): "
                INPUT score2
            UNTIL validateScores(score2) == TRUE
            
            REPEAT
                OUTPUT "Enter practical score 3 (0-100): "
                INPUT score3
            UNTIL validateScores(score3) == TRUE
            
            CALL calculateTotalAndAverage()
            CALL assignRemark()
        END METHOD

        METHOD validateScores(REAL score) RETURNS BOOLEAN
            IF score < 0 OR score > 100 THEN
                OUTPUT "Invalid score! Score must be between 0 and 100. Try again."
                RETURN FALSE
            ELSE
                RETURN TRUE
            END IF
        END METHOD

        METHOD calculateTotalAndAverage()
            totalScore = score1 + score2 + score3
            averageScore = totalScore / 3.0
        END METHOD

        METHOD assignRemark()
            IF averageScore >= 80 THEN
                remark = "Excellent"
            ELSE IF averageScore >= 70 THEN
                remark = "Very Good"
            ELSE IF averageScore >= 60 THEN
                remark = "Good"
            ELSE IF averageScore >= 50 THEN
                remark = "Pass"
            ELSE
                remark = "Needs Improvement"
            END IF
        END METHOD

        METHOD getAverageScore() RETURNS REAL
            RETURN averageScore
        END METHOD

        METHOD displayStudentReport()
            OUTPUT "Student Name: ", studentName
            OUTPUT "Total Score: ", totalScore
            OUTPUT "Average Score: ", FORMAT_DECIMAL(averageScore, 2)
            OUTPUT "Remark: ", remark
        END METHOD

        METHOD saveStudentReport(FILE_STREAM outFile)
            WRITE FILE outFile: "Student Name: " + studentName
            WRITE FILE outFile: "Index Number: " + indexNumber
            WRITE FILE outFile: "Total Score: " + totalScore
            WRITE FILE outFile: "Average Score: " + FORMAT_DECIMAL(averageScore, 2)
            WRITE FILE outFile: "Remark: " + remark
        END METHOD
    END CLASS

    START MAIN PROGRAM
        OUTPUT "STUDENT PRACTICAL SCORE MANAGEMENT SYSTEM"
        OUTPUT "Enter number of students: "
        INPUT numStudents

        DECLARE ARRAY/VECTOR OF StudentScore: students(numStudents)
        REAL totalClassScore = 0.0

        FOR i = 0 TO numStudents - 1 DO
            OUTPUT "Recording details for Student ", i + 1
            CALL students[i].setStudentDetails()
            totalClassScore = totalClassScore + students[i].getAverageScore()
        END FOR

        REAL classAverage = totalClassScore / numStudents

        OUTPUT "PRACTICAL SCORE REPORT"
        FOR i = 0 TO numStudents - 1 DO
            CALL students[i].displayStudentReport()
        END FOR

        OUTPUT "Class Average: ", FORMAT_DECIMAL(classAverage, 2)

        OPEN FILE "practical_scores.txt" AS outFile
        IF FILE.IS_OPEN(outFile) THEN
            WRITE FILE outFile: "PRACTICAL SCORE REPORT"
            FOR i = 0 TO numStudents - 1 DO
                CALL students[i].saveStudentReport(outFile)
            END FOR
            WRITE FILE outFile: "Class Average: " + FORMAT_DECIMAL(classAverage, 2)
            CLOSE FILE outFile
            OUTPUT "Report successfully saved to 'practical_scores.txt'"
        ELSE
            OUTPUT "Error: Unable to save report to file."
        END IF

        OUTPUT "Thank you for using the system. Goodbye!"
    END MAIN PROGRAM
END