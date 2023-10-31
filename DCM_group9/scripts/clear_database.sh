#!/bin/bash
# !!!!!!!! WARNING !!!!!!!!
# clears the contents of the database.json file
# !!!!!!!! WARNING !!!!!!!!

database_path="DCM_group9/backend/database.json"

# Check if the file exists, and if not, create it
if [ ! -f "$database_path" ]; then
  touch "$database_path"
  echo "Created '$database_path'"
else
  # Clear the contents of the file
  > "$database_path"
  echo "Contents of '$database_path' have been cleared."
fi