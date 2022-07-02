#!/bin/bash
PROJECT_ROOT=$( dirname $(realpath $0) )
cd $PROJECT_ROOT/src/article

protoc Article.proto --cpp_out=./
