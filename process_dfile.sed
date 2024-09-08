# This script improves a g++ .d file by adding an empty target for each dependency. 
# It will transform a file of format:
# 
#  target: dependency1 dependency2 dependency3 \
#          dependency4 \
#          dependency5  \
#          dependency6 \
#
# Into:
#
#  dependency1:
#  dependency2:
#  dependency3:
#
#  ...etc.
#
# We add the output of this script to the original file.

# Delete comments
s/#.*//

# Delete <target>: from all lines matching pattern <target>: [file]\
s@^[^ ]* *:  *@@

# Delete trailing backslashes from all lines
s/ *\\$//

# Delete blank lines
/^$/ d

# Add a colon to the end of each line
s/$/ :/
