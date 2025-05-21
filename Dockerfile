# Use an official C++ development image
FROM ubuntu:22.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV LANG=C.UTF-8

USER root

# Install required packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y sudo && \
    groupadd -r appuser && \
    useradd -m -r -g appuser appuser && \
    echo "appuser ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    rm -rf /var/lib/apt/lists/*

USER appuser

# Set the working directory
WORKDIR /app

# Copy the project files into the container
COPY ./src ./src
COPY ./include ./include
COPY ./CMakeLists.txt ./

#Create a build directory and build the project
RUN mkdir -p build && \
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DIGNORE_GIT_METADATA=ON && \
    cmake --build build --target all

#Set the default command to run the application
CMD ["./build/programming_paradigms"]
