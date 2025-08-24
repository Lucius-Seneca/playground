# Use a simple Ubuntu image as base
FROM --platform=linux/amd64 ubuntu:22.04

# Avoid listening for user inputs while the container is built
ENV DEBIAN_FRONTEND=noninteractive

# To enable package configuration
RUN apt-get update && apt-get install -y --no-install-recommends apt-utils && rm -rf /var/lib/apt/lists/*

# Add Bazelisk to the docker
RUN apt-get update && apt-get install -y \
    apt-transport-https curl gnupg \
    && rm -rf /var/lib/apt/lists/*
RUN curl -Lo /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
RUN chmod +x /usr/local/bin/bazel

# Add Buildifier to the repo
RUN curl -Lo /usr/local/bin/buildifier https://github.com/bazelbuild/buildtools/releases/latest/download/buildifier
RUN chmod +x /usr/local/bin/buildifier

# Install Bazel, CMake and other dependencies
RUN apt-get update && apt-get install -y \
    clang \
    clang-format \
    clang-tidy \
    cmake \
    fontconfig \
    git \
    iputils-ping \
    nano \
    pre-commit \
    python3 \
    python3-pip \
    sudo \
    unzip \
    wget \
    zsh \
    && rm -rf /var/lib/apt/lists/*

# Configure Git to trust the workspace directory
RUN git config --global --add safe.directory /workspaces/playground

# Use current clangd version
RUN curl -Lo clangd-linux-19.1.2.zip https://github.com/clangd/clangd/releases/download/19.1.2/clangd-linux-19.1.2.zip \
    && unzip clangd-linux-19.1.2.zip -d /usr/local/bin \
    && rm clangd-linux-19.1.2.zip

RUN curl -Lo clangd_indexing_tools-linux-19.1.2.zip https://github.com/clangd/clangd/releases/download/19.1.2/clangd_indexing_tools-linux-19.1.2.zip \
    && unzip -o clangd_indexing_tools-linux-19.1.2.zip -d /usr/local/bin \
    && rm clangd_indexing_tools-linux-19.1.2.zip

# Ensure clangd is executable and create a symbolic link
RUN chmod +x /usr/local/bin/clangd*/bin/clangd \
    && ln -s /usr/local/bin/clangd*/bin/clangd /usr/local/bin/clangd

# Add the user as the executing user instead of using root
# (to avoid dubious git ownerships)
ARG USERNAME

RUN useradd -m ${USERNAME} && \
    echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Fix ownership issues
RUN mkdir -p /home/${USERNAME}/.cache/ccache && touch /home/${USERNAME}/.cache/.bash_history \
    && chown -R ${USERNAME}:${USERNAME} /home/${USERNAME} \
    && chown -R ${USERNAME}:${USERNAME} /usr/local/bin/bazel \
    && chown -R ${USERNAME}:${USERNAME} /usr/local/bin/buildifier \
    && chown -R ${USERNAME}:${USERNAME} /usr/local/bin/clangd_19.1.2 \
    && git config --global core.editor "nano"

USER ${USERNAME}

ENV TERM=xterm-256color
ENV PS1='\[\e[92m\]\u\[\e[0m\]@\[\e[94m\]\h\[\e[0m\]:\[\e[35m\]\w\[\e[0m\]# '

# This command runs your application, comment out this line to compile only
CMD ["/bin/zsh"]

LABEL Name=playground Version=0.0.1
