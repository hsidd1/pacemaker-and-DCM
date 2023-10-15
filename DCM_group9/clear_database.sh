#!/bin/bash
# !!!!!!!! WARNING !!!!!!!!
# clears the contents of the database.txt file
# !!!!!!!! WARNING !!!!!!!!

# Check if the file exists, and if not, create it
if [ ! -f "database.json" ]; then
  touch "database.json"
fi

# Clear the contents of the file
> "database.json"

echo "Contents of 'database.json' have been cleared."