FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y build-essential valgrind python3 \
    vim bash-completion git gdb python3-pip clang afl++

RUN mkdir -p /root/workspace/code-snippets

COPY devcontainer/01-intro /root/workspace/code-snippets/01-intro
COPY devcontainer/02-basics /root/workspace/code-snippets/02-basics
COPY devcontainer/03-mm-libc /root/workspace/code-snippets/03-mm-libc
COPY devcontainer/04-building-debugging /root/workspace/code-snippets/04-building-debugging
COPY devcontainer/05-use-cases /root/workspace/code-snippets/05-use-cases
COPY devcontainer/06-security /root/workspace/code-snippets/06-security

# This argument, combined with invoking docker build with -build-arg
# CACHEBUST=$(date +%s), triggers the rebuild of everything that
# follows independently of the cache. Needed as the git repos evolve
ARG CACHEBUST=1

RUN git clone https://github.com/c-programming-essentials/check50.git /tmp/check50
RUN cd /tmp/check50 && pip install . --break-system-packages --root-user-action=ignore

RUN git clone https://github.com/c-programming-essentials/exercises.git /root/workspace/exercises
COPY exercises-solutions /root/workspace/exercise-solutions
RUN cd /root/workspace/exercise-solutions && rm -rf .git

WORKDIR /root/workspace
