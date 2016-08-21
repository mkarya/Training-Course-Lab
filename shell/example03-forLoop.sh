#!/bin/bash

# Associate the name of each planet with its distance from the sun.

for planet in "Mercury 36" "Venus 67" "Earth 93"  "Mars 142" "Jupiter 483"
do
  original_params=("$@")	
  set -- $planet  #  Parses variable "planet"
                  #+ and sets positional parameters.
  #  The "--" prevents nasty surprises if $planet is null or
  #+ begins with a dash.

  #  May need to save original positional parameters,
  #+ since they get overwritten.
  #  One way of doing this is to use an array,
  #         original_params=("$@")

  echo "$1		$2,000,000 miles from the sun"
  #-------two  tabs---concatenate zeroes onto parameter $2
  echo "$original_params[0]"
  echo "$original_params[1]"
done

exit 0
