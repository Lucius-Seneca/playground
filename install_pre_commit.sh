#!/bin/bash

# Update package lists
sudo apt update

# Install pre-commit if not already installed
if ! command -v pre-commit &> /dev/null
then
    echo "pre-commit is being installed ..."
    sudo apt install -y pre-commit
fi

# Install the latest version of pre-commit using pip
echo "Upgrade pre-commit to the latest version."
RUN pip3 install --upgrade pre-commit

echo "pre-commit updated to the latest version."

# Run pre-commit install
echo "Commit hooks are being installed ..."
pre-commit install

echo "pre-commit hooks are successfully installed."
