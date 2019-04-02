# Regex
Regular Expression in Five Languages 
#----------------------------------------------------------------------

Purpose:

  * Demonstrate (elementary) understanding of Regular Expressions
    and how to use them in various useful languages.

#----------------------------------------------------------------------

Background:

  * The input file will have multiple proposed tokens on each
    line.  There also might be lines with no proposed tokens
    and / or just or extra whitespace.

  * The proposed tokens will be separated by whitespace, which is
    to be ignored.

  * Your program will consider successive tokens from the input
    file and classify them as 'FP', 'STR', 'INT', or
    'does not match'.

  * An FP is one or more decimal digits, followed by a right
    parenthesis, followed by a left parenthesis, followed by
    one or more decimal digits.

  * A STR is a vertical bar (|) followed by zero or more uppercase
    letters and decimal digits followed by a plus sign (+).

  * An INT is a octothorpe sign (#) followed by one or more
    decimal digits or letters R through W.  The letters may be
    uppercase or lowercase.  (That is, r through w are allowed.)

#----------------------------------------------------------------------

Examples:

  000)(000  is a legal FP.
  1)(1      is a legal FP.
  )000      is not a legal FP.
  000(      is not a legal FP.
  1.1       is not a legal FP.

  |+        is a legal STR.
  |1+       is a legal STR.
  |HITHERE+ is a legal STR.
  |a+       is not a legal STR.
  "abc"     is not a legal STR.
  A+        is not a legal STR.
  |A        is not a legal STR.

  #rSt      is a legal INT.
  #0        is a legal INT.
  #r0       is a legal INT.
  #W        is a legal INT.
  123       is not a legal INT.
  rSt       is not a legel INT.

#----------------------------------------------------------------------
Tasks:

  1. Download HMWK_03_dalioba.zip from Blackboard.

  2. Unzip the file somewhere convenient.

  3. Change 'dalioba' in the name of the directory to your NetID.
     (Your NetID is three letters followed by four or five digits.
      The directory name will now be something like
      'hmwk_03_abc1234', with YOUR NetID instead of 'abc1234'.)

  4. Look in that directory.

  5. Change the header lines in the skeleton files
     hmwk_03.cs / .java / .py.

      -- Line 1:  Family name first, then a comma, then
                  personal name.

      -- Line 2:  Your NetID.

      -- Line 3:  The date you edited the file.

  6. Run the files you just changed with the provided
     'inputdata.text' as the input file.

  7. Observe the following output (it will be the same no matter
     which language you picked):

processing tokens from inputdata.txt ...
>000)(000< is the proposed token.
>1)(1< is the proposed token.
>)000< is the proposed token.
>000(< is the proposed token.
>1.1< is the proposed token.
>|+< is the proposed token.
>|1+< is the proposed token.
>|HITHERE+< is the proposed token.
>|a+< is the proposed token.
>"abc"< is the proposed token.
>A+< is the proposed token.
>|A< is the proposed token.
>#rSt< is the proposed token.
>#0< is the proposed token.
>#r0< is the proposed token.
>#W< is the proposed token.
>123< is the proposed token.
>rSt< is the proposed token.

  8. Now, change the contents of processToken() function in each
     of the hmwk_03.cs, .java, and .py files to use the regular
     expression support of the corresponding language so that the
     following output is generated for the 'inputdata.txt' test
     case file.

processing tokens from inputdata.txt ...
>000)(000< matches FP
>1)(1< matches FP
>)000< does not match
>000(< does not match
>1.1< does not match
>|+< matches STR
>|1+< matches STR
>|HITHERE+< matches STR
>|a+< does not match
>"abc"< does not match
>A+< does not match
>|A< does not match
>#rSt< matches INT
>#0< matches INT
>#r0< matches INT
>#W< matches INT
>123< does not match
>rSt< does not match

  9. You should get the same output for each of the three
     languages.  Make your output match this format EXACTLY since
     when your solutions are tested, their output will be checked
     using diff.

#-----------------------------------------------------------------
