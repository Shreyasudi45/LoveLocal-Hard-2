# ALGORITHM:

Reverse the Input String:
Create a string 'rev_s' by reversing the input string 's'.

Concatenate the Original and Reversed Strings:
Create a new string ''new_s' by concatenating the original string 's', a special character (here, '#'), and the reversed string 'rev_s'.

Build KMP Table:
Initialize a KMP table ('kmpTable') with zeros, having the same length as the concatenated string.
Iterate through the concatenated string using the KMP algorithm to build the KMP table.
If the characters at positions i and j are equal, set kmpTable[i] to j + 1 and increment both i and j.
If the characters are not equal and j is greater than 0, update j using kmpTable[j - 1].
Otherwise, set kmpTable[i] to 0 and increment i.

Compute Length to Add:
Determine the length to add to the original string by subtracting the length of the longest palindrome prefix (obtained from the last element of the KMP table) from the length of the original string.

Construct the Shortest Palindrome:
Return the concatenation of the substring of the reversed string rev_s from index 0 to lenToAdd and the original string s.

Main Function:
Read the input string s from the user.
Call the shortestPalindrome function with the input string and print the result.

Summarized Algorithm:

function shortestPalindrome(s):
    rev_s = reverse(s)
    new_s = s + "#" + rev_s
    n = length(new_s)
    kmpTable = buildKMPTable(new_s)
    lenToAdd = length(s) - kmpTable[n - 1]
    return rev_s[0, lenToAdd] + s

function buildKMPTable(s):
    n = length(s)
    kmpTable = array of size n filled with zeros
    for i = 1, j = 0; i < n; :
        if s[i] == s[j]:
            kmpTable[i++] = ++j
        else:
            if j > 0:
                j = kmpTable[j - 1]
            else:
                kmpTable[i++] = 0
    return kmpTable

main:
    read s from user
    result = shortestPalindrome(s)
    print result


# LOGIC:

Reverse the Input String ('rev_s'):
A string 'rev_s' is created by reversing the characters of the input string 's'. This is done using the 'reverse' function from the C++ Standard Template Library (STL).

Concatenate the Original and Reversed Strings ('new_s'):
A new string 'new_s' is formed by concatenating the original string 's', a special character ('#'), and the reversed string 'rev_s'.

Build the KMP Table ('kmpTable'):
A KMP table is constructed for the concatenated string 'new_s' using the KMP algorithm. The KMP table helps efficiently match prefixes with suffixes.

Compute the Length to Add ('lenToAdd'):
The length to add to the original string is determined by subtracting the length of the longest palindrome prefix (obtained from the last element of the KMP table) from the length of the original string.

Construct the Shortest Palindrome ('result'):
The shortest palindrome is constructed by taking a substring of the reversed string 'rev_s' from index 0 to 'lenToAdd' and concatenating it with the original string 's'.

Main Function ('main'):

Reads the input string 's' from the user.
Calls the 'shortestPalindrome' function with the input string.
Prints the resulting shortest palindrome.