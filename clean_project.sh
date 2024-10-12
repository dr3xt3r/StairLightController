#!/bin/bash

# Function to clear a folder but keep the folder itself
clear_folder() {
# specify local variable 'folder' as the first argument passed to the function
  local folder=$1
  if [ -d "$folder" ]; then
    echo "Clearing contents of $folder..."
# remove all files, hidden files and directories in the specified folder
    rm -rf "$folder"/*
    rm -rf "$folder"/.[!.]*
    echo "$folder cleared!"
  else
    echo "$folder does not exist"
  fi
}

# clear the contents of the '.cache' folder
clear_folder .cache

# clear the contents of the 'build' folder
clear_folder build