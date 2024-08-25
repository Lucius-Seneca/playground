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
    cmake \
    clang \
    clangd \
    clang-format \
    git \
    nano

# Add the user as the executing user instead of using root
# (to avoid dubious git ownerships)
ARG USERNAME

RUN useradd -m ${USERNAME}
USER ${USERNAME}

RUN git config --global core.editor "nano"

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY --chown=${USERNAME}:${USERNAME} . /home/${USERNAME}/workspace/testrepo
WORKDIR /home/${USERNAME}/workspace/testrepo

ENV TERM=xterm-256color
ENV PS1='\[\e[92m\]\u\[\e[0m\]@\[\e[94m\]\h\[\e[0m\]:\[\e[35m\]\w\[\e[0m\]# '

# This command runs your application, comment out this line to compile only
CMD ["/bin/bash"]

LABEL Name=testrepo Version=0.0.1
