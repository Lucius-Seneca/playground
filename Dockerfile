# Use a simple Ubuntu image as base
FROM --platform=linux/amd64 ubuntu:22.04

# Avoid listening for user inputs while the container is built
ENV DEBIAN_FRONTEND=noninteractive

# To enable package configuration
RUN apt-get update && apt-get install -y --no-install-recommends apt-utils

# Add Bazelisk to the docker
RUN apt-get update && apt-get install -y \
    apt-transport-https curl gnupg
RUN curl -Lo /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
RUN chmod +x /usr/local/bin/bazel

# Add Buildifier to the repo
RUN curl -Lo /usr/local/bin/buildifier https://github.com/bazelbuild/buildtools/releases/latest/download/buildifier
RUN chmod +x /usr/local/bin/buildifier

# Install Bazel, CMake and other dependencies
RUN apt-get update && apt-get install -y \
    sudo \
    cmake \
    clang \
    clangd \
    clang-format \
    clang-tidy \
    git \
    nano \
    python3 \
    python3-pip \
    fontconfig \
    wget \
    unzip \
    zsh \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install pre-commit

# Add the user as the executing user instead of using root
# (to avoid dubious git ownerships)
ARG USERNAME

RUN useradd -m ${USERNAME} && \
    echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
USER ${USERNAME}

RUN mkdir -p /home/${USERNAME}/.cache/ccache && touch /home/${USERNAME}/.cache/.bash_history \
    && chown -R ${USERNAME} /home/${USERNAME}/.cache

RUN git config --global core.editor "nano"

ENV TERM=xterm-256color
ENV PS1='\[\e[92m\]\u\[\e[0m\]@\[\e[94m\]\h\[\e[0m\]:\[\e[35m\]\w\[\e[0m\]# '

# This command runs your application, comment out this line to compile only
CMD ["/bin/zsh"]

LABEL Name=testrepo Version=0.0.1
