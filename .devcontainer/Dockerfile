FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y build-essential valgrind python3 \
    vim bash-completion git gdb python3-pip clang afl++ wget gcc-multilib \
    python3-serial python3-psutil unzip git openocd gdb-multiarch esptool \
    podman-docker clangd clang telnet gcc-arm-none-eabi

RUN mkdir -p /root/workspace/code-snippets

COPY devcontainer/01-intro /root/workspace/code-snippets/01-intro
COPY devcontainer/02-basics /root/workspace/code-snippets/02-basics
COPY devcontainer/03-mm-libc /root/workspace/code-snippets/03-mm-libc
COPY devcontainer/04-building-debugging /root/workspace/code-snippets/04-building-debugging
COPY devcontainer/05-use-cases /root/workspace/code-snippets/05-use-cases
COPY devcontainer/06-security /root/workspace/code-snippets/06-security

RUN git clone https://github.com/c-programming-essentials/check50.git /tmp/check50
RUN cd /tmp/check50 && pip install . --break-system-packages --root-user-action=ignore

RUN git clone https://github.com/c-programming-essentials/exercises.git /root/workspace/exercises
COPY exercises-solutions /root/workspace/exercise-solutions
RUN cd /root/workspace/exercise-solutions && rm -rf .git

WORKDIR /root/workspace
