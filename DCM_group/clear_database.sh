#!/bin/bash
# !!!!!!!! WARNING !!!!!!!!
# clears the contents of the database.txt file
# !!!!!!!! WARNING !!!!!!!!

# Check if the file exists, and if not, create it
if [ ! -f "database.txt" ]; then
  touch "database.txt"
fi

# Clear the contents of the file
> "database.txt"

echo "Contents of 'database.txt' have been cleared."