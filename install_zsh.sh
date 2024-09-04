#!/bin/bash

# Add Ohmyzsh
sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh --unattended)"
cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
