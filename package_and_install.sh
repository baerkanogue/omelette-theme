#!/bin/bash

read -p "Enter omelette version: " version

vsix_file="omelette-${version}.vsix"

if [[ -f "$vsix_file" ]]; then
    # Install the extension
    code --install-extension "$vsix_file"
    echo "Installed $vsix_file"
else
    echo "File $vsix_file not found!"
fi